#include <stdio.h>
#include <stdlib.h>#
#include <stdbool.h>
/*Jednoduchý program pro vytvoření BST celých čísel a hledání prvku v něm*/

typedef struct BstNode {
int data;
struct BstNode *left;
struct BstNode *right;	
}BstNode;

/*********************************************************************/
//funkce   min v stroum

int *FindMin(BstNode* root) {
	if(root==NULL) {
		printf("Chyba,strom je prazdny\n");
		return -1;
	   }
    
	while(root->left !=NULL)  {
	root=root->left; }
 
 return root->data;

}

/*********************************************************************/
//funkce max  v stroum

int *FindMax(BstNode* root) {
	if(root==NULL) {
		printf("Chyba,strom je prazdny\n");
		return -1;
	   }
    
	while(root->right !=NULL)  {
	root=root->right; 
	printf("root->right =%d\n",root);
	}
 
 return root->data;

}


/*****************************************************************************/
//Funkce pro vytvoření nového uzlu v haldě

BstNode *GetNewNode(int data) {
	printf("\nFunkce vytvor uzel//\n\t BstNode *GetNewNode(int data)    \n");
	
	BstNode *newNode=malloc(sizeof(struct BstNode));//ulozim adresu kde je alokovana pamat
	printf("BstNode *newNode=malloc(sizeof(struct BstNode));\n newNode=%d\n",newNode);
	
	newNode->data=data;                     //na tejto adrese ulozim hodnotu data
	printf("newNode->data=data;\n newNode->data=%d\n",data);
	
	newNode->left=newNode->right=NULL;  //na tejto adrese ulozim levy a pravy ukazatel na dalsi bunku na hodnotu 0;
	printf("newNode->left=newNode->right=NULL;");
	
	printf("return newNode = %d\n\n",newNode);
	return newNode;
	 
}

/****************************************************************************/
//Vložit data do BST, vrátí adresu kořenového uzlu 

BstNode* Insert(BstNode* root,int data)   //funkce vkladani data do stromu
{  
    printf("\nFunkce Insert  vkladani data do stromu//\n\t BstNode* Insert(BstNode* root,int data)\n");
   

	if(root==NULL) {                    //prazdny strom,koren
	root=GetNewNode(data);              //funkce vloz data do korena stromu
	printf("\n\t novy uzel// if(root==NULL) root=GetNewNode(data);\n return root=%d;\n",root);     
    return root;  }
    
	
	
	//Pokud jsou data, která mají být vložena, menší, vložte do levého podstromu. 
	
	else if(data <=root->data) {          //rozhodujem ci budem davat data doleva nebo prava
	printf("\n\tVnorovani v levo//\nelse if(data <=root->data)  root->left=Insert(root->left,data);\n root->left=%d;\n",root->left); 
    root->left=Insert(root->left,data); 
	  }       

    else {                                //jinak vložte pravý podstrom
	printf("\n\tVnorovani v pravo// \n else  root->right=Insert(root->right,data);\n root->right=%d\n",root->right);
    root->right=Insert(root->right,data);//pomoci rekurzese vracim do funkce getnewnode
    }     
	
	 printf("funkce Insert//\nreturn root=%d\n\n",root);
	return root;
}

/***********************************************************************/
//Pro vyhledání elementu v BST vrací true, pokud je prvek nalezen 

bool Search(BstNode* root,int data) 
{
	printf("\n\t funkce   bool\n Search(BstNode* root,int data) {\n");
		printf(" root=%d,int data=%d \n", root,data);
	
	if(root == NULL)  {
		return false;
		printf("funkce Search//\n  if(root == NULL) return false;\n");   }
	
	else if(root->data == data) {
		return true;
		printf("funkce Search//\n  else if(root->data == data)  return true\n;");  }
	
	else if(data <= root->data) {
		return Search(root->left,data);
		 printf("funkce Search//\n  else if(data <= root->data)//return Search(root->left,data); \n;");}
	
	else {
		return Search(root->right,data);
	printf("funkce Search//\n  else return Search(root->right,data);\n ");  }



}

/************************************************************************/
int main()
{
	BstNode *root = NULL;  // deklarace datoveho typu
      printf("BstNode* root = NULL;  root=%d\n\n",root);       
	/*Code to test the logic*/
	root = Insert(root,15);	
	printf("root = Insert(root,15); root=%d\n\n",root);
	root = Insert(root,10);	
	printf("root = Insert(root,10); root=%d\n\n",root);
	root = Insert(root,20);
	printf("root = Insert(root,20); root=%d\n\n",root);
	root = Insert(root,25);
	printf("root = Insert(root,25); root=%d\n\n",root);
	root = Insert(root,8);
	printf("root = Insert(root,8); root=%d\n\n",root);
	root = Insert(root,12);
	printf("root = Insert(root,12); root=%d\n\n",root);
	                                     // Ask user to enter a number.  
	int number;
	printf("Enter number be searched\n");
	scanf("%d",&number);
	                                     //If number is found, print "FOUND"
	if(Search(root,number) == true) printf("nalezen\n");
	else printf("nenalezen\n");
	
	 
	printf("min je %d\n",FindMin(root));
	printf("max je %d\n",FindMax(root));
	return 0;
}