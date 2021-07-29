#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "vector.h"
#include "mymalloc.h"

/* Public Vector API */
/**
 * @brief   Vytvoří vektor s počáteční velikostí speicifikovanou parametrem
 * @param   initial_size    počáteční velikost Vectoru
 * @param   alloc_step      Určuje, po jak velkých blocích se přialokovává paměť
 * @return  Vrací nově alokovanou strukturu popisující Vector jinak NULL pokud dojde k problémům.
 */
Vector_t *Vector_Create( uint64_t initial_size, uint32_t alloc_step ){
	//printf("cre");
	Vector_t *novy = myMalloc(sizeof(Vector_t));
	if (novy == NULL){
		myFree(novy);
		printf("Nepodarilo se alokovat pamet pro vektor.\n");
	}
	novy->items = myMalloc(initial_size * sizeof(uint64_t));
	if (novy->items == NULL){
		myFree(novy);
		printf("Nepodarilo se alokovat pamet pro vektor.\n");
	}
	novy->size = initial_size;
	novy->free_cells = initial_size;
	novy->alloc_step = alloc_step;
	return novy;
}

/**
 * @brief   Vytvoří samostatnou kopii vektoru
 * @param   original    Ukazatel na kopírovaný Vector
 * @return  Vrací strukturu popisující zkopírovaný Vector. Při chybách vrátí NULL
 */
Vector_t *Vector_Copy( const Vector_t *original ){
	Vector_t *novy = myMalloc(sizeof(Vector_t));
	if (novy == NULL){
		myFree(novy);
		printf("Nepodarilo se alokovat pamet pro vektor.\n");
	}
	novy->items = myMalloc(original->size * sizeof(uint64_t));
	if (novy->items == NULL){
		myFree(novy);
		printf("Nepodarilo se alokovat pamet pro vektor.\n");
	}
	novy->size = original->size;
	novy->free_cells = original->free_cells;
	novy->alloc_step = original->alloc_step;
	for (unsigned int i = 0; i < (novy->size - novy->free_cells); i++){
		novy->items[i] = original->items[i];
	}
	return novy;
}

/**
 * @brief   Vymaže obsah vektoru, uvolní paměť a nastaví jeho velikost na 0. Prvek alloc_step zůstává nezměněn.
 * @param   vector  Ukazatel na Vector
 */
void Vector_Clear( Vector_t *vector ){
	myFree(vector->items);
	vector->items = NULL;
	vector->size = 0;
	vector->free_cells = 0;
}

/**
 * @brief   Vrací aktuální délku vektoru
 * @param   vector  Ukazatel na Vector
 * @return  Aktuální délka vektoru nebo UINT64_MAX pokud je předán NULL
 */
uint64_t Vector_Length( Vector_t *vector ){
	if (vector == NULL) return UINT64_MAX;
	return (vector->size - vector->free_cells);
}

/**
 * @brief   Navrací hodnotu vektoru na vybraném umístění
 * @param   vector      Ukazatel na Vector
 * @param   position    Pozice v rámci Vectoru
 * @param   value       Ukazatel pro navrácení hodnoty pokud byla nalezena
 * @return  Vrací true pokud je prvek ve vektoru jinak false
 */
bool Vector_At( Vector_t *vector, uint64_t position, uint64_t *value ){
	if (position >= (vector->size - vector->free_cells)) return false;
	*value = vector->items[position];
	return true;
}

/**
 * @brief   Odstraní prvek na vybrané pozici a posune data o prvek doleva.
 * @param   vector      Ukazatel na Vector
 * @param   position    Pozice v rámci Vectoru
 * @return  Vrací true pokud byla pozice uvnitř rozsahu jinak false
 */
bool Vector_Remove( Vector_t *vector, uint64_t position ){
	if (position >= (vector->size - vector->free_cells)) return false;
	for (unsigned int i = position; i < (vector->size - vector->free_cells); i++){
		vector->items[i] = vector->items[i+1];
	}
	vector->free_cells++;
	return true;
}

/**
 * @brief   Přidá novou hodnotu na konec vektoru
 * @param   vector  Ukazatel na Vector
 * @param   value   Vkládaná hodnota
 */
void Vector_Append( Vector_t *vector, uint64_t value ){
	//printf("app");
	if (vector->free_cells == 0){
		uint64_t *uk = myRealloc(vector->items, sizeof(uint64_t) * (vector->size + vector->alloc_step));
		if (uk == NULL){
			myFree(vector);
			printf("Nepodarilo se alokovat pamet pro vektor.\n");
		}
		vector->items = uk;
		vector->size += vector->alloc_step;
		vector->free_cells = vector->alloc_step;
	}
	uint64_t index = (vector->size - vector->free_cells);
	vector->items[index] = value;
	vector->free_cells--;
	//printf("%lld ", vector->items[index]);
}

/**
 * @brief   Funkce slouží k zjištění, jestli se někde ve vektoru nachází daná hodnota
 * @param   vector  Ukazatel na Vector
 * @param   value   Hledaná hodnota
 * @return  Vrací true pokud je hodnota nalezena, jinak false
 */
bool Vector_Contains( Vector_t *vector, uint64_t value ){
	for (unsigned int i = 0; i < (vector->size - vector->free_cells); i++){
		if (vector->items[i] == value) return true;
	}
	return false;
}

/**
 * @brief   Hledá pozici prvku s danou hodnotou ve Vectoru
 * @param   vector  Ukazatel na Vector
 * @param   value   Hledaná hodnota
 * @param   from    Pozice od které se začíná hledat
 * @return  Vrací pozici prvku pokud je nalezen, jinak -1
 */
int64_t Vector_IndexOf( Vector_t *vector, uint64_t value, uint64_t from ){
	for (uint64_t i = from; i < (vector->size - vector->free_cells); i++){
		if (vector->items[i] == value) return i;
	}
	return -1;	
}

/**
 * @brief   Vyplní část vektoru zadanou rozsahem nějakou hodnotou. Vektor je přepsán od začáteční pozice až po koncovou (včetně).
 * Pokud je koncová pozice za rozsahem vektoru, je vyplněna část od počáteční pozice po poslení prvek vektoru. Jestli je počáteční pozice za koncem vektoru,
 * není vykonáno nic.
 * #note    Bonusová funkce pro aktivní studenty
 * @param   vector          Ukazatel na Vector
 * @param   value           Nastavovaná hodnota
 * @param   start_position  Počáteční pozice
 * @param   end_position    Konečná pozice
 */
void Vector_Fill( Vector_t *vector, uint64_t value, uint64_t start_position, uint64_t end_position ){
	if (start_position > (vector->size - vector->free_cells)) return;
	if (end_position > (vector->size - vector->free_cells)) end_position = vector->size - vector->free_cells;
	for (unsigned int i = start_position; i <= end_position; i++){
		vector->items[i] = value;
	}
}