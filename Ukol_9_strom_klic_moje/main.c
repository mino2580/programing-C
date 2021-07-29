#include "tree.h"
#include "data.h"
#include "ioutils.h"
#include <stdio.h>
#define LIM 10 
 
 
 
void zpracuj_strom(TreeNode *uk,TreeNodeProc user_fn) { //tisknu data rekurzivne
	if(uk!=NULL) {
		zpracuj_strom(uk->left,user_fn);
        user_fn(uk);
		Data_Print(&uk->data);
		zpracuj_strom(uk->left,user_fn);
	}
}
void zvys_vek(TreeNode *uk) {
	uk->data.vek++;
}


void menu()
{
    printf( "1 - tree_init()\n"
            "2 - tree_clear()\n"
            "3 - tree_insert()\n"
            "4 - tree_delete()\n"
            "5 - tree_find_node()\n"
            "6 - tree_get_node_count()\n"
            "7 - tree_proces()\n"
            "M - zobraz toto menu\n"
            "K - konec\n"
            "Pro ukonceni stiskni CTRL+D (Linux) nebo CTRL+Z (Windows).\n\n" );
}


/**********************************************/
void process_tree_node( TreeNode* node )
{
    Data_Print( &node->data );
    printf( " | L -> " );

    if( node->left ) {
        Data_Print( &node->left->data );
    } else {
        printf( "NULL" );
    }

    printf( " | R -> " );

    if( node->right ) {
        Data_Print( &node->right->data );
    } else {
        printf( "NULL" );
    }

    printf( "\n" );
}
/////////////////////////////////////////////////////////////////////////////
//void prunik()
/*
Data_t Data_vloz( char * jmeno, double vek, double vaha, double vyska )
{
    Data_t data;
    strcpy(data.jmeno, jmeno);
    data.vek = vek;
    data.vaha = vaha; 
    data.vyska = vyska;
    return data;
}
*/

/*
void Data_Print1( Data_t  data )
{
    printf( "Jmeno=%s, vek=%0.1lf, vaha=%0.1lf, vyska=%0.1lf\n",
            data.jmeno, data.vek, data.vaha, data.vyska );
}*/
/********************************************/
			 Data_t datecka[LIM]={
        {"praha",5,1,1},
        {"bojkovice",2,2,2},
        {"pitin",3,8,8},
        {"brno",4,5,5},
        {"ujezdec",5,45,45},
        {"zlin",6,87,87},
        {"moskva",7,1,1},
        {"traktor",8,4,6},
        {"kombajn",9,2,3},
        {"auto",10,5,7}
    };
/////////////////////	
	Data_t datecka2[LIM]={
        {"martin",1,1,1},
        {"bojkovice",2,2,2},
        {"hostetin",11,8,8},
        {"luhacovice",12,5,5},
        {"brod",13,6,6},
        {"viden",14,7,7,},
        {"motorka",15,2,98},
        {"zlin",16,3,3},
        {"krokodyl",17,7,1},
        {"moskva",3,1,7}
    };


 /////////////////////////////////////////////////////////////////////////

TreeNode *Tree_Find_Node(Tree root, const Data_t data){
//Data_t  data;				/**< Data listu stromu */
//struct _TreeNode * left;	/**< Ukazatel na levý list stromu */
//struct _TreeNode * right;	/**< Ukazatel na pravý list stromu */
	(void)root;
    (void)data;
	TreeNode*uk=root.root;      //struktura,ne ukazatel,mazu sipku,davam tecku
	int cmp=0;                    //pomocna promenna pro funkci,jen pro optimalizaci
	                              // *prev=NULL; ukazatel na posledni bunky
	while(uk!=NULL)   //jedu rekurzivne
    { 
		cmp=Data_Cmp(&uk->data,&data);
		                          //dva krat volana funkce s dvoma parametramy
		if(cmp<0) uk=uk->right;  //porovnani do leva nebo prava
		else if (cmp>0) uk=uk->left;       //pokud je mensi vraci -1,nebo1
		else return uk  ;//data ve strome jsou=vracime na ne ukazatel
	}
    
    return NULL;
}

//////////////////////////////////////////////////////////////////////////




/*************************************************************************/
/*
struct Node * Search(int key)
{
struct Node *t=root;

while(t!=NULL)
{
if(key==t->data)
return t;
else if(key<t->data)
t=t->lchild;
else
t=t->rchild;
}
return NULL;
}
*/
/*********************************************************************/
 
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
 /*****************************************************************************/
 bool Tree_Insert(Tree * const root, const Data_t data)  //vloz do stromu
{
	////*typedef struct _TreeNode {
   // Data_t  data;				/**< Data listu stromu */
   // struct _TreeNode * left;	/**< Ukazatel na levý list stromu */
  //  struct _TreeNode * right;	/**< Ukazatel na pravý list stromu */
//} TreeNode;*/
    (void)root;                   //vkladyni do stromu data
    (void)data;
	if(root==NULL) return false;  //test jestli se to podari
	TreeNode*uk=root->root,*prev=NULL;       //ukazatel na tree node 
	/*printf("TreeNode*uk=root->root=%d\n",uk);*/
	
	int cmp=0;                    //pomocna promenna pro funkci,jen pro optimalizaci
	                              // *prev=NULL; ukazatel na posledni bunky
	while(uk!=NULL)
    { //porovnava delkz retezcu,vacsi do prava
		prev=uk;                  //predchadzajuca adresa
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
	/*printf("uk=myMalloc(sizeof(TreeNode));  %d\n",uk);*/
	
	uk->left=uk->right=NULL;  //nasel jsem misto kam to mam vlozit uk==0
	uk->data=data;  //ukladam data ktere nam da uzivatel
	if(prev==NULL)   //vkladani do prazdneho stromu 
	{
     root->root=uk;  //ano´novy uzel bude koren stromu
	/* printf("root->root=uk; %d\n",uk);*/
	 
	} else            //vkladam za existujuci uzel
	{                  //ne =vkladame za existujuci uzel
	if(cmp<0) prev->right=uk;  //jestlize posledni porovnani je <jak nula uloz adresu alokace pamati do prava 
	else prev->left=uk;   // jinak obracene 
	}
	root->itemsCount++;
    return true;
}
/*************************************************************************/
void Data_Print( Data_t * data )
{
    printf( "Jmeno=%s, vek=%0.1lf, vaha=%0.1lf, vyska=%0.1lf\n",
            data->jmeno, data->vek, data->vaha, data->vyska );
}
/***********************************************************************/

int Data_Cmp( const Data_t *d1, const Data_t *d2 )
{
   // return strcmp( d1->jmeno, d2->jmeno );  //porovnava velikost retezcu
if( d1->vek < d2->vek )return  -1;
else if ( d1->vek > d2->vek )return  1;
else if ( d1->vek == d2->vek ) return 0;
else return 2;

}
/**********************************************************************/
//typedef struct _TreeNode {
//    Data_t  data;				/**< Data listu stromu */
 //   struct _TreeNode * left;	/**< Ukazatel na levý list stromu */
 //   struct _TreeNode * right;	/**< Ukazatel na pravý list stromu */
//} TreeNode;*/
 
/*************************************************************************/
void prunik_sjednoceni(Tree * const root,Tree * const root2){
	TreeNode*uk=root->root;
	TreeNode*uk2=root2->root;
	int cmp=0;  
   Data_Print(&uk->data );
  // Data_t * data=&uk->data;  //musim zmenit datovy typ ked chcem zobrazit strukturu
	//printf("vek %lf \n",data->vek);   //a musim priradit adresu dat.typu,pretoze pristupujem k halde
	 
}
int Height(TreeNode * root)
{
int x,y;
if(root==NULL)return 0;
x=Height(root->left);
printf("x %d=\n",x);
y=Height(root->right);
printf("x %d=\n",y);
return x>y?x+1:y+1;
 
}


/*******************************************************************/
int pole[30] = {0};//global pole
int hloubka=0;
/***************************************************************/
 void zpracuj_strom1(TreeNode *uk, int hloubka){
	if (uk != NULL){
		pole[hloubka]++;
		hloubka++;
		printf("hlobka stromu %d \n",hloubka);	
		zpracuj_strom1(uk->left, hloubka);
		zpracuj_strom1(uk->right, hloubka);
	}
	 
}

int maxWidth( Tree *root ){
	int max = 0;
	int loop = 0;
	TreeNode *uk = root->root;
for( loop = 0; loop < 30; loop++) {
pole[loop] = 0;  }
	 zpracuj_strom1(uk, 0);

	for(loop = 0; loop < 30; loop++) {
      if (pole[loop] > max) max = pole[loop]; 
	  printf(" pole %d \n", pole[loop]);  }
	printf(" pocet uzlu %d \n", max);  
	return max;
}
/***************************************************************************/
int main( int argc, char** argv ){
    ( void ) argc; // unsed
    ( void ) argv; // unsed
    printf( "Strom v1.0\n" );
    printf( "----------\n\n" );
    char v;
    Tree tree,tree1,tree2;
	
/*  typedef struct _Tree {
    TreeNode * root;    //ukazatel na zacatek stromu
    unsigned int itemsCount;//pocet položek stromu
} Tree;                       */
	 
    bool initialized = false;
    menu();
    bool running = true;
	 
                          //pokud je running true while porad funguje
    while( running ) {   //pokud je running false while se ukonci
        printf( "Vase volba: " );
        running = io_utils_get_char( &v );//overuje jestli vstup byl zadany spravne,,jestli retezec nebyl moc dlouhy

        if( running ) {   
            printf( "%c\n", v );  //vypise runing pokud je true
        }

        if( ( initialized || v > '9' || v == '1' ) && running ) {//jestli byla zadana spravna volba case,spravne pismeno
            switch( v ) {
/*******************************************************************/	
				case 'q':

                  printf( "vyska stromu stromu:\n" );
                    //Data_t data;
                    initialized=Tree_Init(&tree);
                   
                    
                    for(int i=0;i<LIM;i++){
					Tree_Insert( &tree, datecka[i]); 
					}
		//vyska stromu			
					printf("Height %d \n",Height(tree.root));
     puts("\n  \n");                 
 maxWidth( &tree );
 
 //pocet uzlu na spodnim patru
                 //  puts("\nstrom 1 \n");
                   Tree_Process(tree, process_tree_node, 1);
					// puts("\nstrom 2 \n");
                   // Tree_Process(tree2, process_tree_node, 1);
                   
                 
                   
                    break;
               
/*************************************************************************/					
                    
					
                case '1':
                    if( initialized ) {
                        printf( "Strom jiz byl inicializovan.\n" );
                        break;
                    }
                    // printf("&tree =%d,tre=%d\n",&tree,tree); //
                    initialized = Tree_Init( &tree );

                    if( initialized ) {
                        printf( "Strom byl inicializovan.\n" );
                    } else {
                        printf( "Strom nebyl inicializovan.\n" );
                    }

                    break;

                case '2':
                    Tree_Clear( &tree );
                    printf( "Obsah stromu byl odstranen.\n" );
                    break;

                case '3': {
                    printf( "Data uzlu stromu:\n" );
                    Data_t data;///**< vek, vaha, vyska */
                    running = Data_Get( &data );//nacitani dat a ukladani

                    if( !running ) {
                        continue;
                    }

                    if( !Tree_Insert( &tree, data ) ) {
                        printf( "Zadana hodnota je jiz ve strome obsazena!\n" );
                    }

                    break;
                }

                case '4':
                    printf( "Zadej mazana data:\n" );
                    Data_t data;
                    running = Data_Get( &data );

                    if( !running ) {
                        continue;
                    }

                    Tree_Delete( &tree, data );
                    break;

                case '5': {
                    printf( "Zadej hledana data:\n" );
                    Data_t data;
                    running = Data_Get( &data );

                    if( !running ) {
                        continue;
                    }

                    TreeNode *node = Tree_Find_Node( tree, data );

                    if( node ) {
                        printf( "Data byla nalezena v uzlu\n" );
                    } else {
                        printf( "Data nebyla ve strome nalezena.\n" );
                    }

                    break;
                }

                case '6':
				//zpracuj_strom(tree.root,process_tree_node);
				//zpracuj_strom(tree.root,zvys_vek);
                   Tree_Process(tree,process_tree_node,procINORDER);
				   Tree_Process(tree,zvys_vek,procINORDER);
                    printf( "Pocet uzlu stromu: %ld\n", (long unsigned int)Tree_Get_Count( tree ) );
                    break;

                case '7': {
                    long mode = 0;
                    printf( "Pruchod:\n1 - preorder\n2 - inorder\n3 - postorder\n\nVase volba: " );
                    running = io_utils_get_long( &mode );

                    if( !running ) {
                        continue;
                    }

                    printf( "%ld\n\n", mode );

                    if( mode >= 1 && mode <= 3 ) {
                        Tree_Process( tree, ( TreeNodeProc )process_tree_node, ( TreeProcessMode )mode );
                    } else {
                        printf( "Neznama volba!\n" );
                    }

                    break;
                }

                case 'm':
                case 'M':
                    menu();
                    break;

                case 'k':
                case 'K':
                    running = false;
                    printf( "Konec.\n" );
                    break;

                default:
                    printf( "Neznama volba!\n" );
                    break;
            }
        } else if( !initialized ) {
            printf( "Strom neni inicializovan!\n" );
        }

        printf( "\n" );
    }

    if( initialized ) {
        Tree_Clear( &tree );
    }

    return 0;
}
