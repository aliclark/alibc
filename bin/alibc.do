
DEPS="ctype.o errno.o stdlib.o string.o unistd.o"
redo-ifchange $DEPS
clang -nostdlib -nodefaultlibs -shared -Wl,-soname,libalibc.so.1 -o libalibc.so.1 $DEPS
