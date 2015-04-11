
#include "maillon.h"

/** Display a maillon in a binary rapresentation. */
void print_maillon(pMaillon list){
	pMaillon tmp = list;
	printf("Liste : \n");
	while(tmp != NULL){
		printf("\tMaillon : \t\t");	displayBinary(tmp->maille);
		tmp = tmp->succ;
	}
}

/** Get the length of a Maillon list. */
int length(pMaillon list){
	int i=0;
	pMaillon tmp = list;
	while(tmp != NULL){
		i++;
		tmp = tmp->succ;
	}
	return i;
}

/** Add a Maillon to the tail of a Maillon list. */
pMaillon add_to_tail(pMaillon list, Storage elem){
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

/** Convert a string into a Maillon list. */
pMaillon string_to_maillon(char *s){
	pMaillon m = NULL;
	Storage maille;
	for(int i=0; i<strlen(s); i+=NBL){
		maille = 0;
		for(int j=0; (j<NBL && j+i<strlen(s)); j++){
			set_charnum(&maille, j, char_to_num(s[i+j]));
		}
		m = add_to_tail(m, maille);
	}
	return m;
}

/** Convert a Maillon list into a string. */
void maillon_to_string(pMaillon list, char *str){
	int bEnd = 0;
	int i, j;
	pMaillon tmp = list;

	char strTmp[length(list)*NBL+1];

	j = 0;
	while(tmp != NULL){
		i = 0;
		while(i<NBL && !bEnd){
			if(get_charnum(tmp->maille, i) != 0)
				strTmp[j*NBL+i] = num_to_char(get_charnum(tmp->maille, i));
			else
				bEnd = 1;
			i++;
		}
		tmp = tmp->succ;
		j++;
	}

	if(bEnd)
		strTmp[(j-1)*NBL+i-1] = '\0';
	else
		strTmp[(j-1)*NBL+i] = '\0';
	strcpy(str, strTmp);
}