# openbsd_ports

## WARNING

See the license disclaimer.

## Notes

- None of the ports have been tested on anything other than x86_64.  
- I usually build only with the base-clang compiler, and that there are some ad hoc patches that assume clang (or libc++).  
- The Mozc port is patched without *any consideration* for IBus. Please use fcitx5 instead.  
- The Mozc icons are not built.  
- Fcitx5 has removed the osyncstream-based logging implementation and switched to simple logging instead (see feeecaaa4f32e7a6bd2e059fc7eeee0e837c6e56 for details).

## How to use

Add to `/etc/mk.conf`:
```
PORTSDIR_PATH=<clone destination>:${PORTSDIR}/mystuff:${PORTSDIR}
```

## References

[kdeguchi/mozc-ports: Latest version mozc ports for FreeBSD](https://github.com/kdeguchi/mozc-ports)  
[OpenBSD 7.5でBazelをビルドする #OpenBSD7.0 - Qiita](https://qiita.com/asuka1975/items/c162ef0295dea6cef639)  
[fcitx/fcitx5-macos/patches/osyncstream.patch](https://github.com/fcitx/fcitx5-macos/blob/55148e6e60f48cf1d65aac5a6beba14a43442b43/patches/osyncstream.patch)

## Licenses

The following files are distributed under their original licenses:  
- [enolink.patch](japanese/mozc/files/enolink.patch) = [openbsd/ports/devel/abseil-cpp/patches/patch-absl_status_status_cc](https://codeberg.org/openbsd/ports/src/branch/master/devel/abseil-cpp/patches/patch-absl_status_status_cc)  
- [inputmethods/fcitx/Makefile](inputmethods/fcitx/Makefile) is derived from [openbsd/ports/inputmethods/fcitx/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/Makefile)  
- [inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) = [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [inputmethods/fcitx-config-qt/Makefile](inputmethods/fcitx-config-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-config-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-config-qt/Makefile)  
- [inputmethods/fcitx-gtk/Makefile](inputmethods/fcitx-gtk/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-gtk/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-gtk/Makefile)  
- [inputmethods/fcitx-qt/Makefile](inputmethods/fcitx-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-qt/Makefile)  
- [devel/bazel/Makefile.inc](devel/bazel/Makefile.inc) is derived from [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  
- [www/yt-dlp](www/yt-dlp) is derived from [openbsd/ports/www/yt-dlp](https://codeberg.org/openbsd/ports/src/branch/master/www/yt-dlp)

Other files are licensed under [The Unlicense](UNLICENSE).

## Contact

DO NOT CONTACT ME IN ANY WAY.
