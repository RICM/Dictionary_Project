#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEBUG 1

void displayBinary(uint32_t n);

uint8_t char_to_num(char c);
char num_to_char(uint8_t n);

void set_charnum(uint32_t *n, uint8_t k, uint8_t toAdd);
uint8_t get_charnum(uint32_t n, uint8_t k);