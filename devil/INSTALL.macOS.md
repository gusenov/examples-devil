## Установка на macOS

```
$ brew install devil
$ brew info devil
devil: stable 1.8.0 (bottled), HEAD
Cross-platform image library
https://sourceforge.net/projects/openil/
/usr/local/Cellar/devil/1.8.0_1 (13 files, 510.8KB) *
  Poured from bottle on 2019-07-16 at 16:33:26
From: https://github.com/Homebrew/homebrew-core/blob/master/Formula/devil.rb
==> Dependencies
Build: cmake ✔
Required: jasper ✔, jpeg ✔, libpng ✔, libtiff ✔, little-cms2 ✔

$ ls /usr/local/Cellar/devil/1.8.0_1
INSTALL_RECEIPT.json	LICENSE			README.md		include			lib


$ ls /usr/local/Cellar/devil/1.8.0_1/include/IL/
il.h	ilu.h	ilut.h

$ ls -l /usr/local/include/IL*
lrwxr-xr-x  /usr/local/include/IL -> ../Cellar/devil/1.8.0_1/include/IL


$ ls /usr/local/Cellar/devil/1.8.0_1/lib/
libIL.dylib	libILU.dylib	libILUT.dylib	pkgconfig

$ ls /usr/local/lib/libIL*.dylib
lrwxr-xr-x  /usr/local/lib/libIL.dylib -> ../Cellar/devil/1.8.0_1/lib/libIL.dylib
lrwxr-xr-x  /usr/local/lib/libILU.dylib -> ../Cellar/devil/1.8.0_1/lib/libILU.dylib
lrwxr-xr-x  /usr/local/lib/libILUT.dylib -> ../Cellar/devil/1.8.0_1/lib/libILUT.dylib
```

## Удаление на macOS

```
$ brew remove devil

$ brew remove little-cms2
$ brew remove libtiff
$ brew remove libpng
$ brew remove jpeg
$ brew remove jasper
```

