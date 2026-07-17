# openbsd_ports

"unstable."

## WARNING

All ports are provided as-is without warranty and may cause serious damage to your computer.  
Also, for convenience, there may be ports that establish network connections during the build process; however, please understand that there is not enough motivation to thoroughly eliminate all network access during builds.

## Info

None of the ports have been tested on anything other than x86_64.  
Before building Fcitx5, please run the following command. This workaround would not be necessary if the fix proposed at ['devel/llvm: fix clang linking with -fexperimental-library' - MARC](https://marc.info/?l=openbsd-ports&m=178196468149108) were accepted, but unfortunately I have not received any response...
```sh
doas ln -s /usr/local/llvm22/lib/libec++experimental.a /usr/local/llvm22/lib/libc++experimental.a
```

## How to use

```sh
git clone https://codeberg.org/c2qd/openbsd_ports.git c2qd_ports
```

`/etc/mk.conf`:
```
PORTSDIR_PATH=/path/to/c2qd_ports:${PORTSDIR}:${PORTSDIR}/mystuff
```

## Credit

ref?  
[kdeguchi/mozc-ports: Latest version mozc ports for FreeBSD](https://github.com/kdeguchi/mozc-ports)  
[OpenBSD 7.5でBazelをビルドする #OpenBSD7.0 - Qiita](https://qiita.com/asuka1975/items/c162ef0295dea6cef639)  

## License

The following files are distributed under their original licenses.  
- [enolink.patch](japanese/mozc/files/enolink.patch) is from [openbsd/ports/devel/abseil-cpp/patches/patch-absl_status_status_cc](https://codeberg.org/openbsd/ports/src/branch/master/devel/abseil-cpp/patches/patch-absl_status_status_cc)  
- [inputmethods/fcitx*/Makefile](inputmethods) is from [openbsd/ports/inputmethods/fcitx*/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods)  
- [patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) is from [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [devel/bazel/Makefile.inc](devel/bazel/Makefile.inc) is from [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  

[The Unlicense](UNLICENSE)
