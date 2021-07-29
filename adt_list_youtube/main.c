#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;                                   //data v pametove bunke
	struct Node *next;                          //ukazatel na strukturu uzel
};

struct Node *head;                              //globální proměnné, lze k nim přistupovat kdekoli

void Insert(int x) {
	                                           // printf("\n\tvoid Insert(int x) {\n");
struct Node* temp=  malloc(sizeof(struct Node));//malloc vraci ukaazatel na zacatek pametoveho modulu 
                                               // printf("struct Node* temp=  malloc(sizeof(struct Node));\n");
												//printf("                                 *temp= %d \n",*temp);
							
					//printf("                                 temp= %d \n",temp);
temp->data=x;
												//printf("temp->data=x;                    temp->data= %d\n",temp->data);
temp->next=head;
                                                //printf("temp->next=head;                 temp->next= %d\n",temp->next);
head=temp;
                                                //printf("head=temp;                       head= %d\n",head);
}

void Print() {
	                                            //printf("\n\tvoid Print() {\n" );
 
	struct Node *temp=head;
	
	                                           // printf("struct Node *temp=head;\n");
	                                           // printf("                                   *temp= %d\n",*temp );
												//printf("                                   temp=%d\n",temp);
	printf(" List je: \n");
	while(temp!=NULL) {
		                                        //printf("while(temp!=NULL) {\n");
		printf(" temp->data= %d;",temp->data);
		temp=temp->next;
		                                       // printf("\ntemp=temp->next;                 temp= %d,",temp);
	}
	
printf("\n");

}


int main()
{
	head=NULL;//empty list
	printf("zadaj pocet cisel\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
	    printf("Zadej cisla \n");
	    scanf("%d",&x);
		Insert(x);//funkce pro vkladani prvku
		Print();
	}
	
	return 0;
}
