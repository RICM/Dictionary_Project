#include "struct.h"

#define DEBUG 1

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

void set_charnum(uint32_t *n, uint8_t k, uint8_t toAdd){
	uint32_t mask = 0xFFFFFFFF;
	mask = mask << 5;
	for(int i=0; i<(5*(5-k)); i++)
		mask = (mask << 1) | 1;	
	*n = *n & mask;
	*n = *n | (toAdd << (5*(5-k)));
}

//marche dans le mauvais sens -- Fixed
uint8_t get_charnum(uint32_t num, uint8_t k){
  /*uint32_t masque = 63;
  uint8_t res = (num & masque<<k*5)>>k*5;
  return res;*/

	return (num & (31<<(5*(5-k))))>>(5*(5-k));
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
	printf("Liste : \n");
	while(tmp != NULL){
		printf("\tMaillon : \t\t");	displayBinary(tmp->maille);
		tmp = tmp->succ;
	}
}

int length(Chainage list){
	int i=0;
	Chainage tmp = list;
	while(tmp != NULL){
		i++;
		tmp = tmp->succ;
	}
	return i;
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

void maillon_to_string(Chainage list, char *str){
	int bEnd = 0;
	int i, j;
	Chainage tmp = list;

	char strTmp[length(list)*6+1];

	j = 0;
	while(tmp != NULL){
		i = 0;
		while(i<6 && !bEnd){
			if(get_charnum(tmp->maille, i) != 31){
				strTmp[j*6+i] = num_to_char(get_charnum(tmp->maille, i));
			}
			else
				bEnd = 1;
			i++;
		}
		tmp = tmp->succ;
		j++;
	}
	if(i==6)
		strTmp[j*6] = '\0';
	else
		strTmp[(j-1)*6+i-1] = '\0';

	strcpy(str, strTmp);
}



