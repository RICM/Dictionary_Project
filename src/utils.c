#include "utils.h"

/** Display a split binary representation of n. */
void displayBinary(Storage n){
	char tmp[SIZE];
	char s[SIZE + (SIZE/5) + 1];
	int i, j;

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
		if((SIZE == 64 && (i == 4 || (i-4)%(5) == 0)) 
			|| (SIZE == 32 && (i == 2 || (i-2)%(5) == 0)) 
			|| (SIZE == 16 && (i == 1 || (i-1)%(5) == 0)) 
			|| (SIZE == 8 && (i == 3 || (i-3)%(5) == 0))){
			s[j] = '-';
			j++;
		}
		s[j] = tmp[i];
		j++;
	}
	s[SIZE + (SIZE/5)] = '\0';
	printf("%s\n", s);
}

/** Convert a character into its place in the alphabet. */
uint8_t char_to_num(char c){
	return c-'a'+1;
}

/** Convert a number into the character which is at the 
	place indicated by n in the alphabet. */
char num_to_char(uint8_t n){
	return n+'a'-1;
}

/** Write a character inside a container n. */
void set_charnum(Storage *n, uint8_t k, Storage toAdd){
	Storage mask = 31;
	*n &= ~(mask) << (5*(NBL-1-k));
	if(DEBUG){
		printf("With mask : \t\t"); displayBinary(*n);
	}
	*n |= (toAdd << (5*(NBL-1-k)));
	if(DEBUG){printf("With data : \t\t"); displayBinary(*n); printf("\n");}
}

/** Read a character at the place k inside a container n. */
uint8_t get_charnum(Storage num, uint8_t k){
	Storage mask = 31;
	return (num & (mask<<(5*(NBL-1-k))))>>(5*(NBL-1-k));
}