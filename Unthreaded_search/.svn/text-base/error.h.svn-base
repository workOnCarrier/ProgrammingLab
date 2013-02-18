
#ifndef __ERRORS_H__
#define __ERRORS_H__

#ifndef WIN32
#include <unistd.h>
#endif // WIN32
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#if defined _DEBUG 
#define DPRINTF(arg) printf arg
#else
#define DPRINTF(arg) 
#endif 

#ifndef WIN32
#define err_abort(code,text) do {\
	fprintf ( stderr, "%s at \"%s\":%d: %sn", \
	text, __FILE__, __LINE__, strerror (code)); \
	abort(); \
	} while (0)

#define errno_abort(text) do { \
	fprintf ( stderr, "%s at \"%s\":%d: %s \n", \
	text, __FILE__, __LINE__, strerror (errno)); \
	abort(); \
	} while (0)

#else

#define err_abort(code,text) do {\
	fprintf ( stderr, "%s at \"%s\":%d: %sn", \
	text, __FILE__, __LINE__, strerror (code)); \
	abort(); \
	} while (0)

#define errno_abort(text) do { \
	fprintf ( stderr, "%s at \"%s\":%d: %s \n", \
	text, __FILE__, __LINE__, strerror (errno)); \
	abort(); \
	} while (0)
#endif // WIN32

namespace custom{
class runtime_error
{
	std::string info;
public:
	runtime_error ( std::string error ):info ( error ) {}
	std::string	what ( ) { return info; }
};
}

#endif // __ERRORS_H__

