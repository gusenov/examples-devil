#!/bin/bash

EXE_FILE="./program.out"

DEVIL_INCLUDE="../devil/1.8.0_1/include/"

DEVIL_LIB="../devil/1.8.0_1/relink/"
LIBS="-lIL -lILU -lILUT"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 \
    -I"$DEVIL_INCLUDE" \
    -L"$DEVIL_LIB" $LIBS \
    -ljasper.4 -ljpeg.9 -lpng16.16 -ltiff.5 -llcms2.2 \
    `find . -maxdepth 1 -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" \
 && DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:"$DEVIL_LIB" "$EXE_FILE"
