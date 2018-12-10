#include <stdio.h>
#include <stdlib.h>


struct node
{
	int value;
	struct node *next;
       	struct node *prev;	
};


struct node *insertAfter(struct node **head_ptr, struct node *nodo, int value )
{
	// alloco nuovo nodo 
	struct node *new_node = malloc(sizeof(struct node));
	new_node->value = value;
	
	
	// caso inserisci in lista vuota
	if(*head_ptr == NULL)
	{	
		*head_ptr = new_node;
		return new_node;
	}

	// caso inserisci in testa lista piena
	if(nodo == NULL)
	{		
		new_node->prev = NULL;
		
		(*head_ptr)->prev = new_node;
		new_node->next = *head_ptr;

		*head_ptr = new_node;

		return new_node;
	}
	printf("dio\n");
	// caso inserisci in mezzo
	new_node->next = nodo->next;
	new_node->prev = nodo;
	
	if(nodo->next != NULL)
	{
		nodo->next->prev = new_node;
	}
	nodo->next = new_node;
	return new_node;
	
}

void deleteNode(struct node **head, struct node *nodo)
{
	// caso elimino testa
	if(nodo->prev == NULL)
	{
		(*head)->next = nodo->next;
		*head = nodo->next;
		nodo->next->prev = NULL;
		
		free(nodo);
		return;
	}
	
	// caso elimino in mezzo
	nodo->prev->next = nodo->next;
	nodo->next->prev = nodo->prev;
	free(nodo);
}

void printList(struct node *head)
{

	struct node *n = head;
	while(n != NULL)
	{
		printf("%d\n",n->value);
		n = n->next;
	}
}


void inverti(struct node **head){
	struct node *n = *head;

	while(n != NULL){
		printf("%d\n", n->value);
		n = n->next;
	}
}


int main()
{
	struct node *head = NULL;
	struct node *n1 = insertAfter(&head, NULL ,1);
	struct node *n_new = insertAfter(&head, n1, 88);
	struct node *n2 = insertAfter(&head, NULL, 2);
	struct node *n3 = insertAfter(&head, NULL, 3);
	
	deleteNode(&head, n2);
	deleteNode(&head, n3);

	printList(head);

	printf("\nINVERTI LISTA...\n");

	inverti(&head);
}
