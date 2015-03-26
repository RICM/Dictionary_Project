#include "struct.h"

#define DEBUG 1

uint8_t char_to_num(char c){
	return c-'a'+1;
}

char num_to_char(uint8_t n){
	return n+'a'-1;
}

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

void set_charnum(uint32_t *n, uint8_t k, uint8_t toAdd){
	uint32_t mask = 0xFFFFFFFF;
	//printf("First mask : \t\t\t");	displayBinary(mask);
	mask = mask << 5;
	for(int i=0; i<(5*(5-k)); i++)
		mask = (mask << 1) | 1; //(5*(5-k));
	//printf("Mask after shift : \t\t");	displayBinary(mask);
	//printf("Element : \t\t\t");	displayBinary(*n);	
	*n = *n & mask;
	//printf("Element after applying mask : \t");	displayBinary(*n);
	*n = *n | (toAdd << (5*(5-k)));
	//printf("Element to add : \t\t");	displayBinary(toAdd);
	//printf("Shifted element to add : \t"); displayBinary(toAdd << (5*(5-k)));
	//printf("Final element : \t\t");	displayBinary(*n);	printf("\n");
}

//marche dans le mauvais sens
uint8_t get_charnum(uint32_t num, uint8_t k){
  uint32_t masque = 63;
  uint8_t res = (num & masque<<k*5)>>k*5;
  return res;
}

Chainage add_to_tail(Chainage list, uint32_t elem){
	Chainage newMaillon = malloc(sizeof(Maillon));
	newMaillon->maille = elem;
	newMaillon->succ = NULL;

	if(list == NULL)
		return newMaillon;
	else{
		Chainage tmp = list;
		while(tmp->succ != NULL)
			tmp = tmp->succ;
		tmp->succ = newMaillon;
		return list;
	}
}

void print_Maillon(Chainage list){
	Chainage tmp = list;
	//printf("Liste : \n");
	while(tmp != NULL){
		//printf("\tMaillon : \t\t");	displayBinary(tmp->maille);
		tmp = tmp->succ;
	}
}

Chainage string_to_maillon(char *s){
	Chainage m = NULL;
	uint32_t maille;
	for(int i=0; i<strlen(s); i+=6){
		maille = 0xFFFFFFFF;
		for(int j=0; (j<6 && j+i<strlen(s)); j++){
			set_charnum(&maille, j, char_to_num(s[i+j]));
		}
		m = add_to_tail(m, maille);
	}
	return m;
}



