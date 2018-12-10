#include <stdio.h>
#include <stdlib.h>
#include "classifica.h"
#include <string.h>


int main(){
	struct squadra *testa = NULL;
	inserisciSquadra(&testa, "sassuolo");
	inserisciSquadra(&testa, "cagliari");
	inserisciSquadra(&testa, "baridiod");
	inserisciSquadra(&testa, "leccedio");
	inserisciSquadra(&testa, "salernitana");

	struct squadra *i = testa;
	while(i != NULL)
	{
		printf("%s\t\t",i->nome);
		printf("%d\t",i->punti);
		printf("%d\t",i->golSegnati);
		printf("%d\n",i->golSubiti);
		i = i->next;
	}
	printf("aggiorna....\n");
	aggiornaDopoPartita(&testa, "baridiod", "leccedio", 3, 3);
	//aggiornaDopoPartita(&testa, "sassuolo", "leccedio", 3, 1);
	//aggiornaDopoPartita(&testa, "salernitana", "cagliari", 4, 7);

	i = testa;
	while(i != NULL)
	{
		printf("%s\t\t",i->nome);
		printf("%d\t",i->punti);
		printf("%d\t",i->golSegnati);
		printf("%d\n",i->golSubiti);
		i = i->next;
	}
}


void inserisciSquadra(struct squadra **head,char *nome)
{
	struct squadra *new_squadra = malloc(sizeof(struct squadra));
	new_squadra->nome = nome;
	new_squadra->punti = 0;
	new_squadra->golSegnati = 0;
	new_squadra->golSubiti = 0;
	new_squadra->next = NULL;

	// inserisco prima squadra
	if(*head == NULL)
	{
		new_squadra->prev = NULL;
		*head = new_squadra;
		return;
	}

	// itero fino alla fine della classifica e inserisco
	struct squadra *i = *head;
	while(i != NULL)
	{
		if(i->next == NULL)
		{
			break;
		}
		i = i->next;
	}
	i->next = new_squadra;
	new_squadra->prev = i;
	
}

void aggiornaDopoPartita(struct squadra **head,char *squadra1, char *squadra2, int gol1, int gol2)
{
	struct squadra *s1 = malloc(sizeof(struct squadra));
	struct squadra *s2 = malloc(sizeof(struct squadra));
	// itero fino alla fine per trovare le squadre
	struct squadra *s = *head;
	while(s != NULL)
	{
		if(s->nome == squadra1)
		{
			s1 = s;
		}
		if(s->nome == squadra2)
		{
			s2 = s;
		}
		s = s->next;
	}
	// adesso ho s1 = struttura squadra 1       s2 = struttura squadra 2
	if(gol1 > gol2)
	{
		s1->punti = s1->punti + 3;
		s1->golSegnati = s1->golSegnati + gol1;
		s1->golSubiti = s1->golSubiti + gol2;

		s2->golSegnati = s2->golSegnati + gol2;
		s2->golSubiti = s2->golSubiti +gol1;
	}


	if(gol1 < gol2)
	{
		s2->punti = s2->punti + 3;
		s1->golSegnati = s1->golSegnati + gol1;
		s1->golSubiti = s1->golSubiti + gol2;

		s2->golSegnati = s2->golSegnati + gol2;
		s2->golSubiti = s2->golSubiti +gol1;
	}


	if(gol1 == gol2)
	{
		s1->punti = s1->punti + 1;
		s2->punti = s2->punti + 1;
		
		s1->golSegnati = s1->golSegnati + gol1;
		s1->golSubiti = s1->golSubiti + gol2;

		s2->golSegnati = s2->golSegnati + gol2;
		s2->golSubiti = s2->golSubiti +gol1;
	}

	aggiornaTutto(head,s1);
	printf("s2-nome%s\n",s2->nome);
	aggiornaTutto(head,s2);
}


void aggiornaTutto(struct squadra **head,struct squadra *s)
{
	if(s->prev != NULL){
	
	printf("s2-prev%s\n",s->prev->nome);
	}

	// caso base
	if(s->prev == NULL)
	{
		*head = s;
		return; // è gia prima in classifica
	}
	if(s->next == NULL && s->prev->punti == s->punti)
	{
		return; // ultima rimane ultima
	}
	
	if(s->punti == s->prev->punti)
	{
		return; // squadra in pos giusta
	}
	
	
	if(s->punti > s->prev->punti)
	{
		// scambia prev con s
		//struct squadra *x = malloc(sizeof(struct squadra));
		//x = s->prev;
		printf("SCAMBIAAA  s %s\n",s->nome);
		printf("SCAMBIAAA  s prev = x  %s\n",s->prev->nome);
		printf("SCAMBIAAA  s next  %s\n",s->next->nome);
		
		s->prev->next = s->next;
		s->next->prev = s->prev;

		s->next = s->prev;
		s->prev = s;

		s->prev = s->prev->prev;
		s->prev->prev = s;

		

		aggiornaTutto(head,s->prev);
	}
}



