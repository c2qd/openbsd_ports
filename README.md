# openbsd_ports

## WARNING

See the license disclaimer.

## Notes

- None of the ports have been tested on anything other than x86_64.  
- I usually build only with the base-clang compiler, and that there are some ad hoc patches that assume clang (or libc++).  
- The Mozc port is patched without *any consideration* for IBus. Please use fcitx5 instead.  
- The Mozc icons are not built.  
- Fcitx5 has removed the osyncstream-based logging implementation and switched to simple logging instead (see feeecaaa4f32e7a6bd2e059fc7eeee0e837c6e56 for details).
<details>
<summary>develop memo</summary>
generate abseil-cpp so list:
```sh
ls /usr/local/lib/libabsl* | sed 's,^/usr/local/lib/lib,-l,; s/\.so.*//; s/^/        "/; s/$/",/'
```
gen abseil-cpp build.bazel:
in abseil-cpp.x/absl/

</details>

## How to use

Add to `/etc/mk.conf`:
```
PORTSDIR_PATH=<clone destination>:${PORTSDIR}/mystuff:${PORTSDIR}
```

## References

[kdeguchi/mozc-ports: Latest version mozc ports for FreeBSD](https://github.com/kdeguchi/mozc-ports)  
[OpenBSD 7.5でBazelをビルドする #OpenBSD7.0 - Qiita](https://qiita.com/asuka1975/items/c162ef0295dea6cef639)  
[fcitx/fcitx5-macos/patches/osyncstream.patch](https://github.com/fcitx/fcitx5-macos/blob/55148e6e60f48cf1d65aac5a6beba14a43442b43/patches/osyncstream.patch)  
[openbsd/ports/devel/cmake/cmake.port.mk](https://codeberg.org/openbsd/ports/src/branch/master/devel/cmake/cmake.port.mk)  
[openbsd/ports/devel/jdk/java.port.mk](https://codeberg.org/openbsd/ports/src/branch/master/devel/jdk/java.port.mk)  
[https://sources.debian.org/src/mozc/3.33.6133%252Bds1-0.1~exp1](https://sources.debian.org/src/mozc/3.33.6133%252Bds1-0.1~exp1)

## Licenses

The following files are distributed under their original licenses:  
- [devel/bazel/Makefile.inc](devel/bazel/Makefile.inc) is derived from [openbsd/ports/devel/bazel/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/devel/bazel/Makefile)  
- [games/easyrpg-player](games/easyrpg-player) is derived from [openbsd/ports/games/easyrpg](https://codeberg.org/openbsd/ports/src/branch/master/games/easyrpg)  
- [games/liblcf](games/liblcf) is derived from [openbsd/ports/games/liblcf](https://codeberg.org/openbsd/ports/src/branch/master/games/liblcf)  
- [inputmethods/fcitx/Makefile](inputmethods/fcitx/Makefile) is derived from [openbsd/ports/inputmethods/fcitx/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/Makefile)  
- [inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp](inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp) = [openbsd/ports/inputmethods/patches/patch-src_lib_fcitx-utils_misc_cpp](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx/patches/patch-src_lib_fcitx-utils_misc_cpp)  
- [inputmethods/fcitx-config-qt/Makefile](inputmethods/fcitx-config-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-config-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-config-qt/Makefile)  
- [inputmethods/fcitx-gtk/Makefile](inputmethods/fcitx-gtk/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-gtk/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-gtk/Makefile)  
- [inputmethods/fcitx-qt/Makefile](inputmethods/fcitx-qt/Makefile) is derived from [openbsd/ports/inputmethods/fcitx-qt/Makefile](https://codeberg.org/openbsd/ports/src/branch/master/inputmethods/fcitx-qt/Makefile)  
- [inputmethods/mozc/files/third_party/abseil-cpp](inputmethods/mozc/files/third_party/abseil-cpp) is derived from [abseil/abseil-cpp](https://github.com/abseil/abseil-cpp) ([Apache-2.0](https://github.com/abseil/abseil-cpp/blob/master/LICENSE))  
- [inputmethods/mozc/files/third_party/protobuf](inputmethods/mozc/files/third_party/protobuf) is derived from [https://sources.debian.org/src/mozc/3.33.6133%252Bds1-0.1~exp1/debian/third_party/protobuf](https://sources.debian.org/src/mozc/3.33.6133%2Bds1-0.1~exp1/debian/third_party/protobuf) ([BSD-3-Clause](https://sources.debian.org/src/mozc/3.33.6133%2Bds1-0.1~exp1/debian/copyright))  
- [www/yt-dlp](www/yt-dlp) is derived from [openbsd/ports/www/yt-dlp](https://codeberg.org/openbsd/ports/src/branch/master/www/yt-dlp)

Other files are licensed under [The Unlicense](UNLICENSE).

## Contact

DO NOT CONTACT ME IN ANY WAY.
