#include "tree.h"
#include <stdlib.h>
#include "mymalloc.h"

bool Tree_Init(Tree* const root)
{
    (void)root;
    if(root == NULL)
        return false;
    root->itemsCount = 0;
    root->root = NULL;
    return true;
}

void Tree_Clear(Tree* const root)
{
    (void)root;
    Tree_Process(*root, (TreeNodeProc)myFree, procPOSTORDER);
    root->itemsCount = 0;
    root->root = NULL;
}

bool Tree_Insert(Tree* const root, const Data_t data)
{
    (void)root;
    (void)data;
    if(root == NULL)
        return false;
    TreeNode *uk = root->root, *prev = NULL;
    int cmp = 0;
    while(uk != NULL) {
        prev = uk;
        cmp = Data_Cmp(&uk->data, &data);
        if(cmp < 0)
            uk = uk->right;
        else if(cmp > 0)
            uk = uk->left;
        else
            uk = uk->right;
            //return true; // data uz ve stromu jsou = koncime
    }
    uk = myMalloc(sizeof(TreeNode));
    uk->left = uk->right = NULL;
    uk->data = data;
    if(prev == NULL) {   // vkladame do prazdneho stromu?
        root->root = uk; // ano = novy uzel bude koren stromu
    } else {             // ne = vkladame za existujici uzel
        if(cmp < 0)
            prev->right = uk;
        else
            prev->left = uk;
    }
    root->itemsCount++;
    return true;
}

void Tree_Delete(Tree* const root, const Data_t data)
{
    (void)root;
    (void)data;
    if(root == NULL)
        return;
    TreeNode *uk = root->root, *prev = NULL;
    int cmp = 0, prev_cmp = 0;
    while(uk != NULL) {
        prev = uk;
        prev_cmp = cmp;
        cmp = Data_Cmp(&uk->data, &data);
        if(cmp < 0)
            uk = uk->right;
        else if(cmp > 0)
            uk = uk->left;
        else { // nasli jsme mazany uzel!!!
            if(uk->left != NULL && uk->right != NULL) {
                // nahrazeni otce nepravejsim uzlem leveho podstromu...
                // domaci ukol!!!
            } else {
                if(uk->left != NULL || uk->right != NULL) {
                    TreeNode* nenulovy;
                    if(uk->left != NULL) nenulovy = uk->left;
                    else nenulovy = uk->right;
                    if(prev == NULL)
                        root->root = nenulovy;
                    else if(prev_cmp > 0)
                        prev->left = nenulovy;
                    else
                        (prev->right = nenulovy);
                } else {
                    if (prev==NULL) root->root = NULL;
                    else
                        if(prev_cmp > 0) prev->left = NULL;
                        else prev->right = NULL;
                }
                myFree(uk);
            }
        }
    }
}

const Data_t* Tree_Get_Data(const TreeNode* const node)
{
    (void)node;
    return &node->data;
}

TreeNode* Tree_Find_Node(Tree root, const Data_t data, TreeNode* ptr_last)
{
    (void)root;
    (void)data;

    TreeNode* uk = root.root;
    if(ptr_last!=NULL)uk = ptr_last->left;
    int cmp = 0;
    while(uk != NULL) {
        cmp = Data_Cmp(&uk->data, &data);
        if(cmp < 0)
            uk = uk->right;
        else if(cmp > 0)
            uk = uk->left;

        else
            return uk; // data ve stromu jsou = vracime ukazatel
    }
    return NULL;
}

size_t Tree_Get_Count(Tree root)
{
    (void)root;
    return root.itemsCount;
}

void zpracuj_strom_inorder(TreeNode* uk, TreeNodeProc user_fn)
{
    if(uk != NULL) {
        zpracuj_strom_inorder(uk->left, user_fn);
        user_fn(uk);
        zpracuj_strom_inorder(uk->right, user_fn);
    }
}
void zpracuj_strom_preorder(TreeNode* uk, TreeNodeProc user_fn)
{
    if(uk != NULL) {
        user_fn(uk);
        zpracuj_strom_preorder(uk->left, user_fn);
        zpracuj_strom_preorder(uk->right, user_fn);
    }
}
void zpracuj_strom_postorder(TreeNode* uk, TreeNodeProc user_fn)
{
    if(uk != NULL) {
        zpracuj_strom_postorder(uk->left, user_fn);
        zpracuj_strom_postorder(uk->right, user_fn);
        user_fn(uk);
    }
}

void Tree_Process(Tree root, TreeNodeProc proc, TreeProcessMode mode)
{
    (void)root;
    (void)proc;
    (void)mode;
    switch(mode) {
    case procPREORDER:
        zpracuj_strom_preorder(root.root, proc);
        break;
    case procINORDER:
        zpracuj_strom_inorder(root.root, proc);
        break;
    case procPOSTORDER:
        zpracuj_strom_postorder(root.root, proc);
        break;
    }
}

int Tree_count_key(Tree root, const Data_t data)
    {
    int i = 0;
    (void)root;
    (void)data;
    TreeNode* uk = root.root;
    int cmp = 0;
    while(uk != NULL) {
        cmp = Data_Cmp(&uk->data, &data);
        //printf("cmp= %d, %s\n",cmp, data.jmeno);
        if(cmp < 0){
            uk = uk->right;

            }
        else if(cmp > 0){
            uk = uk->left;

        }
        else{
            i++;
            uk = uk->left;
            //printf("zvedam %i \n",i);
            // data ve stromu jsou = vracime ukazatel
        }
    }
    return i;
    }
