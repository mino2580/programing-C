#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "mymalloc.h"

//class first;
void error(char *message){
	fputs(message, stderr);
	exit(EXIT_FAILURE);
}
/************************************************************************/
/** \fn void ListInit(List_t* list)
 * \brief Provede inicializaci seznamu pøed jeho prvním pouitím.
 * \param list - seznam, který se má inicializovat
 *
 *	Inicializace spoèívá v naplnìní ukazatelù \link List_t#first list->first \endlink a
 *	\link List_t#active list->active \endlink nulovými ukazateli
 */
void List_Init(List_t *list){         //1
	list->active = NULL;
	list->first = NULL;	
	printf("list->active =%d\nlist->first = %d\n;",NULL,NULL);
}

/************************************************************************/
/** \fn void InsertFirst(List_t* list, Data_t data)
 * \brief Vytvoøí nový prvek a vloí jej na zaèátek seznamu.
 * \param list - seznam, do kterého se má nový prvek vkládat
 * \param data - data, která mají být obsahem nového prvního prvku
 *
 *	Vytvoøí nový prvek s datovou èástí "data" a vloí jej na zaèátek seznamu "list"
 */
void List_Insert_First(List_t* list, Data_t data){
	List_Node_t *novy = myMalloc(sizeof(List_Node_t));
	//printf("List_Node_t *novy = myMalloc(sizeof(List_Node_t))\nnovy =%d\n",novy);
	if (novy == NULL) error("List_Insert_First: vsechno na hovno");
	novy->data = data;
	 Data_Print(&novy->data);
	// printf("&novy->data=%d\n",novy->data);
	novy->next = list->first;
	//printf("novy->next =  =%d\n",novy->next);
	list->first = novy;//adresa ,na konec zustane posledny prvek na zacatku seznamu
//printf("list->first = novy =%d\n",novy);

}
/************************************************************************/
/** \fn void First(List_t* list)
 * \brief Nastaví ukazatel aktivního prvku na 1. prvek.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *	Nastaví \link List_t#active list->active \endlink na hodnotu
 *	\link List_t#first list->first \endlink
 */
void List_First(List_t* list){
	list->active = list->first;
	//printf("list->active = list->first \nlist->active = %d",list->active);
}

/************************************************************************/
/** \fn Data_t CopyFirst(List_t list)
 * \brief Vrátí data 1. prvku seznamu
 * \param list - seznam, se kterým má být tato operace provedena
 * \param *data - pointer, který slou¾í k navrácení data ze seznamu
 * \return Vrátí true, pokud je prvek pøeèten jinak vrátí false
 */
bool List_Copy_First(List_t list, Data_t *data){
	if (list.first != NULL){
		*data = list.first->data;
		return true;
	}
	else return false;
}

/************************************************************************/
/** \fn void DeleteFirst(List_t* list)
 * \brief Ruí první prvek seznamu.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *   Pokud byl první prvek zároveò aktivním prvkem, aktivita se ztrácí.
 *   Pokud byl seznam prázdný, nic se nedìje.
 */
void List_Delete_First(List_t* list){
	if (list->first != NULL){
		if (list->first == list->active) list->active = NULL;
		List_Node_t *deleted = list->first;
		list->first = list->first->next;
		myFree(deleted);
		printf("list->first %d",list->first);
	}
}
/************************************************************************/
/** \fn void PostDelete(List_t* list)
 * \brief Ruí první prvek seznamu za aktivním prvkem.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *   Pokud nebyl seznam aktivní, nic se nedìje.
 *   Pokud byl seznam prázdný, nic se nedìje.
 */
void List_Post_Delete(List_t* list){
	if (list->active == NULL) return; //&& list->active->next != NULL) return;
	List_Node_t *deleted = list->active->next;
	list->active->next = deleted->next;
	myFree(deleted);
}

/************************************************************************/
/** \fn void PostInsert(List_t* list, Data_t data)
 * \brief Vloí nový prvek za aktivní prvek seznamu.
 * \param list - seznam, do kterého se má nový prvek vkládat
 * \param data - data, která mají být obsahem nového prvku
 *
 *	Vytvoøí nový prvek s datovou èástí "data" a vloí jej za aktivní prvek
 *  seznamu "list". Pokud nebyl seznam aktivní, nedìlá nic.
 */
void List_Post_Insert(List_t* list, Data_t data){
	if (list->active == NULL) return;
	List_Node_t *novy = myMalloc(sizeof(List_Node_t));
	if (novy == NULL) error("List_Post_Insert: furt na hovno");
	novy->data = data;
	novy->next = list->active->next;
	list->active->next = novy;
	//list->active = novy;
}

/************************************************************************/
/** \fn Data_t LCopy(List_t list)
 * \brief Vrátí data aktivního prvku seznamu
 * \param list - seznam, se kterým má být tato operace provedena
 * \param *data - pointer, který slou¾í k navrácení data ze seznamu
 * \return Vrátí true, pokud je prvek pøeèten jinak vrátí false
 *
 * Pokud seznam není aktivní vrátí false.
 */
bool List_Copy(List_t list, Data_t *data){
	if (list.active == NULL) return false;
	*data = list.active->data;
	return true;
}

/************************************************************************/
/** \fn void Actualize(List_t* list, Data_t data)
 * \brief Pøepíe obsah aktivní poloky novými daty.
 * \param list - seznam, do kterého se má nový prvek vkládat
 * \param data - data, která mají být obsahem nového prvku
 *
 *  Pokud není seznam aktivní, nedìlá nic.
 */
void List_Actualize(List_t *list, Data_t data){
	if (list->active == NULL) return;
	list->active->data = data;
	 
}


/************************************************************************/
/** \fn void LSucc(List_t* list)
 * \brief Posune aktivitu na následující prvek seznamu.
 * \param list - seznam, se kterým má být tato operace provedena
 *
 *  Pokud není ádný prvek aktivní, nedìlá nic.
 */
void List_Succ(List_t* list){
	if (list->active == NULL) return;
	list->active = list->active->next;	
}

/************************************************************************/
/** \fn bool Active(List_t list)
 * \brief Je-li seznam aktivní, vrací true
 * \param list - seznam, se kterým má být tato operace provedena
 */
bool List_Is_Active(List_t list){
 if (list.active != NULL) return true;
 else return false;	
}