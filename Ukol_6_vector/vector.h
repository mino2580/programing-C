/**
 * @file    vector.h
 * @author  Roman Dosek, Toas Jurena
 * @date    2/2015
 * @brief   Headers of Vector data structure
 */

#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdint.h>
#include <stdbool.h>

/* Vector structure */
typedef struct {

    uint64_t *items;        /**< Internal pointer to allocated memory */
    uint64_t size;          /**< Number of currently allocated cells */
    uint64_t free_cells;     /**< Number of unused cells inside Vector */
    uint32_t alloc_step;    /**< Number of cells allocated during expanding */
} Vector_t;

/* Public Vector API */
/**
 * @brief   Vytvoří vektor s počáteční velikostí speicifikovanou parametrem
 * @param   initial_size    počáteční velikost Vectoru
 * @param   alloc_step      Určuje, po jak velkých blocích se přialokovává paměť
 * @return  Vrací nově alokovanou strukturu popisující Vector jinak NULL pokud dojde k problémům.
 */
Vector_t *Vector_Create( uint64_t initial_size, uint32_t alloc_step );

/**
 * @brief   Vytvoří samostatnou kopii vektoru
 * @param   original    Ukazatel na kopírovaný Vector
 * @return  Vrací strukturu popisující zkopírovaný Vector. Při chybách vrátí NULL
 */
Vector_t *Vector_Copy( const Vector_t *original );

/**
 * @brief   Vymaže obsah vektoru, uvolní paměť a nastaví jeho velikost na 0. Prvek alloc_step zůstává nezměněn.
 * @param   vector  Ukazatel na Vector
 */
void Vector_Clear( Vector_t *vector );

/**
 * @brief   Vrací aktuální délku vektoru
 * @param   vector  Ukazatel na Vector
 * @return  Aktuální délka vektoru nebo UINT64_MAX pokud je předán NULL
 */
uint64_t Vector_Length( Vector_t *vector );

/**
 * @brief   Navrací hodnotu vektoru na vybraném umístění
 * @param   vector      Ukazatel na Vector
 * @param   position    Pozice v rámci Vectoru
 * @param   value       Ukazatel pro navrácení hodnoty pokud byla nalezena
 * @return  Vrací true pokud je prvek ve vektoru jinak false
 */
bool Vector_At( Vector_t *vector, uint64_t position, uint64_t *value );

/**
 * @brief   Odstraní prvek na vybrané pozici a posune data o prvek doleva.
 * @param   vector      Ukazatel na Vector
 * @param   position    Pozice v rámci Vectoru
 * @return  Vrací true pokud byla pozice uvnitř rozsahu jinak false
 */
bool Vector_Remove( Vector_t *vector, uint64_t position );

/**
 * @brief   Přidá novou hodnotu na konec vektoru
 * @param   vector  Ukazatel na Vector
 * @param   value   Vkládaná hodnota
 */
void Vector_Append( Vector_t *vector, uint64_t value );

/**
 * @brief   Funkce slouží k zjištění, jestli se někde ve vektoru nachází daná hodnota
 * @param   vector  Ukazatel na Vector
 * @param   value   Hledaná hodnota
 * @return  Vrací true pokud je hodnota nalezena, jinak false
 */
bool Vector_Contains( Vector_t *vector, uint64_t value );

/**
 * @brief   Hledá pozici prvku s danou hodnotou ve Vectoru
 * @param   vector  Ukazatel na Vector
 * @param   value   Hledaná hodnota
 * @param   from    Pozice od které se začíná hledat
 * @return  Vrací pozici prvku pokud je nalezen, jinak -1
 */
int64_t Vector_IndexOf( Vector_t *vector, uint64_t value, uint64_t from );

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
void Vector_Fill( Vector_t *vector, uint64_t value, uint64_t start_position, uint64_t end_position );

#endif //__VECTOR_H
