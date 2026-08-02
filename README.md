# openbsd_ports

## WARNING

All ports are provided as-is without warranty and may cause serious damage to your computer.  
Also, for convenience, there may be ports that establish network connections during the build process; however, please understand that there is not enough motivation to thoroughly eliminate all network access during builds.

## Notes

- None of the ports have been tested on anything other than x86_64.  
- I usually build only with the base-clang compiler (ports-clang for inputmethods/fcitx), and that there are some ad hoc patches that assume clang (or libc++).  
- The Mozc port is patched without *any consideration* for IBus. Please use fcitx5 instead.  
- The Mozc icons are not built, as I use dwm (and occasionally dwl), and building them would make the DISTFILES handling more complicated.  
- Before building Fcitx5, please run the following command. This workaround would not be necessary if the fix proposed at ['devel/llvm: fix clang linking with -fexperimental-library' - MARC](https://marc.info/?l=openbsd-ports&m=178196468149108) were accepted, but I have not received any response.
- ```sh
  doas ln -s /usr/local/llvm22/lib/libec++experimental.a /usr/local/llvm22/lib/libc++experimental.a
  ```

## How to use

example
```sh
cd /usr/ports
git clone https://codeberg.org/c2qd/openbsd_ports.git c2qd_ports
doas sh -c 'echo "PORTSDIR_PATH=\${PORTSDIR}/c2qd_ports:\${PORTSDIR}/mystuff:\${PORTSDIR}" >> /etc/mk.conf'
```

## Credits

References  
[kdeguchi/mozc-ports: Latest version mozc ports for FreeBSD](https://github.com/kdeguchi/mozc-ports)  
[OpenBSD 7.5でBazelをビルドする #OpenBSD7.0 - Qiita](https://qiita.com/asuka1975/items/c162ef0295dea6cef639)  

## Licenses

The following files are distributed under their original licenses.  
- [enolink.patch](japanese/mozc/files/enolink.patch) = [openbsd/ports/devel/abseil-cpp/patches/patch-absl_status_status_cc](https://codeberg.org/openbsd/ports/src/branch/master/devel/abseil-cpp/patches/patch-absl_status_status_cc)  
- [inputmethods/fcitx/Makefile](inputmethods/fcitx/Makefile) ≒ [openbsd/ports/inputmethods/fcitx/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/Makefile)  
- [inputmethods/fcitx-config-qt/Makefile](inputmethods/fcitx-config-qt/Makefile) ≒ [openbsd/ports/inputmethods/fcitx-config-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-config-qt/Makefile)  
- [inputmethods/fcitx-gtk/Makefile](inputmethods/fcitx-gtk/Makefile) ≒ [openbsd/ports/inputmethods/fcitx-gtk/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-gtk/Makefile)  
- [inputmethods/fcitx-qt/Makefile](inputmethods/fcitx-qt/Makefile) ≒ [openbsd/ports/inputmethods/fcitx-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-qt/Makefile)  
- [patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) = [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [devel/bazel/Makefile.inc](devel/bazel/Makefile.inc) ≒ [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  

Other files are licensed under [The Unlicense](UNLICENSE)

## Contact

Do NOT contact me in any way.
