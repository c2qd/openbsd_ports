# openbsd_ports

## WARNING

See the license disclaimer.

## Notes

- None of the ports have been tested on anything other than x86_64.  
- I usually build only with the base-clang compiler, and that there are some ad hoc patches that assume clang (or libc++).  
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
- [devel/bazel/Makefile.inc](devel/bazel/Makefile.inc) is derived from [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  
- [devel/bazel/patches/patch-src_main_java_com_google_devtools_build_lib_analysis_constraints_ConstraintConstants_java](devel/bazel/patches/patch-src_main_java_com_google_devtools_build_lib_analysis_constraints_ConstraintConstants_java) and [devel/bazel/patches/patch-src_main_java_com_google_devtools_build_lib_analysis_ShToolchain_java](devel/bazel/patches/patch-src_main_java_com_google_devtools_build_lib_analysis_ShToolchain_java) is derived from [Fix default --shell_executable on openbsd (bazelbuild/bazel@2b184b8)](https://github.com/bazelbuild/bazel/commit/2b184b8089d3ee10b1a784299563d2d7baf922c3)  
- [games/easyrpg-player](games/easyrpg-player) is derived from [openbsd/ports/games/easyrpg](https://codeberg.org/openbsd/ports/src/branch/master/games/easyrpg)  
- [games/liblcf](games/liblcf) is derived from [openbsd/ports/games/liblcf](https://codeberg.org/openbsd/ports/src/branch/master/games/liblcf)  
- [inputmethods/fcitx/Makefile](inputmethods/fcitx/Makefile) is derived from [openbsd/ports/inputmethods/fcitx/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/Makefile)  
- [inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) = [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [inputmethods/fcitx-config-qt/Makefile](inputmethods/fcitx-config-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-config-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-config-qt/Makefile)  
- [inputmethods/fcitx-gtk/Makefile](inputmethods/fcitx-gtk/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-gtk/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-gtk/Makefile)  
- [inputmethods/fcitx-qt/Makefile](inputmethods/fcitx-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-qt/Makefile)  
- [net/gajim](net/gajim) is derived from [openbsd/ports/net/gajim](https://codeberg.org/openbsd/ports/src/branch/master/net/gajim)  
- [net/py-nbxmpp](net/py-nbxmpp) is derived from [openbsd/ports/www/yt-dlp](https://codeberg.org/openbsd/ports/src/branch/master/net/py-nbxmpp)  
- [www/yt-dlp](www/yt-dlp) is derived from [openbsd/ports/www/yt-dlp](https://codeberg.org/openbsd/ports/src/branch/master/www/yt-dlp)

Other files are licensed under [The Unlicense](UNLICENSE).

## Contact

DO NOT CONTACT ME IN ANY WAY.
