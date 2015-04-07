
#include "maillon.h"

void print_Maillon(pMaillon list){
	pMaillon tmp = list;
	printf("Liste : \n");
	while(tmp != NULL){
		printf("\tMaillon : \t\t");	displayBinary(tmp->maille);
		tmp = tmp->succ;
	}
}

int length(pMaillon list){
	int i=0;
	pMaillon tmp = list;
	while(tmp != NULL){
		i++;
		tmp = tmp->succ;
	}
	return i;
}

pMaillon add_to_tail(pMaillon list, uint32_t elem){
	pMaillon newMaillon = malloc(sizeof(Maillon));
	newMaillon->maille = elem;
	newMaillon->succ = NULL;

	if(list == NULL)
		return newMaillon;
	else{
		pMaillon tmp = list;
		while(tmp->succ != NULL)
			tmp = tmp->succ;
		tmp->succ = newMaillon;
		return list;
	}
}

pMaillon string_to_maillon(char *s){
	pMaillon m = NULL;
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

void maillon_to_string(pMaillon list, char *str){
	int bEnd = 0;
	int i, j;
	pMaillon tmp = list;

	char strTmp[length(list)*6+1];

	j = 0;
	while(tmp != NULL){
		i = 0;
		while(i<6 && !bEnd){
			if(get_charnum(tmp->maille, i) != 31)
				strTmp[j*6+i] = num_to_char(get_charnum(tmp->maille, i));
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