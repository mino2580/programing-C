#include "tree.h"
#include "data.h"
#include "ioutils.h"
#include <stdio.h>

void menu()
{
    printf( "1 - tree_init()\n"
            "2 - tree_clear()\n"
            "3 - tree_insert()\n"
            "4 - tree_delete()\n"
            "5 - tree_find_node()\n"
            "6 - tree_get_node_count()\n"
            "7 - tree_proces()\n"
            "8 - tree_Tree_count_key()\n"
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

int main( int argc, char** argv )
{
    ( void ) argc; // unsed
    ( void ) argv; // unsed
    printf( "Strom v1.0\n" );
    printf( "----------\n\n" );
    char v;
    Tree tree = {NULL, 0};
    bool initialized = false;
    menu();
    bool running = true;

    while( running ) {
        printf( "Vase volba: " );
        running = io_utils_get_char( &v );

        if( running ) {
            printf( "%c\n", v );
        }

        if( ( initialized || v > '9' || v == '1' ) && running ) {
            switch( v ) {
                case '1':
                    if( initialized ) {
                        printf( "Strom jiz byl inicializovan.\n" );
                        break;
                    }

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
                    Data_t data;
                    running = Data_Get( &data );

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
                    TreeNode * ptr_last = NULL;
                    TreeNode *node = Tree_Find_Node( tree, data, ptr_last);

                    if( node ) {
                        printf( "Data byla nalezena v uzlu\n" );
                    } else {
                        printf( "Data nebyla ve strome nalezena.\n" );
                    }

                    break;
                }

                case '6':
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

                case '8':

                    //Data_t data;
                    running = Data_Get( &data );

                    if( !running ) {
                        continue;
                    }
                    int j = 0;//, i = 0;
                    //bool a=true;
                    //while(a==true){
                    j = Tree_count_key(tree, data);


                    if( j>0 ) {
                        printf( "Data byla nalezena v uzlu, jejich vyskyt je: %i\n", j+1 );
                    } else {
                        printf( "Data nebyla ve strome nalezena.\n" );
                    }

                    break;


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
