#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "maillon.h"

typedef struct emplacement_t {
	int l, c;
	struct emplacement_t *succ;
} Emplacement;

typedef Emplacement *pEmplacement;

typedef struct mot_t {
	pMaillon tete_mot, queue_mot;
	Emplacement_Point tete_liste, queue_liste;
} Mot;