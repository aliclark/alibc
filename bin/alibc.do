
DEPS="ctype.o stdlib.o string.o unistd.o"

if [ "$CC" = "" ]; then
  CC=clang
fi

redo-ifchange $DEPS

$CC -nostdlib -nodefaultlibs -shared -Wl,-soname,libalibc.so.1 -o libalibc.so.1 $DEPS
