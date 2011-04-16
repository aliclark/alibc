
# what about other header files?
redo-ifchange ../include/$1.h

redo-ifchange ../src/$1.c
gcc -I../include -fPIC -g -Wall -Wextra -pedantic -c -o $3 ../src/$1.c
