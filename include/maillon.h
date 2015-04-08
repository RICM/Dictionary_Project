#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"

typedef struct maillon_t {
	Storage maille;
	struct maillon_t *succ;
} Maillon;

typedef Maillon *pMaillon;

void print_Maillon(pMaillon list);
int length(pMaillon list);

pMaillon add_to_tail(pMaillon list, Storage elem);
pMaillon string_to_maillon(char *s);
void maillon_to_string(pMaillon list, char *str);