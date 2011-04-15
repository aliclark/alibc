
#ifndef __UNISTD
#define __UNISTD

int getopt (int argc, char* const *argv, const char* optstring);
extern char *optarg;
extern int opterr, optind, optopt;

#endif
