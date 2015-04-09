#include "utils.h"

void displayBinary(Storage n){
	char tmp[SIZE];
	char s[SIZE + (SIZE/5) + 1];
	int i, j;
	if(DEBUG){

		for(int i=0; i<SIZE; i++)
			tmp[i] = '0';

		i =0;
		j = 0;
		while (n) {
	    	if (n & 1)
	        	tmp[SIZE-1-i] = '1';
	    	n >>= 1;
	    	i++;
		}

		for(i=0; i<SIZE; i++){
			if((SIZE == 64 && (i == 4 || (i-4)%(5) == 0)) || (SIZE == 32 && (i == 2 || (i-2)%(5) == 0)) || (SIZE == 16 && (i == 1 || (i-1)%(5) == 0)) || (SIZE == 8 && (i == 3 || (i-3)%(5) == 0))){
				s[j] = '-';
				j++;
			}
			s[j] = tmp[i];
			j++;
		}
		s[SIZE + (SIZE/5)] = '\0';
		printf("%s\n", s);
	}
}

uint8_t char_to_num(char c){
	return c-'a'+1;
}

char num_to_char(uint8_t n){
	return n+'a'-1;
}

void set_charnum(Storage *n, uint8_t k, Storage toAdd){
	Storage mask = 1;
	for(int i=1; i<SIZE; i++)
		mask = mask | (1<<i);
	
	mask = mask << 5;
	for(int i=0; i<(5*(NBL-1-k)); i++)
		mask = (mask << 1) | 1;
	//printf("Origin : \t\t"); displayBinary(*n);
	*n = *n & mask;
	//printf("With mask : \t\t"); displayBinary(*n);
	*n = *n | (toAdd << (5*(NBL-1-k)));
	//printf("With data : \t\t"); displayBinary(*n); printf("\n");
}

uint8_t get_charnum(Storage num, uint8_t k){
	Storage mask = 31;
	//displayBinary(mask<<(5*(NBL-1-k)));
	return (num & (mask<<(5*(NBL-1-k))))>>(5*(NBL-1-k));
}