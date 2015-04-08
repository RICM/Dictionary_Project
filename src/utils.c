#include "utils.h"

void displayBinary(uint32_t n){
	char s[39];
	int i=0;
	if(DEBUG){
		for(int i=0; i<38; i++)
			s[i] = '0';
		s[38] = '\0';

		while (n) {
	    	if (n & 1)
	        	s[37-i] = '1';
	    	n >>= 1;
	    	i++;
		}
		s[0] = s[6];
		s[1] = s[7];
		s[2] = '-';
		for(int i=8; i<13; i++)
			s[i-5] = s[i];
		s[8] = '-';
		for(int i=13; i<18; i++)
			s[i-4] = s[i];
		s[14] = '-';
		for(int i=18; i<23; i++)
			s[i-3] = s[i];
		s[20] = '-';
		for(int i=23; i<28; i++)
			s[i-2] = s[i];
		s[26] = '-';
		for(int i=28; i<33; i++)
			s[i-1] = s[i];
		s[32] = '-';
		printf("%s\n", s);
	}
}

uint8_t char_to_num(char c){
	return c-'a'+1;
}

char num_to_char(uint8_t n){
	return n+'a'-1;
}

void set_charnum(Storage *n, uint8_t k, uint8_t toAdd){
	Storage mask = 1;
	for(int i=1; i<SIZE; i++)
		mask = mask | (1<<i);
	
	mask = mask << 5;
	for(int i=0; i<(5*(5-k)); i++)
		mask = (mask << 1) | 1;
	*n = *n & mask;
	*n = *n | (toAdd << (5*(5-k)));
}

uint8_t get_charnum(Storage num, uint8_t k){
	return (num & (31<<(5*(5-k))))>>(5*(5-k));
}