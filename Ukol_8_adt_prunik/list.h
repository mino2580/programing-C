#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include "data.h"

/*!
 * \file list.h
 * \brief Hlavičkový soubor modulu ADT Lineární seznam
 *
 * Zde najdete kompletní implementaci ADT lineární seznam - tj. definici datových
 * typů a metod, které s nimi pracují
 */

//typedef enum {false, true} bool; /* pro ANSI C si nadefinujeme bool */


/************************************************************************/
/** \struct List_Node_s
 * Zde je definován jeden prvek lineárního seznamu.
 *
 * \var typedef List_Node_s List_Node_t
 * \var typedef List_Node_t * List_Node_Ptr_t
 */
typedef struct List_Node_s
{	Data_t data;                /**< datová část prvku */
	struct List_Node_s * next; /**<	ukazatel na dalí prvek */
} List_Node_t;

typedef List_Node_t * List_Node_Ptr_t;

/************************************************************************/
/** \struct List_t
 * Zde je definován seznam jako ukazatel na první a ukazatel na aktivní prvek.
 */
typedef struct {
	List_Node_t *  first;					/**< ukazatel na první prvek seznamu */
	List_Node_t *  active;					/**< ukazatel na aktivní prvek seznamu */
} List_t;


/************************************************************************/
/** \fn void ListInit(List_t* list)
 * \brief Provede inicializaci seznamu před jeho prvním pouitím.
 * \param list - seznam, který se má inicializovat
 *
 *	Inicializace spočívá v naplnění ukazatelů \link List_t#first list->first \endlink a
 *	\link List_t#active list->active \endlink nulovými ukazateli
 */
void List_Init(List_t *list);

/************************************************************************/
/** \fn void InsertFirst(List_t* list, Data_t data)
 * \brief Vytvoří nový prvek a vloí jej na začátek seznamu.
 * \param list - seznam, do kterého se má nový prvek vkládat
 * \param data - data, která mají být obsahem nového prvního prvku
 *
 *	Vytvoří nový prvek s datovou částí "data" a vloí jej na začátek seznamu "list"
 */
void List_Insert_First(List_t *list, Data_t data);

/************************************************************************/
/** \fn void First(List_t* list)
 * \brief Nastaví ukazatel aktivního prvku na 1. prvek.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *	Nastaví \link List_t#active list->active \endlink na hodnotu
 *	\link List_t#first list->first \endlink
 */
void List_First(List_t *list);

/************************************************************************/
/** \fn Data_t CopyFirst(List_t list)
 * \brief Vrátí data 1. prvku seznamu
 * \param list - seznam, se kterým má být tato operace provedena
 * \param *data - pointer, který slouží k navrácení data ze seznamu
 * \return Vrátí true, pokud je prvek přečten jinak vrátí false
 */
bool List_Copy_First(List_t list, Data_t *data);

/************************************************************************/
/** \fn void DeleteFirst(List_t* list)
 * \brief Ruí první prvek seznamu.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *   Pokud byl první prvek zároveň aktivním prvkem, aktivita se ztrácí.
 *   Pokud byl seznam prázdný, nic se neděje.
 */
void List_Delete_First(List_t *list);

/************************************************************************/
/** \fn void PostDelete(List_t* list)
 * \brief Ruí první prvek seznamu za aktivním prvkem.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *   Pokud nebyl seznam aktivní, nic se neděje.
 *   Pokud byl seznam prázdný, nic se neděje.
 */
void List_Post_Delete(List_t *list);

/************************************************************************/
/** \fn void PostInsert(List_t* list, Data_t data)
 * \brief Vloí nový prvek za aktivní prvek seznamu.
 * \param list - seznam, do kterého se má nový prvek vkládat
 * \param data - data, která mají být obsahem nového prvku
 *
 *	Vytvoří nový prvek s datovou částí "data" a vloí jej za aktivní prvek
 *  seznamu "list". Pokud nebyl seznam aktivní, nedělá nic.
 */
void List_Post_Insert(List_t *list, Data_t data);


/************************************************************************/
/** \fn Data_t LCopy(List_t list)
 * \brief Vrátí data aktivního prvku seznamu
 * \param list - seznam, se kterým má být tato operace provedena
 * \param *data - pointer, který slouží k navrácení data ze seznamu
 * \return Vrátí true, pokud je prvek přečten jinak vrátí false
 *
 * Pokud seznam není aktivní vrátí false.
 */
bool List_Copy(List_t list, Data_t *data);

/************************************************************************/
/** \fn void Actualize(List_t* list, Data_t data)
 * \brief Přepíše obsah aktivní polozky novými daty.
 * \param list - seznam, do kterého se má nový prvek vkládat
 * \param data - data, která mají být obsahem nového prvku
 *
 *  Pokud není seznam aktivní, nedělá nic.
 */
void List_Actualize(List_t *list, Data_t data);


/************************************************************************/
/** \fn void LSucc(List_t* list)
 * \brief Posune aktivitu na následující prvek seznamu.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *  Pokud není ádný prvek aktivní, nedělá nic.
 */
void List_Succ(List_t *list);

/************************************************************************/
/** \fn bool Active(List_t list)
 * \brief Je-li seznam aktivní, vrací true
 * \param list - seznam, se kterým má být tato operace provedena
 */
bool List_Is_Active(List_t list);

#endif
