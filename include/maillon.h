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

/** Display a maillon in a binary rapresentation. */
void print_maillon(pMaillon list);

/** Get the length of a Maillon list. */
int length(pMaillon list);

/** Add a Maillon to the tail of a Maillon list. */
pMaillon add_to_tail(pMaillon list, Storage elem);

/** Convert a string into a Maillon list. */
pMaillon string_to_maillon(char *s);

/** Convert a Maillon list into a string. */
void maillon_to_string(pMaillon list, char *str);