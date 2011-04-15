
#include <assert.h>
#include <stdio.h>

#include "string.h"
#include "unistd.h"

char *optarg = NULL;
int opterr = 0, optind = 1, optopt = 0;

/* index into the arg where we left off */
static size_t __optwithin       = 0;
static char*  __optfailillegal  = "%s: illegal option -- %c\n";
static char*  __optfailargument = "%s: option requires an argument -- %c\n";

/*
 * huh?:
 * When an element of argv[] contains multiple option characters, it
 * is unspecified how getopt() determines which options have already
 * been processed.
 */
int getopt (int argc, char* const *argv, const char* optstring)
{
    char* curg;
    char* curc;
    int rvc;

    assert(argc      >= 1);
    assert(argv      != NULL);
    assert(optstring != NULL);

    optarg = NULL;
    opterr = 0;
    optopt = 0;

    curg = argv[optind];

    if (__optwithin == 0)
    {
        if ((curg == NULL) || (curg[0] != '-') || (curg[1] == '\0'))
        {
            /* NULL / text / - */
            return -1;
        }

        if (strcmp(curg, "--") == 0)
        {
            ++optind;
            return -1;
        }

        __optwithin = 1;
    }

    curg += __optwithin;

    rvc = curg[0];

    curc = strchr(optstring, rvc);

    if (curc == NULL)
    {
        opterr = 1;
        optopt = rvc;
        rvc = '?';
        ++optind;
    }
    else
    {
        if (curc[1] == ':')
        {
            if (curg[1] == '\0')
            {
                if (optind + 1 >= argc)
                {
                    /* -o */
                    opterr = 2;
                    optopt = rvc;
                    rvc = (optstring[0] == ':') ? ':' : '?';
                    ++optind;
                }
                else
                {
                    /* -o filename */
                    optarg = argv[optind + 1];
                    optind += 2;
                }
            }
            else
            {
                /* -ofilename */
                optarg = curg + 1;
                ++optind;
            }

            __optwithin = 0;
        }
        else
        {
            if (curg[1] == '\0')
            {
                /* -a */
                __optwithin = 0;
                ++optind;
            }
            else
            {
                /* -ao */
                ++__optwithin;
            }
        }
    }

    if ((opterr != 0) && (optstring[0] != ':'))
    {
        fprintf(stderr, (curc == NULL) ? __optfailillegal : __optfailargument, argv[0], optopt);
    }

    return rvc;
}
