#include <stdio.h>
typedef struct Node {
	int data;
	struct Node*next;
};
struct Node* head;

void Reverse(struct Node* p) {
	if(p->next==NULL) {
		head=p;
		return;
	}
Reverse(p->next);
struct Node *q=p->next;
q->next=p;
p->next=NULL;
}

void Print(struct Node*p) {   //reverse print
	if(p==NULL) {
		printf("\n");
		return;    //podminka ukonceni
}
	                      //nejprve vytisknout hodnotu v uzlu
	Print(p->next);  
   printf("%d ",p->data);  //kdys to prohodim s radkem vys ,rekurze nebude//volani rekurze
}


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
