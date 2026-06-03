# openbsd_ports

## WARNING

All ports are provided as-is without warranty and may cause serious damage to your computer.  
Also, for convenience, there may be ports that establish network connections during the build process; however, please understand that there is not enough motivation to thoroughly eliminate all network access during builds.

## Info

I have no intention of submitting this upstream. All of the ports are rather roughly made, after all.  
Not a fan of the network access during builds? Think the Makefiles are way too sloppy? Believe this should be contributed upstream?  
Feel free to fork it. It's under The Unlicense after all, so go ahead, take it over as if it were yours, hack on it, and send it to ports@ if you want.  
That's about how little motivation I have to do any of that myself.<br><br>

None of the ports have been tested on anything other than x86_64.

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

## Nonsense

Taking various points into account, it might be more accurate to say that the Mozc-related parts are not really *ports* at all, but simply automated build processes.  
If I think back to the dystopian build process I went through before, the fact that this only requires a simple make command already feels somewhat better.  
...The effort required to escape that dystopia was significant. I wonder if it was really worth doing at all.<br><br>
I am not refusing all reports. Typos and patch suggestions, and so on.  
If you feel like it, feel free to submit them to the issues.  
Pull requests are disabled, though.  
However, as mentioned earlier, my motivation is low, so I cannot guarantee that I will respond to or even acknowledge them...

## License

[The Unlicense](UNLICENSE)
