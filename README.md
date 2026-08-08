# openbsd_ports

## WARNING

See the license disclaimer.

## Notes

- None of the ports have been tested on anything other than x86_64.  
- I usually build only with the base-clang compiler (ports-clang for inputmethods/fcitx), and that there are some ad hoc patches that assume clang (or libc++).  
- The Mozc port is patched without *any consideration* for IBus. Please use fcitx5 instead.  
- The Mozc icons are not built.  
- Before building Fcitx5, please run the following command. Related: ['devel/llvm: fix clang linking with -fexperimental-library' - MARC](https://marc.info/?l=openbsd-ports&m=178196468149108)
- ```sh
  doas ln -s /usr/local/llvm22/lib/libec++experimental.a /usr/local/llvm22/lib/libc++experimental.a
  ```

## How to use

Add to `/etc/mk.conf`:
```
PORTSDIR_PATH=<clone destination>:${PORTSDIR}/mystuff:${PORTSDIR}
```

## References

[kdeguchi/mozc-ports: Latest version mozc ports for FreeBSD](https://github.com/kdeguchi/mozc-ports)  
[OpenBSD 7.5でBazelをビルドする #OpenBSD7.0 - Qiita](https://qiita.com/asuka1975/items/c162ef0295dea6cef639)  

## Licenses

The following files are distributed under their original licenses:  
- [enolink.patch](japanese/mozc/files/enolink.patch) = [openbsd/ports/devel/abseil-cpp/patches/patch-absl_status_status_cc](https://codeberg.org/openbsd/ports/src/branch/master/devel/abseil-cpp/patches/patch-absl_status_status_cc)  
- [inputmethods/fcitx/Makefile](inputmethods/fcitx/Makefile) is derived from [openbsd/ports/inputmethods/fcitx/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/Makefile)  
- [inputmethods/fcitx-config-qt/Makefile](inputmethods/fcitx-config-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-config-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-config-qt/Makefile)  
- [inputmethods/fcitx-gtk/Makefile](inputmethods/fcitx-gtk/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-gtk/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-gtk/Makefile)  
- [inputmethods/fcitx-qt/Makefile](inputmethods/fcitx-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-qt/Makefile)  
- [patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) = [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [devel/bazel/Makefile.inc](devel/bazel/Makefile.inc) is derived from [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  

Other files are licensed under [The Unlicense](UNLICENSE).

## Contact

DO NOT CONTACT ME IN ANY WAY.
