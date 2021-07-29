/*
 * data.c
 *
 *  Created on: 9. 3. 2015
 *      Author: dulik
 */

#include <stdio.h>
#include <string.h>
#include "data.h"
#include "ioutils.h"


/***************************************************/
bool Data_Get( Data_t * data )
{
    int eoln_pos = 0;
    printf( "Zadejte jmeno osoby: " );

    if( !io_utils_get_string( data->jmeno, 255 ) ) {
        return false;
    }
/*size_t strspn(const char *s, const char *accept);
Vrací počet počátečních znaků, ve kterých řetězec s obsahuje znaky z řetězce accept (v libovolném pořadí)*/
    eoln_pos = strcspn( data->jmeno, "\n\r" );    /* Najdi pozici konce radku */
    data->jmeno[eoln_pos] = 0;                    /* a "ustrihni" konec radku */
    printf( "Zadejte vek, vahu a vysku (oddelene Enter):\n" );

    if( !io_utils_get_double( &data->vek ) ) {
        return false;
    }

    if( !io_utils_get_double( &data->vaha ) ) {
        return false;
    }

    if( !io_utils_get_double( &data->vyska ) ) {
        return false;
    }

    return true;
}
/**************************************************/


