// Private includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Private typedef
typedef struct {
    int id;
    char jmeno[64], prijmeni[64], adresa[256], telefon[32];
} tClovek;


               /////////////jak to funguje.?
static enum SORT {
    ID, JMENO, PRIJMENI, ADRESA, TELEFON
} radimeDle = TELEFON;

// Private function prototypes
static int handleCommandLineArguments( int argc, char** argv, enum SORT *sortType, char *path );
static int compareItems( const void *p1, const void *p2 );

// Private functions

int main( int argc, char *argv[] )
{
	
	//praca na cviceni
    tClovek pole[256]= {
		
	   {1,"franta","spacek","nad stranemi","1234"},
	   {2,"frant ","bednarovae ","nad stranem ","123"},
	   {3,"fran ","adolf","nad strane ","12 "},
	   {4,"fra ","jiri ","nad stran ","1 "},
	
     };
    char filePath[256];

    //zpracujeme parametr prikazove radky
    if( handleCommandLineArguments( argc, argv, &radimeDle, filePath ) == 0 ) {
        fprintf( stderr, "Nespravne zadane argumenty." );
        return 0;
    }
                 /////////////jak to funguje.?
    FILE *inputFile = fopen( filePath, "r" );




    // praca na cviceni
    if( inputFile == NULL ) {
        fprintf( stderr, "Soubor \"%s\"se nepodařilo otevřít.", filePath );
    }
    int r=0;//cislo radku
    char radek[256];
    while(fgets(radek,256,inputFile)!=NULL) {
		//puts(radek);
		
		if(sscanf(radek,"%[^;];%[^;];%[^;];%[^;];",
		pole[r].jmeno,pole[r].prijmeni,pole[r].adresa,
		pole[r].telefon) ==4 )
		r++;
		
		else {
			fprintf(stderr,"eror,radek ve spatnem formatu  %s\n",radek);
		}
		
	}



    //praca na cviceni
    // razeni: qsort
    qsort( pole, r,/*sizeof( pole ) / sizeof( tClovek ),*/ sizeof( tClovek ), compareItems );

    // vypis vysledku
    for(   int i = 0; i < r/*sizeof( pole ) / sizeof( tClovek )*/; i++ ) {
        printf( "%d; %s; %s; %s; %s\n", pole[i].id, pole[i].jmeno, pole[i].prijmeni, pole[i].adresa, pole[i].telefon );
    }

    return 0;
}

/**
 * @brief Try to parse given commandline arguments
 * @param[in] argc Count of arguments
 * @param[in] argv Arguments
 * @param[out] sortType Pointer to enum SORT to return type of sort
 * @param[out] path Pointer to char to store filepath
 * @return Returns 0 of argument count is not 5 and all required arguments are present. Otherwise return 1;
 */
int handleCommandLineArguments( int argc, char** argv, enum SORT *sortType, char *path )
{
    // parse seed and file path from cmd line
    if( argc == 5 ) {
        int correct = 0;

        for( int i = 1; i < 5; i += 2 ) {
            if( strcmp( argv[i], "-type" ) == 0 ) {
                switch( argv[i + 1][0] ) {
                    case 'i':
                        *sortType =  ID;
                        break;

                    case 'j':
                        *sortType =   JMENO;
                        break;

                    case 'p':
                        *sortType =  PRIJMENI;
                        break;

                    case 'a':
                        *sortType =  ADRESA;
                        break;

                    case 't':
                        *sortType = TELEFON;
                        break;

                    default:
                        printf( "1. parametr prikazoveho je pismeno, ktere urcuje, podle ceho budeme radit\n"
                                "i: dle ID, j: dle jmena, p: prijemni, a: adresy, t: telefonu\n" );
                        *sortType = TELEFON;
                }

                correct++;
                continue;
            }

            if( strcmp( argv[i], "-file" ) == 0 ) {
                strcpy( path, argv[i + 1] );
                correct++;
            }
        }

        if( correct == 2 ) {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Function to compare two items
 * @param[in] p1
 * @param[in] p2
 * @return Return 0 of items are equal, >0 when first item is bigger, 0< when first item is smaller
 */
int compareItems( const void *p1, const void *p2 )
{
    const tClovek * c1 = p1, *c2 = p2;

    switch( radimeDle ) {
        case ID:
            return c1->id - c2->id;

        case JMENO:
            return strcmp( c1->jmeno, c2->jmeno );

        case PRIJMENI:
            return strcmp( c1->prijmeni, c2->prijmeni );

        case ADRESA:
            return strcmp( c1->adresa, c2->adresa );

        case TELEFON:
            return strcmp( c1->telefon, c2->telefon );
    }

    return 0;
}
