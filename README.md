# openbsd_ports

## WARNING

All ports are provided as-is without warranty and may cause serious damage to your computer.  
Also, for convenience, there may be ports that establish network connections during the build process; however, please understand that there is not enough motivation to thoroughly eliminate all network access during builds.

## Info

None of the ports have been tested on anything other than x86_64.

## What
devel  
- bazel  
  - v8  
  - v9  

inputmethods  
- fcitx*(newer than official ports)  

japanese  
- mozc  
  - fcitx-mozc  
  - mozc  

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

I have no intention of submitting this upstream. All of the ports are rather roughly made, after all.  
Not a fan of the network access during builds? Think the Makefiles are way too sloppy? Believe this should be contributed upstream?  
Feel free to fork it. It's under The Unlicense after all, so go ahead, take it over as if it were yours, hack on it, and send it to ports@ if you want.  
That's about how little motivation I have to do any of that myself.<br><br>

~~Taking various points into account, it might be more accurate to say that the Mozc-related parts are not really *ports* at all, but simply automated build processes.~~  
~~If I think back to the dystopian build process I went through before, the fact that this only requires a simple make command already feels somewhat better.~~<br><br>

I don't "strictly" prohibit network access, but I do try to keep it to a minimum as much as possible.  
I just don't have the energy to verify whether there is absolutely zero network access, which is why I say I don't "strictly" prohibit it.<br><br>

Because there are complicated circumstances in the IPC of the mozc port, if you are considering forking it to make improvements, or if you are simply interested, please refer to the upper part of the file [japanese/mozc/patches/patch-src_ipc_unix_ipc_cc](japanese/mozc/patches/patch-src_ipc_unix_ipc_cc).

## Credit

ref:  
[kdeguchi/mozc-ports: Latest version mozc ports for FreeBSD](https://github.com/kdeguchi/mozc-ports)  
[OpenBSD 7.5でBazelをビルドする #OpenBSD7.0 - Qiita](https://qiita.com/asuka1975/items/c162ef0295dea6cef639)  
`man bsd.port.mk`  
and many documents~

## License

The following files are distributed under their original licenses.  
- [enolink.patch](japanese/mozc/files/enolink.patch) is from [openbsd/ports/devel/abseil-cpp/patches/patch-absl_status_status_cc](https://codeberg.org/openbsd/ports/src/branch/master/devel/abseil-cpp/patches/patch-absl_status_status_cc)  
- [inputmethods/fcitx*/Makefile](inputmethods) is from [openbsd/ports/inputmethods/fcitx*/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods)  
- [patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) is from [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [devel/bazel/Makefile.inc] is from [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  

[The Unlicense](UNLICENSE)
