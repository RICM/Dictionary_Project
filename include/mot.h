#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "maillon.h"

typedef struct emplacement_t {
	int l, c;
	struct emplacement_t *succ;
} Emplacement;

typedef Emplacement *pEmplacement;

typedef struct mot_t {
	pMaillon tete_mot, queue_mot;
	pEmplacement tete_liste, queue_liste;
} Mot;

typedef Mot *pMot;

void add_emplacement(pEmplacement p, int l, int c);

void creer_mot(Mot *mot, char *m, int l, int c);
void print_mot(Mot m);
int compare_mots(Mot m1, Mot m2);