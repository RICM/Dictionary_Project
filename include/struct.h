#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct maillon_t {
	uint32_t maille;
	struct maillon_t *succ;
} Maillon;

typedef Maillon *pMaillon;

typedef struct emplacement_t {
	int l, c;
	struct emplacement_t *succ;
} Emplacement;

typedef Emplacement *pEmplacement;

typedef struct mot_t {
	pMaillon tete_mot, queue_mot;
	Emplacement_Point tete_liste, queue_liste;
} Mot;

uint8_t char_to_num(char c);
char num_to_char(uint8_t n);

void set_charnum(uint32_t *n, uint8_t k, uint8_t toAdd);
uint8_t get_charnum(uint32_t n, uint8_t k);

void print_Maillon(pMaillon list);
pMaillon string_to_maillon(char *s);
void maillon_to_string(pMaillon list, char *str);