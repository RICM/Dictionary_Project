#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dictionnaire_t {
	Mot m;
	struct dictionnaire_t *succ;
} Dictionnaire;

typedef Dictionnaire *pDictionnaire;

void insertion_dictionnaire(pDictionnaire d, char *mot, int l, int c);
void affichage(pDictionnaire d);
