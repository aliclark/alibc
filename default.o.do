
# what about other header files?
redo-ifchange $1.h

redo-ifchange $1.c
gcc -I. -fPIC -g -Wall -Wextra -pedantic -c -o $3 $1.c
