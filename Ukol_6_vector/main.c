#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "vector.h"
#include "ioutils.h"
#include "mymalloc.h"
//haalo

void Free_Exit(Vector_t *v){
	printf("Uvolnuji vsechnu pridelenou pamet.\n");
	myFree(v->items);
	myFree(v);	 
	printf("Vsechna pridelena pamet byla uvolnena.\n");
	exit(EXIT_SUCCESS);
}

int main(void){
	uint64_t siz, inc;
	char ch[255];
	bool alive = true;
    printf("Vector test program\n"
		   "Zadejte prosim vychozi velikost pole a velikost prirustku.\n"
		   "Velikost:\n");
	if (!io_utils_get_uint64_t(&siz)){
		printf("Konec souboru, koncime.\n");
		exit(EXIT_SUCCESS);
	}
	printf("Prirustek:\n");
	if (!io_utils_get_uint64_t(&inc)){
		printf("Konec souboru, koncime.\n");
		exit(EXIT_SUCCESS);
	}

	Vector_t *v = Vector_Create(siz, inc);
	Vector_t *copy;
	
	for (unsigned int i = 0; i < 100; i = i + 5){
		Vector_Append(v, i);
	}
 	uint64_t val, startpos, endpos;
	while (alive){
		printf("Stisknete:\n"
		 "1 pro vypis delky vektoru\n"
		 "2 pro pridani prvku\n"
		 "3 pro odebrani prvku\n"
		 "4 pro vypis vsech prvku\n"
		 "5 pro zjisteni jestli vektor obsahuje prvek\n"
		 "6 pro nalezeni pozice prvku\n"
		 "7 pro vycisteni vektoru\n"
		 "8 pro vyplneni casti vektoru predanou hodnotou\n"
		 "9 pro vytvoreni kopie vektoru\n"
		 "0 pro vypsani jednoho prvku\n"
		 "cokoli jineho pro konec.\n");
		if (io_utils_get_string(ch, 255) == false) alive = false; 
		switch (ch[0]){
			case'1':	//delka vektoru
				printf("Delka vektoru: %" PRIu64 "\n", Vector_Length(v));	
			break;
			case'2':	//pridani prvku
			    printf("Vlozte hodnotu prvku:\n");
				io_utils_get_uint64_t(&val);
				Vector_Append(v, val);			
			break;
			case'3':	//odebrani prvku
			    printf("Zadejte pozici prvku ktery chcete odebrat:\n");
				if (!io_utils_get_uint64_t(&val)){			//podminka pro output 6, asi by mela byt u vsech vstupu, ktere nejsou pro hlavni menu...
					printf("Konec souboru, koncime.\n");
					Free_Exit(v);
				}
				Vector_Remove(v, val);
				//printf("free %" PRIu64 "size %" PRIu64 "\n", v->free_cells, v->size);				
			break;
			case'4':	//vypis vsech prvku
				for (unsigned int i = 0; i < Vector_Length(v); i++){
					Vector_At(v, i, &val);
					printf("vector[%d]: %" PRIu64 "\n", i, val);
				}
			break;
			case'5':	//jestli obsahuje prvek
			    printf("Zadejte hodnotu hledaneho prvku:\n");
				io_utils_get_uint64_t(&val);
				if (Vector_Contains(v, val)) printf("Vector obsahuje prvek\n");
				else printf("Vector neobsahuje prvek\n");
			break;
			case'6':	//nalezeni pozice prvku
			    printf("Zadejte hodnotu hledaneho prvku:\n");
				io_utils_get_uint64_t(&val);
				printf("Zadejte pocatecni index hledani:\n");
				io_utils_get_uint64_t(&startpos);
				printf("Pozice prvku: %" PRId64 "\n", Vector_IndexOf(v, val, startpos));
			break;
			case'7':	//vycisteni
				Vector_Clear(v);
			break;
			case'8':	//vyplneni casti vektoru predanou hodnotou
			    printf("Zadejte hodnotu, ktera ma byt zapsana:\n");
				io_utils_get_uint64_t(&val);
				printf("Zadejte startovni pozici:\n");
				io_utils_get_uint64_t(&startpos);
				printf("Zadejte koncovou pozici:\n");
				io_utils_get_uint64_t(&endpos);
				Vector_Fill(v, val, startpos, endpos);				
			break;
			case'9':	//vytvoreni kopie
				copy = Vector_Copy(v);
				Vector_At(copy, 0, &val);
				printf("copy[0]: %" PRIu64 "\n", val);
				printf("Odebiram vektor \"copy\"\n");
				myFree(copy->items);
				myFree(copy);	 				
			break;
			case'0':	//vypsani jednoho prvku
				printf("Zadejte index prvku:\n");
				io_utils_get_uint64_t(&startpos);
				if (Vector_At(v, startpos, &val)) printf("vector[%" PRIu64 "]: %" PRIu64 "\n", startpos, val);
				else printf("Prvek na indexu %" PRIu64 " nebyl ve vektoru nalezen.\n", startpos);
			break;
			//case'k':			//aby vysel test 1 - moc to nechapu
			//	alive = false;
		//		printf("Uvolnuji vsechnu pridelenou pamet.\n");
		//		myFree(v->items);
		//		myFree(v);	 
		//		printf("Vsechna pridelena pamet byla uvolnena.\n");
				//return EXIT_SUCCESS;
		//	break;
			default:
				//alive = false;
				Free_Exit(v);
				//printf("Uvolnuji vsechnu pridelenou pamet.\n");
				//myFree(v->items);
				//myFree(v);	 
				//printf("Vsechna pridelena pamet byla uvolnena.\n");
				//return EXIT_SUCCESS;
			break;
		}
	}
	printf("Konec souboru, koncime.\n");
	Free_Exit(v);
	return 0;
}

