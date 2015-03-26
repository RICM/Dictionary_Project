#include "struct.h"

#define DEBUG 0

uint8_t char_to_num(char c){
	return c-'a'+1;
}

char num_to_char(uint8_t n){
	return n+'a'-1;
}

void displayBinary(uint32_t n){
	int i=0;
	if(DEBUG){
		while (n) {
	    	if (n & 1)
	        	printf("1");
	    	else
	        	printf("0");

	    	n >>= 1;
	    	i++;
	    	if(i%5 == 0)
	    		printf("-");
		}
		printf("\n");
	}
}

void set_charnum(uint32_t n, uint8_t k, uint8_t toAdd){
	uint32_t mask = 0xFFFFFFFF;
	displayBinary(mask);
	mask = mask << 5;
	for(int i=0; i<(5*(5-k)); i++)
		mask = (mask << 1) | 1; //(5*(5-k));
	displayBinary(mask);

	displayBinary(n);	
	n = n & mask;
	displayBinary(n);
	n = n | (toAdd << (5*(5-k)));
	displayBinary(toAdd);
	displayBinary(toAdd << (5*(5-k)));
	displayBinary(n);
}