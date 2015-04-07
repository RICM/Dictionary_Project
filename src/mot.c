
#include "mot.h"

/*void add_emplacement(pEmplacement p, pEmplacement p2){
	pEmplacement tmp = p;
	while(tmp->succ != NULL){
		tmp = tmp->succ;
	}
	tmp->succ = p2;
}*/

void creer_mot(pMot mot, char *m, int l, int c){
	pMaillon maillon = string_to_maillon(m);

	if(maillon != NULL){
    	mot->tete_mot = maillon;
    	mot->queue_mot = NULL;

    	pEmplacement emp = malloc(sizeof(Emplacement));
    	emp->l = l;
    	emp->c = c;
    	emp->succ = NULL;

    	mot->tete_liste = emp;
    	mot->queue_liste = NULL;

    	while(maillon->succ != NULL){
      		maillon = maillon->succ;
      		mot->queue_mot = maillon;
    	}
  	}
}

void print_mot(Mot m){
	pEmplacement empTmp = m.tete_liste;
	char str[length(m.tete_mot)*6+1];
	maillon_to_string(m.tete_mot, str);
	printf("%s ", str);
	while(empTmp != NULL){
		printf("(%d, %d) ", empTmp->l, empTmp->c);
		empTmp = empTmp->succ;
	}
	printf("\n");
}

int compare_mots(Mot m1, Mot m2){
	pMaillon tmp1 = m1.tete_mot;
	pMaillon tmp2 = m2.tete_mot;
	int out = 0;
	int bEnd = 0;
	int i;

	while(tmp1 != NULL && tmp2 != NULL && !bEnd){
		i = 0;
		while(i<6 && !bEnd){
			if(get_charnum(tmp1->maille, i) > get_charnum(tmp2->maille, i)){
				out = -1;
				bEnd = 1;
			}
			else if(get_charnum(tmp1->maille, i) < get_charnum(tmp2->maille, i)){
				out = 1;
				bEnd = 1;
			}
			i++;
		}

		if(!bEnd){
			tmp1 = tmp1->succ;
			tmp2 = tmp2->succ;
		}
	}
	if(tmp1 == NULL && tmp2 != NULL)
		out = -1;
	else if(tmp2 == NULL && tmp1 != NULL)
		out = 1;
	return out;
}