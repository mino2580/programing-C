#include <stdio.h>
#include <stdlib.h>
//vlozte uzel na ntu pozici
struct Node {
	int data;
	struct Node *next;
};
struct Node *head;

void Insert(int data,int n)  {
	                                                // puts("\n\tvoid Insert(int data,int n){\n");	
struct Node*temp1=(struct Node*)malloc(sizeof(struct Node*));	
// do *temp1 sa ulozi ukazatel ,ktery ukazuje na adresu,kde je alokovana pamat-halda 
                                                    //  puts("struct Node*temp1=(struct Node*)malloc(sizeof(struct Node*));");
												     //	printf("// ukazatel na alokovanu pamet *temp1,                 *temp1= %d\n",*temp1);
                                                      //   printf("// adresa temp1,                                       temp1= %d\n\n", temp1);	
temp1->data=data;
temp1->next=NULL;
                                                      //  printf("temp1->data=data;  // hodnota v bunke struktury data// temp1->data= %d\n ", temp1->data);
                                                      //  puts("temp1->next=NULL; //ulozena adresa v bunke struktury next,ukazatel na dalsi bunku v pamati");
                                                       //  printf("                                                       temp1->next= %d\n\n ",temp1->next);
if(n==1) {  
	temp1->next=head;
	head=temp1;
//do head sa ulozi adresa temp1,na ktorej je ulozena adresa alokovanej pamati bunky
                                                     //  puts("if(n==1) {");
                                                     //  puts("temp1->next=head;  //if(n==1) do temp1 ulozim adresu na ktorej je ulozena hlava");
                                                       //  puts("head=temp1;       //if(n==1) do hlavy ulozim ukazatel kteri ukazuje na pamat bunky");
												     //	printf("                                                      temp1->next= %d\n",temp1->next);
                                                     //   printf("                                                      head= %d\n",head);
                                                     //   puts("return;}\n");
	  return ;                                       //vratise k hlavni metode
        }

struct Node *temp2=head;
                                                //   puts(" struct Node *temp2=head;");
												 //  printf("// adresa predchadzajucej bunky                       *temp2= %d\n",*temp2);
                                                 //  printf("/ /adresa temp2                                       temp2= %d\n\n", temp2);

for(int i=0;i<n-2;i++) {
	temp2=temp2->next;
                                                 //  printf("for(int i=0;i<n-2;i++){\n");
                                                 //  printf("temp2=temp2->next;}                                   temp2 je %d\n",temp2);
   }

temp1->next=temp2->next;
temp2->next=temp1;
                                             //     printf("temp1->next=temp2->next;                              temp1->next= %d\n ",temp1->next);
                                              //    printf("temp2->next=temp1;                                    temp2->next= %d\n ",temp2->next);
}

void Print(){
	
	struct Node*temp=head;
												// puts("struct Node*temp=head;");
	
	while(temp!=NULL) {
		                                      //   puts("while(temp!=NULL) {");
		printf("%d ",temp->data);
		temp=temp->next; 
		                                      //  printf("temp=temp->next;            //                          temp= %d\n ",temp);
		
	}
	printf("\n");
}

int main()
{
head=NULL;
	 Insert(1,1);
	 Insert(2,2);
	 Insert(3,3);
	 Insert(4,4);
	 Insert(4,4);
	 Print();
	return 0;
}
