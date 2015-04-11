#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** Display a split binary representation of n. */
void displayBinary(Storage n);

/** Convert a character into its place in the alphabet. */
uint8_t char_to_num(char c);

/** Convert a number into the character which is at the 
	place indicated by n in the alphabet. */
char num_to_char(uint8_t n);

/** Write a character inside a container n. */
void set_charnum(Storage *n, uint8_t k, Storage toAdd);

/** Read a character at the place k inside a container n. */
uint8_t get_charnum(Storage n, uint8_t k);