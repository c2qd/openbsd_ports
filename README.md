# openbsd_ports

## WARNING

All ports are provided as-is without warranty and may cause serious damage to your computer.

## Info

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

[The Unlicense](LICENSE)
