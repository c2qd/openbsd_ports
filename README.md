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
If the content is not critical in nature, please feel free to post bug reports, improvement requests, etc., to the issue tracker.  
Please understand that there is no guarantee of a response.  
Hey, hey, are you going to tell me that I just said "feel free to fork it if you don't like it"? Yes, I did.  
Well, the intention behind that is, if you don't like my style—in other words, if you have complaints like "you're not strictly prohibiting network access," "the Makefile is too sloppy or doesn't follow best practices," or "the patches are haphazard"—then please feel free to fork it. It might be a roundabout way of saying it, though.  
Oh, and by the way, I don't "strictly" prohibit network access, but I do try to keep it to a minimum as much as possible.  
I just don't have the energy to verify whether there is absolutely zero network access, which is why I say I don't "strictly" prohibit it.

## License

[The Unlicense](UNLICENSE)
