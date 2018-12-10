#include <stdio.h>

struct squadra
{
	char *nome;
	int punti;
	int golSegnati;
	int golSubiti;

	struct squadra *next;
	struct squadra *prev;
};

void inserisciSquadra(struct squadra **head, char *nome);
void aggiornaDopoPartita(struct squadra **head,char *squadra1, char *squadra2, int gol1, int gol2);
void retrocediUltime(int n);
void stampa();
void aggiornaTutto(struct squadra **head,struct squadra *s);
