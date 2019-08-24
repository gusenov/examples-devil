#!/bin/bash

EXE_FILE="./program.out"


DEVIL_INCLUDE="../devil/1.8.0_1/include/"

# DEVIL_LIB="../devil/1.8.0_1/lib/"
DEVIL_LIB="../devil/1.8.0_1/relink/"
LIBS="-lIL -lILU -lILUT"

# ilGetInteger(IL_VERSION_NUM) < IL_VERSION
# 180 < 180
# IL_VERSION_NUM = 180
# IL_VERSION = 180
#
# iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION
# 180 < 180
# ILU_VERSION_NUM = 180
# ILU_VERSION = 180
#
# ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION
# 180 < 180
# ILUT_VERSION_NUM = 3554
# ILUT_VERSION = 180


# DEVIL_LIB="../devil/unknown/lib/"
# LIBS="-lIL -lILU"

# ilGetInteger(IL_VERSION_NUM) < IL_VERSION
# 180 < 180
# IL_VERSION_NUM = 180
# IL_VERSION = 180
#
# iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION
# 178 < 180
# ILU_VERSION_NUM = 180
# ILU_VERSION = 180
#
# Incorrect ilu.dll version


[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

# libIL.dylib
# libILU.dylib
# libILUT.dylib

# libjasper.4.dylib
# libjpeg.9.dylib
# liblcms2.2.dylib
# libpng16.16.dylib
# libtiff.5.dylib

# -ljasper -ljpeg -lpng -ltiff -llcms2

clang++ --std=c++17 \
    -I"$DEVIL_INCLUDE" \
    -L"$DEVIL_LIB" $LIBS \
    -ljasper.4 -ljpeg.9 -lpng16.16 -ltiff.5 -llcms2.2 \
    `find . -maxdepth 1 -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" \
 && DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:"$DEVIL_LIB" "$EXE_FILE"

# С опцией -v:

    # Apple LLVM version 10.0.1 (clang-1001.0.46.4)
    # Target: x86_64-apple-darwin18.5.0
    # Thread model: posix
    # InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
    #  "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
    #      -cc1
    #      -triple x86_64-apple-macosx10.14.0
    #      -Wdeprecated-objc-isa-usage
    #      -Werror=deprecated-objc-isa-usage
    #      -emit-obj
    #      -mrelax-all
    #      -disable-free
    #      -disable-llvm-verifier
    #      -discard-value-names
    #      -main-file-name main.cpp
    #      -mrelocation-model pic
    #      -pic-level 2
    #      -mthread-model posix
    #      -mdisable-fp-elim
    #      -fno-strict-return
    #      -masm-verbose
    #      -munwind-tables
    #      -target-sdk-version=10.14
    #      -target-cpu penryn
    #      -dwarf-column-info
    #      -debugger-tuning=lldb
    #      -target-linker-version 450.3
    #      -v
    #      -resource-dir /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.1
    #      -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk
    #      -I/usr/local/include
    #      -stdlib=libc++
    #      -Wno-atomic-implicit-seq-cst
    #      -Wno-framework-include-private-from-public
    #      -Wno-atimport-in-framework-header
    #      -Wno-quoted-include-in-framework-header
    #      --std=c++17
    #      -fdeprecated-macro
    #      -fdebug-compilation-dir /Users/YOU_USER/YOUR_REPO
    #      -ferror-limit 19
    #      -fmessage-length 179
    #      -stack-protector 1
    #      -fblocks
    #      -fencode-extended-block-signature
    #      -fregister-global-dtors-with-atexit
    #      -fobjc-runtime=macosx-10.14.0
    #      -fcxx-exceptions
    #      -fexceptions
    #      -fmax-type-align=16
    #      -fdiagnostics-show-option
    #      -fcolor-diagnostics
    #      -o /var/folders/bf/hl0zd5p1415cjtdykb_xkg4r0000gn/T/main-ea4494.o
    #      -x c++
    #      ./main.cpp
    # clang -cc1 version 10.0.1 (clang-1001.0.46.4) default target x86_64-apple-darwin18.5.0
    # ignoring nonexistent directory "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include/c++/v1"
    # ignoring nonexistent directory "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/local/include"
    # ignoring nonexistent directory "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/Library/Frameworks"
    # #include "..." search starts here:
    # #include <...> search starts here:
    #  /usr/local/include
    #  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1
    #  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.1/include
    #  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
    #  /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include
    #  /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks (framework directory)
    # End of search list.
    #  "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld"
    #      -demangle
    #      -lto_library /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/libLTO.dylib
    #      -no_deduplicate
    #      -dynamic
    #      -arch x86_64
    #      -macosx_version_min 10.14.0
    #      -syslibroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk
    #      -o ./program.out
    #      -lIL
    #      -lILU
    #      -lILUT
    #      /var/folders/bf/hl0zd5p1415cjtdykb_xkg4r0000gn/T/main-ea4494.o
    #      -L/usr/local/lib
    #      -lc++
    #      -lSystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.1/lib/darwin/libclang_rt.osx.a
