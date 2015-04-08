#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEBUG 1
#define SIZE 32

#if SIZE == 32
	typedef uint32_t Storage;
	#define NBL 6
#elif SIZE == 16
	typedef uint16_t Storage;
	#define NBL 3
#elif SIZE == 8
	typedef uint8_t Storage;
	#define NBL 1
#else
	typedef uint32_t Storage;
	#define NBL 6
#endif

void displayBinary(uint32_t n);

uint8_t char_to_num(char c);
char num_to_char(uint8_t n);

void set_charnum(Storage *n, uint8_t k, uint8_t toAdd);
uint8_t get_charnum(Storage n, uint8_t k);