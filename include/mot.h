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

/** Add an Emplacement to the tail of a Emplacement list. */
pEmplacement add_emplacement(pEmplacement p, pEmplacement p2);

/** Add an Emplacement to a Mot. */
Mot add_emplacement_mot(Mot m, int l, int c);

/** Release of the memory used by a Emplacement list. */
void freeEmplacementList(pEmplacement *emp);

/** Create a Mot with a string, and an intial Emplacement. */
void creer_mot(Mot *mot, char *m, int l, int c);

/** Display a mot in a string representation. */
void print_mot(Mot m);

/** Compare two Mots. */
int compare_mots(Mot m1, Mot m2);

/** Release of the memory used by a Mot. */
void freeMot(Mot *m);