#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mot.h"

typedef struct dictionnaire_t {
	Mot m;
	struct dictionnaire_t *succ;
} Dictionnaire;

typedef Dictionnaire *pDictionnaire;

/** Add a Mot to the head of a Dictionnaire list. */
pDictionnaire add_to_head_dictionnaire(pDictionnaire d, Mot m);

/** Add a Mot to the tail of a Dictionnaire list. */
pDictionnaire add_to_tail_dictionnaire(pDictionnaire d, Mot m);

/** Add a Mot inside a Dictionnaire list. */
pDictionnaire add_inside_dictionnaire(pDictionnaire pred, pDictionnaire succ, Mot m);

/** Add a Mot to a Dictionnaire list. */
pDictionnaire insertion_dictionnaire(pDictionnaire d, char *mot, int l, int c);

/** Display a Dictionnaire list. */
void affichage(pDictionnaire d);

/** Release of the memory used by a Dictionnaire list. */
void freeDictionnaireList(pDictionnaire *d);

/** Display a Dictionnaire list with associated maillons */
void affichageMaillons(pDictionnaire d);
