#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node*next;
};
void Print(struct Node*p) {
	if(p==NULL) {
		printf("\n");
		return;    //podminka ukonceni
}
	                      //nejprve vytisknout hodnotu v uzlu
	Print(p->next);  
   printf("%d ",p->data);  //kdys to prohodim s radkem vys ,rekurze nebude//volani rekurze
}

struct Node * Insert(struct Node *head,int data) {
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL) head=temp;
	else {
		struct Node* temp1=head;
		while(temp1->next != NULL) temp1=temp1->next;
		temp1->next=temp;
	}
	return head;
}


int main(int argc, char **argv)
{
	struct Node* head=NULL;
	head=Insert(head,2);
 head=Insert(head,3);
 head=Insert(head,4);
 head=Insert(head,5);
 Print(head);
 puts("\n");
	return 0;
}
