#include "tree.h"
#include "data.h"
#include "ioutils.h"
#include <stdio.h>

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

//void prunik()




int main( int argc, char** argv ){
    ( void ) argc; // unsed
    ( void ) argv; // unsed
    printf( "Strom v1.0\n" );
    printf( "----------\n\n" );
    char v;
    Tree tree = {NULL, 0};
	 
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
				
				case 'q':
                    
					
					
					
					
					
                    break;
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
