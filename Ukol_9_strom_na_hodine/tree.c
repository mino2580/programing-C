#include "tree.h"
#include <stdlib.h>
#include "mymalloc.h"
/*!
 * \brief Provede inicializaci stromu před jeho použitím.
 * \param root Ukazatel na inicializovaný strom
 */
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
bool Tree_Insert(Tree * const root, const Data_t data)  //vloz do stromu
{
    (void)root;                   //vkladyni do stromu data
    (void)data;
	if(root==NULL) return false;  //test jestli se to podari
	TreeNode*uk=root->root,*prev=NULL;       //ukazatel na tree node 
	int cmp=0;                    //pomocna promenna pro funkci,jen pro optimalizaci
	                              // *prev=NULL; ukazatel na posledni bunky
	while(uk!=NULL)
    { //porovnava delkz retezcu,vacsi do prava
		prev=uk;                  //pomocna premenna
		cmp=Data_Cmp(&uk->data,&data);
		                          //dva krat volana funkce s dvoma parametramy
		if( cmp<0)                //porovnani do leva nebo prava
			uk=uk->right;
			else if (cmp>0)       //pokud je mensi vraci -1,nebo1
				uk=uk->left;
				else return false;//data ve strome jsou=koncime
	}
	//uk alokujem novu pamat o velikosti treenode
	uk=myMalloc(sizeof(TreeNode));  //uk konec bunky kde se uklada dalsi dresa v pripade alokce nove bunky
	uk->left=uk->right=NULL;  //nasel jsem misto kam to mam vlozit uk==0
	uk->data=data;  //ukladam data ktere nam da uzivatel
	if(prev==NULL)   //vkladani do prazdneho stromu 
	{
     root->root=uk;  //ano´novy uzel bude koren stromu
	} else            //vkladam za existujuci uzel
	{                  //ne =vkladame za existujuci uzel
	if(cmp<0) prev->right=uk;  //jestlize posledni porovnani je <jak nula uloz adresu alokace pamati do prava 
	else prev->left=uk;   // jinak obracene 
	}
	root->itemsCount++;
    return true;
}
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
/*!
 * \brief Vrátí ukazatel na uzel, který drží daná data.
 * \param root Ukazatel na strom, ve kterém má být uzel vyhledán
 * \param data Ukazatel na data, která budou hledána
 * \return Fce vrátí ukazatel na uzel držící hledaná data pokud existuje, jinak vrátí NULL
 */
TreeNode *Tree_Find_Node(Tree root, const Data_t data){
//Data_t  data;				/**< Data listu stromu */
//struct _TreeNode * left;	/**< Ukazatel na levý list stromu */
//struct _TreeNode * right;	/**< Ukazatel na pravý list stromu */
	(void)root;
    (void)data;
	TreeNode*uk=root.root;      //struktura,ne ukazatel,mazu sipku,davam tecku
	int cmp=0;                    //pomocna promenna pro funkci,jen pro optimalizaci
	                              // *prev=NULL; ukazatel na posledni bunky
	while(uk!=NULL)
    { 
		cmp=Data_Cmp(&uk->data,&data);
		                          //dva krat volana funkce s dvoma parametramy
		if(cmp<0) uk=uk->right;  //porovnani do leva nebo prava
		else if (cmp>0) uk=uk->left;       //pokud je mensi vraci -1,nebo1
		else return uk  ;//data ve strome jsou=vracime na ne ukazatel
	}
    
    return NULL;
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

/*!
 * \brief Zpracuje každý uzel stromu pomocí funkce specifikované ukazatelem "proc". Průchod stromem
 * může být trojí: PREORDER, INORDER a POSTORDER.
 * \param root Ukazatel na strom jehož uzly mají být zpracovány
 * \param proc Ukazatel na callback funkci pro zpracování uzlu
 * \param mode Typ průchodu stromem (viz. výčtový typ TreeProcessMode)
 * \sa TreeProcessMode
 */
void Tree_Process(Tree root,TreeNodeProc proc,TreeProcessMode mode) { 
    (void)root;
    (void)proc;
    (void)mode;
	switch(mode) {
		
	case procPREORDER:
	zpracuj_strom_preorder(root.root,proc);
	break;
	 
	case procINORDER:
	 zpracuj_strom_inorder(root.root,proc);
		break;
	 
	case procPOSTORDER :
	zpracuj_strom_postorder(root.root,proc);
		break;
	}
	
 }