 
#include "mymalloc.h"
#include <stdbool.h> 
#include "tree.h"
#include "data.h"
#include "ioutils.h"
#include <stdio.h>
#include <stdlib.h>
#define LIM 10


bool byl=true;


bool Tree_Init(Tree * const root)
{
    (void)root;
    if(root==NULL) return false;
    root->root=NULL;
    root->itemsCount=0;
    return true;
}

void Tree_Clear(Tree * const root)
{
    (void)root;
    Tree_Process(*root,(TreeNodeProc)myFree, procPOSTORDER);
    root->itemsCount=0;
    root->root=NULL;
}

bool Tree_Insert(Tree * const root, const Data_t data)
{
    (void)root;
    (void)data;
    (void)root;
    (void)data;
    if(root==NULL) return false;
    TreeNode *uk=root->root, *prev=NULL;
    int cmp=0;
    while(uk!=NULL){
        prev=uk;
        cmp=Data_Cmp(&uk->data,&data);
        if(cmp<0)
            uk=uk->right;
        else if(cmp>0)
            uk=uk->left;
            else return false;
    }
    uk=myMalloc(sizeof(TreeNode));
    uk->left=uk->right=NULL;
    uk->data=data;
    if(prev==NULL)
        root->root=uk;
    else{
        if(cmp<0) prev->right=uk;
        else if(cmp>0) prev->left=uk;
    }
    root->itemsCount++;
    return true;
}

void Tree_Delete(TreeNode** root, const Data_t data)
{
    (void)root;
    (void)data;
    (void)root;
    (void)data;
    if(root==NULL) return false;
    TreeNode *uk=*root, *prev=NULL;
    int cmp, pre_cmp;
    while(uk!=NULL){
        pre_cmp=cmp;
        cmp=Data_Cmp(&uk->data,&data);
        if(cmp<0){
            prev=uk;
            uk=uk->right;
        }
        else if(cmp>0){
            prev=uk;
            uk=uk->left;
        }
            else {
                puts("nasel se");
                if(uk->left != NULL && uk->right != NULL){
                    prev=uk;
                    TreeNode *pred;
                    pred=uk;
                    uk=uk->left;
                    while(uk->right != NULL){
                        pred=uk;
                        uk=uk->right;
                    }
                    prev->data=uk->data;
                    if(uk->left != NULL){
                        if(pred->right==uk)
                            pred->right=uk->left;
                        else if(pred->left==uk)
                                pred->left=uk->left;
                        myFree(uk);
                        return;
                    }else {
                        if(pred->left==uk)
                            pred->left=NULL;
                        else if(pred->right==uk)
                                pred->right=NULL;
                    myFree(uk);
                    return;
                    }
                }else {
                    if(uk->left != NULL ||  uk->right != NULL){
                        TreeNode *pom;
                        if(uk->left != NULL)
                            pom=uk->left;
                        else pom=uk->right;
                        if(pre_cmp<0)
                            prev->right=pom;
                        else prev->left=pom;
                    myFree(uk);
                    return;
                    }else {
                        if(prev==NULL){
                            //root->root=NULL;
                            *root=NULL;
                        }
                        else if(pre_cmp<0)
                                prev->right=NULL;
                             else prev->left=NULL;
                    myFree(uk);
                    return;
                    }
                }
            }
    }
}

void pruchod(TreeNode* tre1, TreeNode* tre2, char ch, TreeNode** prvni){
    if(tre1!=NULL){
        pruchod(tre1->left, tre2, ch, prvni);
        pruchod(tre1->right, tre2, ch, prvni);
        switch(ch){                                                         
            case 'p': if((Tree_Find_Node(tre2, tre1->data))==NULL)
                        Tree_Delete(prvni, tre1->data);
            break;
            case 's': puts("sjednoceni, zatim nemam :D");
            break;
        }
    }
}
void prunik_sjednoceni(TreeNode **tre1, TreeNode **tre2){
    puts("PRO PRUNIK ZADEJ p\nPRO SJEDNOCENI s");
    char znak=getchar();
    pruchod(*tre1, *tre2, znak, tre1);
    getchar();
}


/*void rozdil(TreeNode **tre1, TreeNode **tre2){
    Data_t* uk;
    int pocet=0;
    uk=travel(*tre1, *tre2, &pocet);
    for(int i=0;i<pocet;i++){
        Tree_Delete(*tre1,uk[i]);
    }
}*/

bool isEmpty(Stack *s){
    
    return (s==NULL) ? 1 : 0;
}

void push(Stack **s, TreeNode *node){
    Stack *novy=(Stack*)malloc(sizeof(Stack));
    novy->t=node;
    novy->next=(*s);
    (*s)=novy;
}

TreeNode* pop(Stack **s){
    if(!isEmpty(*s)){
        TreeNode *pom=(*s)->t;
        Stack *mazany=*s;
        *s=(*s)->next;
        free(mazany);
        return pom;
    }else 
        puts("je prazdno");
        return NULL;
}

Data_t* travel(TreeNode* node, TreeNode* rot, int* n){
    TreeNode *cur=node;
    Stack *st=NULL;
    bool done=false;
    //int pocet=Tree_Get_Count(node);
    Data_t* mazane=(Data_t*)malloc(sizeof(Data_t)*LIM);
    int m=0;
    while(!done){
        if(cur!=NULL){
            push(&st, cur);
            cur=cur->left;
        }else {
            if(!isEmpty(st)){
                cur=pop(&st);
                TreeNode *nalezen=Tree_Find_Node(rot,cur->data);
                if(nalezen!=NULL)
                    mazane[m++]=cur->data;
                cur=cur->right;
            }else done=true;
        }
    }
    *n=m;
    return mazane;
}

const Data_t *Tree_Get_Data(const TreeNode * const node)
{
    (void)node;
    if(node==NULL) return NULL;
    return &node->data;
}

TreeNode *Tree_Find_Node(TreeNode* root, const Data_t data)
{
    (void)root;
    (void)data;
    if(root==NULL) return NULL;
    TreeNode *pt=root;
    while(pt!=NULL){
        int cmp=Data_Cmp(&pt->data, &data);
        if(cmp<0)
            pt=pt->right;
        else if(cmp>0)
                pt=pt->left;
             else return pt;
    }
    return NULL;
}

size_t Tree_Get_Count(Tree root)
{
    (void)root;
    return root.itemsCount;
}

void Tree_Process(Tree root, TreeNodeProc proc, TreeProcessMode mode)
{
    (void)root;
    (void)proc;
    (void)mode;
    switch(mode){
        case procPOSTORDER: pos_order(root.root, proc);
        break;
        case procINORDER: in_order(root.root, proc);
        break;
        case procPREORDER: pre_order(root.root, proc);
        break;
        default: puts("default");
        break;
    }
}



void pre_order(TreeNode *pt, TreeNodeProc user_fn){ 
    
    if(pt!=NULL){
        user_fn(pt);
        pre_order(pt->left, user_fn);
        pre_order(pt->right, user_fn);
    }
}

void in_order(TreeNode *pt, TreeNodeProc user_fn){
    if(pt!=NULL){
        in_order(pt->left,user_fn);
        user_fn(pt);
        in_order(pt->right,user_fn);
    }
}

void pos_order(TreeNode *pt, TreeNodeProc user_fn){
    if(pt!=NULL){
        pos_order(pt->left,user_fn);
        pos_order(pt->right,user_fn);
        user_fn(pt);
    }
}

/*TreeNode* FindMin(TreeNode* node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}*/



/*
void pruchod(TreeNode** tre1, TreeNode* tre2, char ch, TreeNode* prvni){
    TreeNode* pt=*tre1;
    if(pt!=NULL){
        pruchod(&pt->left, tre2, ch, prvni);
        pruchod(&pt->right, tre2, ch, prvni);
        switch(ch){                                                         
            case 'p': if((Tree_Find_Node(tre2, pt->data))==NULL)
                        Tree_Delete(&prvni, pt->data);
            break;
            case 's': puts("sjednoceni, zatim nemam :D");
            break;
        }
    }
}
void prunik_sjednoceni(TreeNode **tre1, TreeNode **tre2){
    puts("PRO PRUNIK ZADEJ p\nPRO SJEDNOCENI s");
    char znak=getchar();
    pruchod(&(*tre1), *tre2, znak, *tre1);
    getchar();
}
*/


