#!/usr/bin/env perl
use strict;
use warnings;
use utf8;
use open qw(:std :encoding(UTF-8));

use Unicode::Normalize qw(NFKC);
use IO::Uncompress::Bunzip2 qw($Bunzip2Error);
use HTML::Entities qw(decode_entities);

my $srcroot = '.';
my $dict_dir = "$srcroot/src/data/dictionary_oss";
my $id_file  = "$dict_dir/id.def";

my $jawiki_version = shift @ARGV
    or die "usage: $0 <jawiki-version>\n";
my $jawiki_file = "./jawiki-${jawiki_version}-pages-articles-multistream-index.txt.bz2";

my $out_file = "mozcdic-ut.txt";

if (-f $out_file) {
    my $size = -s $out_file;

    if ($size > 1_000_000) {
        print STDERR "skip: cached $out_file ($size bytes)\n";
        exit 0;
    }
}

my $needs_nfkc = qr/\P{NFKC_Quick_Check=Yes}/;

my $id_mozc = load_general_noun_id($id_file);
my %mozc_key = load_mozc_keys($dict_dir);

my %jawiki_hit_dict = generate_jawiki_hit_dict($jawiki_file);

my @ut_entry;
for my $file (glob("./mozcdic-ut-*.txt")) {
    push @ut_entry, load_ut_entries($file, \%mozc_key);
}

@ut_entry = apply_jawiki_hit(\@ut_entry, \%jawiki_hit_dict);

@ut_entry = sort {
    $a->[0] cmp $b->[0]
        || $a->[4] cmp $b->[4]
        || $a->[3] <=> $b->[3]
} @ut_entry;

open my $out, '>:encoding(UTF-8)', $out_file
    or die "cannot open output file: $!\n";

for my $e (@ut_entry) {
    my ($yomi, undef, undef, $cost, $hyouki) = @$e;
    print $out join("\t", $yomi, $id_mozc, $id_mozc, $cost, $hyouki), "\n";
}

sub load_general_noun_id {
    my ($path) = @_;
    open my $fh, '<:encoding(UTF-8)', $path or die $!;
    while (my $line = <$fh>) {
        next if $line =~ /^\s*#/;
        if ($line =~ /^(\S+)\s+名詞,一般,/) {
            return $1;
        }
    }
    die "id not found";
}

sub load_mozc_keys {
    my ($dir) = @_;
    my %key;

    for my $file (sort glob("$dir/dictionary0*")) {
        open my $fh, '<:encoding(UTF-8)', $file or die $!;

        while (my $line = <$fh>) {
            chomp $line;
            next if $line =~ /^\s*$/;
            next if $line =~ /^\s*#/;

            my ($yomi, undef, undef, undef, $hyouki) = split /\t/, $line, 5;
            next unless defined $hyouki;

            my $len = length($hyouki);
            next if $len < 2 || $len > 25;

            if (index($hyouki, '~') >= 0 || $hyouki =~ $needs_nfkc) {
                $hyouki = normalize_entry($hyouki);
            }
            $key{$yomi . "\0" . $hyouki} = 1;
        }
    }

    return %key;
}

sub load_ut_entries {
    my ($file, $seen) = @_;
    my @out;

    open my $fh, '<:encoding(UTF-8)', $file or die $!;

    while (my $line = <$fh>) {
        next if $line =~ /^\s*$/;
        next if $line =~ /^\s*#/;

        my ($yomi, undef, undef, $cost, $hyouki) = split /\t/, $line, 5;
        next unless defined $hyouki;

        chomp $hyouki;

        my $len = length($hyouki);
        next if $len < 2 || $len > 25;

        if (index($hyouki, '~') >= 0 || $hyouki =~ $needs_nfkc) {
            $hyouki = normalize_entry($hyouki);
        }

        my $key = $yomi . "\0" . $hyouki;
        next if $seen->{$key}++;

        push @out, [$yomi, 'id_ut', 'id_ut', $cost, $hyouki];
    }

    return @out;
}

sub generate_jawiki_hit_dict {
    my ($file) = @_;
    my %seen;

    my $z = IO::Uncompress::Bunzip2->new($file)
        or die $Bunzip2Error;

    while (my $line = <$z>) {
        chomp $line;

        my $p1 = index($line, ':');
        my $p2 = index($line, ':', $p1 + 1);
        next if $p1 < 0 || $p2 < 0;

        my $entry = substr($line, $p2 + 1);

        if (index($entry, '&') >= 0) {
            $entry = decode_entities($entry);
        }

        my $pos = rindex($entry, " (");
        if ($pos >= 0) {
            $entry = substr($entry, $pos + 2);
        }

        my $len = length($entry);
        next if $len < 2 || $len > 25;

        next if $entry =~ /^(ファイル:|Wikipedia:|Template:|Portal:|Help:|Category:|プロジェクト:|曖昧さ回避)/;

        if (index($entry, '~') >= 0 || $entry =~ $needs_nfkc) {
            $entry = normalize_entry($entry);
        }
        $seen{$entry} = 1;
    }

    my @list = sort keys %seen;
    my %hit;

    for (my $i = 0; $i < @list; $i++) {
        my $base = $list[$i];
        my $c = 1;

        while ($i + $c < @list && $c < 30 && index($list[$i + $c], $base) == 0) {
            $c++;
        }

        $hit{$base} = $c;
    }

    return %hit;
}

sub apply_jawiki_hit {
    my ($entries, $hit) = @_;
    my @out;

    for my $e (@$entries) {
        my ($yomi, $id1, $id2, $cost, $hyouki) = @$e;

        my $h = $hit->{$hyouki} // 0;
        $h = 30 if $h > 30;

        if ($hyouki =~ /^[\x00-\x7F]+$/) {
            next if $h == 0;
            $cost = 9000 + int($cost / 20);
        } else {
            if ($h == 0) {
                $cost = 9000 + int($cost / 20);
            } elsif ($h == 1) {
                $cost = 8000 + int($cost / 20);
            } else {
                $cost = 8000 - ($h * 10);
            }
        }

        push @out, [$yomi, $id1, $id2, $cost, $hyouki];
    }

    return @out;
}

my %norm_cache;

sub normalize_entry {
    my ($s) = @_;
    my $orig = $s;

    return $norm_cache{$orig} if exists $norm_cache{$orig};

    $s = NFKC($s);

    if (index($s, '~') >= 0) {
        $s =~ tr/~/\x{301C}/;
    }

    return $norm_cache{$orig} = $s;
}
