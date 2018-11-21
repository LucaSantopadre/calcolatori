#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};



void append(int new_value, struct node **head){
	struct node *new_node = malloc(sizeof(struct node));
	if(new_node ==NULL){
		printf("memoria piena\n");
		exit(1);
	}

	
	new_node->value = new_value;
	new_node->next  = NULL;

	
	// lista vuota
	if(*head == NULL){

		printf("head:   %p\n",head);
		printf("*head:  %p\n",*head);
		
		*head = new_node;
		
		return;
	}
	
	struct node *n= *head;
	
	// scorro nodi fino all'ultimo
	while(n->next != NULL){
		n= n->next;
	}

	n->next = new_node;


}


void print_list(struct node *head){
	struct node *n;	// nodo di appoggio per stampare
	
	n= head;     
	printf("---start list---\n");

	printf("value:    %d\n",n->value);
	while(n->next != NULL){
		n= n->next;
		printf("value:    %d\n",n->value);
	}
	
	
	printf("---end list---\n");
}



// x = elemento da eliminare nella lista x={0....n-1}
void delete(struct node *head,int x){
	struct node *n = head;
	int i = 0;

	// n = nodo prima di quello da eliminare
	while(n->next != NULL && i<x-1){
		n = n->next;
		i++;
	}
	printf("val n:   %d\n",n->value);

	// i = n  => delete last
	if(n->next->next == NULL){
		printf("AAAAAAAAAA\n");
		n->next=NULL;
		return;
	}
	// --------------------
	
	// i = 0  => delete head
	if(x==0){
		n = NULL;
		return;
	}

	printf("nodo prima: %d\n",n->value);
	struct node *temp = n;
	printf("nodo eliminare: %d\n",n->next->value);	
	printf("nodo nuovo da puntare:    %d\n",n->next->next->value);

	n->next = temp->next->next;


	
	// i =0   => delete head

	
	// 0 < i < n   => delete intermediate
}



int main(){
	struct node *head = NULL;

	printf("head:   %p\n",head);
	printf("&head:  %p\n",&head);
	printf("append(100,&head)...  \n\n\n"); 
	append(100,&head);
	append(200,&head);
	append(300,&head);
	append(400,&head);

	printf("\n\nritorno da append\n");
	printf("head:   %p\n",head);
        printf("&head:  %p\n",&head);

	
	print_list(head);
	delete(head, 0);
	print_list(head);
}
