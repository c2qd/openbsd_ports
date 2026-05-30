# openbsd_ports

## WARNING

All ports are provided as-is without warranty and may cause serious damage to your computer.  
Also, for convenience, there may be ports that establish network connections during the build process; however, please understand that there is not enough motivation to thoroughly eliminate all network access during builds.

## Info

I have no intention of submitting this upstream. All of the ports are rather roughly made, after all.  
The Mozc port is for x86_64 only (I do not own any machines other than x86_64, so I cannot test it).

## How to use

```sh
git clone https://codeberg.org/c2qd/openbsd_ports.git c2qd_ports
# or
git clone git@codeberg.org:c2qd/openbsd_ports.git c2qd_ports
```

`/etc/mk.conf`:
```
PORTSDIR_PATH=/path/to/c2qd_ports:${PORTSDIR}:${PORTSDIR}/mystuff
```

## License

[The Unlicense](UNLICENSE)
