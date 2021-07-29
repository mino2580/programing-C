#include "tree.h"
#include <stdlib.h>
#include "mymalloc.h"
/*!
 * \brief Provede inicializaci stromu před jeho použitím.
 * \param root Ukazatel na inicializovaný strom
 */
 /*typedef struct _Tree {
    TreeNode * root;    //ukazatel na zacatek stromu
    unsigned int itemsCount;//pocet položek stromu
} Tree;*/
bool Tree_Init(Tree * const root)  //inicializace stromu
{
    (void)root;
	if(root==NULL) return false;//test pokud by strom nebyl inicializovan
	root->itemsCount=0;
	root->root=NULL;// TreeNode * root;    //ukazatel na zacatek stromu  
    return true;
}
/*!
 * \brief Odstraní všechny listy stromu.
 * \param root Ukazatel na strom
 */
void Tree_Clear(Tree * const root) //nemuzu pouzit free aniz bz si pamatal ukazatele
{
    (void)root;
	Tree_Process(*root,(TreeNodeProc)myFree,procPOSTORDER);
	root->itemsCount=0;
	root->root=NULL;
}
/*!
 * \brief Vytvoří uzel s daty a vloží ho do stromu na správnou pozici.
 * \param root Ukazatel na strom, kam má být nový uzel vložen
 * \param data Ukazatel na data stromu
 * \return Fce vrátí hodnotu TRUE proběhla-li operace úspěšně. V případě, že se nepodařilo vytvořit
 * nový uzel, nebo strom ji obsahuje uzel se stejnými daty, bude vrácena hondota FALSE.
 */

/*!
 * \brief Smaže uzel ze stromu obsahující data o dané hodnotě dle příslušných pravidel (viz. přednáška) včetně jeho dat, je-li příznak stromu "deleteContents" roven TRUE.
 * \param root Ukazatel na strom, odkud má být uzel smazán
 * \param data Ukazatel na data obsažená v mazaném uzlů (může se jednat o jinou instanci Data_tu; důležité je pouze hodnota)
 */
void Tree_Delete(Tree * const root, const Data_t data)//zmaze nekteri s uzlu a napoji na ostatne uzly,bud pod nim nejvic v levo nebo v pravo
{
	
    (void)root;
    (void)data;
	if(root==NULL)  return ;  //test jestli se to podari
	TreeNode*uk=root->root,*prev=NULL;       //ukazatel na tree node 
	int cmp=0,prev_cmp=0;                    //pomocna promenna pro funkci,jen pro optimalizaci
	                              // *prev=NULL; ukazatel na posledni bunky
	while(uk!=NULL)
    { 
		prev=uk;                  //pomocna premenna
         prev_cmp=cmp;           //zaloha  uzlu     
		cmp=Data_Cmp(&uk->data,&data);
		                          //dva krat volana funkce s dvoma parametramy
		if( cmp<0)                //porovnani do leva nebo prava
			uk=uk->right;
			else if (cmp>0)       //pokud je mensi vraci -1,nebo1
				uk=uk->left;
				else 
				{ //nasli jsme mazany uzel !!!
					if(uk->left !=NULL && uk->right !=NULL)
                    {
						//nahrazeni otce nepravejsim uzlem leveho podstromu
					//domaci ukol !!!
					} else 
					{
						if(uk->left !=NULL || uk->right !=NULL) 
						{ //zistime kteri je nenulovi
						  TreeNode *nenulovy;	
						  if(uk->left !=NULL) nenulovy=uk->left;
						  else nenulovy=uk->right;
						  
						  if (prev==NULL) root->root=nenulovy;
						  else if (prev_cmp>0) prev->left=nenulovy;
						  else (prev->right=nenulovy);
						}
                         else
                         {
						   if (prev==NULL) root->root=NULL;
						   else {
						        if (prev_cmp>0) prev->left=NULL;
						        else prev->right=NULL;
					            }
						 }	
						
						myFree(uk);
				     }  
	 
				 }
	}
}





/*!
 * \brief Vrátí data uzlu.
 * \param node Ukazatel na data
 * \return Ukazatel na data uložená v uzlu
 */
const Data_t *Tree_Get_Data(const TreeNode * const node) //Získat data stromu
{ //vraceni dat z neakeho uzlu
    (void)node;
    return &node->data;
}

size_t Tree_Get_Count(Tree root) //vraceni dat z uzlu
{
    (void)root;
    return root.itemsCount;
}
//prvni
void zpracuj_strom_inorder(TreeNode *uk,TreeNodeProc user_fn) { //tisknu data rekurzivne
	if(uk!=NULL) {
		user_fn(uk);
		zpracuj_strom_inorder(uk->left,user_fn);
		zpracuj_strom_inorder(uk->right,user_fn);
        
		 
	}
}
//uprostred
void zpracuj_strom_preorder(TreeNode *uk,TreeNodeProc user_fn) { //tisknu data rekurzivne
	if(uk!=NULL) {
		user_fn(uk);
		zpracuj_strom_preorder(uk->left,user_fn);
		zpracuj_strom_preorder(uk->right,user_fn);
        
		 
	}
}
//konec
void zpracuj_strom_postorder(TreeNode *uk,TreeNodeProc user_fn) { //tisknu data rekurzivne
	if(uk!=NULL) {
		user_fn(uk); 
		zpracuj_strom_postorder(uk->left,user_fn);
		zpracuj_strom_postorder(uk->right,user_fn);
        
	}
}

