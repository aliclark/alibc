
#ifndef __ALIBC_ERRNO_H
#define __ALIBC_ERRNO_H

#define EDOM   1
#define ERANGE 2

extern int errno;

// <a name="errno">errno</a>
/* object to which <strong>certain</strong> library functions assign specific positive values on error */
// <a name="EDOM">EDOM</a>
/* code used for domain errors */
// <a name="ERANGE">ERANGE</a>
/* code used for range errors */

/* Notes: */
/* <ul>
<li>other implementation-defined error values are permitted</li>
<li>to determine the value (if any) assigned to <a href="#errno">errno</a> by a library function, a program should assign zero to <a href="#errno">errno</a> immediately prior to the function call</li>
</ul> */


#endif
