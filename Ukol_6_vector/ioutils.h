/**
 * \file    ioutils.h
 * \author  Tomáš Dulík
 * \date    16.2.2012
 * \brief   Miniknihovna pro načítání vstupu
 */

#ifndef _IOUTILS_H_
#define _IOUTILS_H_

#include <stdbool.h>
#include <inttypes.h>

char io_utils_get_char_line();
bool io_utils_get_string( char * line, int len );
bool io_utils_get_long( long * val );
bool io_utils_get_double( double * val );
void io_utils_clear_stdin();
bool io_utils_get_uint64_t(uint64_t *val);


#endif //_IOUTILS_H_
