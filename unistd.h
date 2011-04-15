
#ifndef __ALIBC_UNISTD_H
#define __ALIBC_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

int getopt (int argc, char* const *argv, const char* optstring);
extern char *optarg;
extern int opterr, optind, optopt;

#ifdef __cplusplus
}
#endif

#endif
