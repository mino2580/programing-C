#include "tree.h"
#include "data.h"
#include "ioutils.h"
#include <stdio.h>
#include <stdlib.h>
#define LIM 10


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

void ukaz(TreeNode *pt){
    process_tree_node(pt);
}


int main( int argc, char** argv )
{
    ( void ) argc; // unsed
    ( void ) argv; // unsed
    printf( "Strom v1.0\n" );
    printf( "----------\n\n" );
    
    
    
    Data_t datecka[LIM]={
        {"praha",1,1,1},
        {"bojkovice",2,2,2},
        {"pitin",3,8,8},
        {"brno",4,5,5},
        {"ujezdec",5,45,45},
        {"zlin",6,87,87},
        {"moskva",7,1,1},
        {"viden",8,4,6},
        {"kombajn",9,2,3},
        {"martin",10,5,7}
    };
    
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
        {"moskva",18,1,7}
    };
    
    
    
    
    char v;
    Tree tree={NULL, 0};
    Tree tree2={NULL, 0};
    
    
    bool initialized = true;
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

                    //initialized = Tree_Init( &tree );         //zpet
                    //initialized = Tree_Init( &tree2 );        //moje

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
                    //Data_t data;
                    initialized=Tree_Init(&tree);
                    initialized = Tree_Init(&tree2);        //moje
                    //running = Data_Get( &data );
                    for(int i=0;i<LIM;i++){
                       if( !Tree_Insert( &tree, datecka[i] ) ) 
                        printf( "Zadana hodnota je jiz ve strome obsazena!\n" );
                       if( !Tree_Insert( &tree2, datecka2[i] ) ) 
                        printf( "Zadana hodnota je jiz ve strome obsazena!\n" );
                    }
                    
                    //uk=travel(tree, tree2);     //LOL funguje to
                    
                    puts("pred provedenim");
                    Tree_Process(tree, process_tree_node, 1);
                    
                    //rozdil(&tree.root, &tree2.root);
                    prunik_sjednoceni(&tree.root, &tree2.root);
                    puts("POPOPO");
                    Tree_Process(tree, process_tree_node, 1);
                    
                    /*if( !running ) {
                        continue;
                    }

                    if( !Tree_Insert( &tree, data ) ) {
                        printf( "Zadana hodnota je jiz ve strome obsazena!\n" );
                    }*/

                    break;
                }

                case '4':
                    printf( "Zadej mazana data:\n" );
                    Data_t data;
                    running = Data_Get( &data );

                    if( !running ) {
                        continue;
                    }

                    //Tree_Delete( &tree, data );
                    break;

                case '5': {
                    printf( "Zadej hledana data:\n" );
                    Data_t data;
                    running = Data_Get( &data );

                    if( !running ) {
                        continue;
                    }

                    //TreeNode *node = Tree_Find_Node( tree, data );

                    /*if( node ) {
                        printf( "Data byla nalezena v uzlu\n" );
                    } else {
                        printf( "Data nebyla ve strome nalezena.\n" );
                    }*/

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
                        //Tree_Process( tree, ( TreeNodeProc )process_tree_node, ( TreeProcessMode )mode );
                        puts("TOTO JE PRVNI STROM ");
                        Tree_Process(tree, process_tree_node, mode);
                        
                        puts("*****");
                        puts("*****");
                        puts("*****");
                        puts("*****");
                        puts("toto je druhy");
                        Tree_Process(tree2, process_tree_node, mode);
                        //ukaz(&tree.root);
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
