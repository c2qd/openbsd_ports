abseil-cpp-xxxxxxxx.x/absl
```pl
#!/usr/bin/env perl

use strict;
use warnings;
use File::Path qw(make_path);

my $b_root =
    '/usr/ports/mystuff/inputmethods/mozc/files/third_party/abseil-cpp/absl';

my $out_root = '../absl2';

open my $find, '-|',
    'find', $b_root, '-type', 'f', '-name', 'BUILD.bazel'
    or die "find: $!\n";

while (my $b_file = <$find>) {
    chomp $b_file;

    my $rel = $b_file;
    $rel =~ s/^\Q$b_root\E\/?//;

    my $a_file = "./$rel";
    my $out_file = "$out_root/$rel";

    print "$rel\n";

    unless (-f $a_file) {
        warn "A not found: $a_file\n";
        next;
    }

    process_file($b_file, $a_file, $out_file);
}

close $find or die "find failed\n";

sub process_file {
    my ($b_file, $a_file, $out_file) = @_;

    my %linkopts;

    #
    # Bから name -> linkopts を取得
    #

    open my $b, '<', $b_file
        or die "$b_file: $!\n";

    my $in_cc_library = 0;
    my $name;
    my @current_linkopts;
    my $in_linkopts = 0;

    while (my $line = <$b>) {

        if (!$in_cc_library && $line =~ /^cc_library\s*\(/) {
            $in_cc_library = 1;
            $name = undef;
            @current_linkopts = ();
            $in_linkopts = 0;
            next;
        }

        next unless $in_cc_library;

        #
        # name =
        #

        if (!$in_linkopts &&
            $line =~ /^\s{4}name\s*=\s*(.+?)\s*,?\s*$/) {

            $name = $1;
            next;
        }

        #
        # linkopts =
        #

        if (!$in_linkopts &&
            $line =~ /^\s{4}linkopts\s*=/) {

            $in_linkopts = 1;
            @current_linkopts = ($line);
            next;
        }

        #
        # linkoptsの継続行
        #

        if ($in_linkopts) {

            #
            # cc_library直下の次の属性
            #

            if ($line =~ /^\s{4}[A-Za-z_][A-Za-z0-9_]*\s*=/) {
                $in_linkopts = 0;
                next;
            }

            #
            # cc_library終了
            #

            if ($line =~ /^\s*\)\s*$/) {
                if (defined $name) {
                    $linkopts{$name} = [@current_linkopts];
                }

                $in_cc_library = 0;
                $in_linkopts = 0;
                next;
            }

            push @current_linkopts, $line;
            next;
        }

        #
        # cc_library終了
        #

        if ($line =~ /^\s*\)\s*$/) {
            if (defined $name && @current_linkopts) {
                $linkopts{$name} = [@current_linkopts];
            }

            $in_cc_library = 0;
        }
    }

    close $b;

    #
    # Aを変換
    #

    my $out_dir = $out_file;
    $out_dir =~ s{/[^/]+$}{};

    make_path($out_dir);

    open my $a, '<', $a_file
        or die "$a_file: $!\n";

    open my $out, '>', $out_file
    or die "$out_file: $!\n";

    print {$out} <<'EOF';
load("@rules_cc//cc:defs.bzl", "cc_library")

package(
    default_visibility = ["//visibility:public"],
)

EOF

    $in_cc_library = 0;

    my $in_package_group = 0;
    my $keep = 0;
    $name = undef;

    while (my $line = <$a>) {

        #
        # package_group() はそのまま保持
        #

        if (!$in_cc_library && !$in_package_group &&
            $line =~ /^package_group\s*\(/) {

            $in_package_group = 1;
            print {$out} $line;

            #
            # package_group(...) が1行で完結する場合
            #

            if ($line =~ /^\s*package_group\s*\(.*\)\s*$/) {
                $in_package_group = 0;
            }

            next;
        }

        #
        # package_group() の継続行
        #

        if ($in_package_group) {
            print {$out} $line;

            if ($line =~ /^\s*\)\s*$/) {
                $in_package_group = 0;
            }

            next;
        }

        #
        # cc_library開始
        #

        if (!$in_cc_library && $line =~ /^cc_library\s*\(/) {
            $in_cc_library = 1;
            $keep = 0;
            $name = undef;

            print {$out} $line;
            next;
        }

        #
        # cc_library以外は全部捨てる
        #

        next unless $in_cc_library;

        #
        # name =
        #

        if ($line =~ /^\s{4}name\s*=\s*(.+?)\s*,?\s*$/) {
            $name = $1;

            print {$out} $line;

            #
            # nameの直後にBのlinkoptsを入れる
            #

            if (exists $linkopts{$name}) {
                print {$out} @{$linkopts{$name}};
            }

            $keep = 1;
            next;
        }

        #
        # visibility / deps
        #

        if ($line =~ /^\s{4}(visibility|deps)\s*=/) {
            $keep = 1;
            print {$out} $line;
            next;
        }

        #
        # その他のcc_library直下属性
        #

        if ($line =~ /^\s{4}[A-Za-z_][A-Za-z0-9_]*\s*=/) {
            $keep = 0;
            next;
        }

        #
        # cc_library終了
        #

        if ($line =~ /^\s*\)\s*$/) {
            print {$out} $line;

            $in_cc_library = 0;
            $keep = 0;
            $name = undef;

            next;
        }

        #
        # visibility / deps の継続行
        #

        print {$out} $line if $keep;
    }

    close $a;
    close $out;
}
```
