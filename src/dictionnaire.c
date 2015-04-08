#include "dictionnaire.h"

pDictionnaire add_to_head_dictionnaire(pDictionnaire d, Mot m){
	pDictionnaire toAdd = malloc(sizeof(Dictionnaire));
	toAdd->m = m;
	toAdd->succ = d;
	return toAdd;
}

pDictionnaire add_to_tail_dictionnaire(pDictionnaire d, Mot m){
	pDictionnaire tmp = d;

	pDictionnaire toAdd = malloc(sizeof(Dictionnaire));
	toAdd->m = m;
	toAdd->succ = NULL;

	while(tmp->succ != NULL)
		tmp = tmp->succ;
	tmp->succ = toAdd;

	return d;
}

pDictionnaire add_inside_dictionnaire(pDictionnaire pred, pDictionnaire succ, Mot m){
	pDictionnaire toAdd = malloc(sizeof(Dictionnaire));
	toAdd->m = m;
	toAdd->succ = succ;
	pred->succ = toAdd;
	return pred;
}

pDictionnaire insertion_dictionnaire(pDictionnaire d, char *mot, int l, int c){
	pDictionnaire tmpSucc;
	pDictionnaire tmpPred;

	Mot m;
	creer_mot(&m, mot, l, c);

	if(d == NULL)
		return add_to_head_dictionnaire(NULL, m);
	else if(d->succ == NULL || compare_mots(m, d->m) < 1)
		switch(compare_mots(m, d->m)){
			case 0:
				d->m = add_emplacement_mot(d->m, l, c);
		    	break;
			case -1:
				d = add_to_head_dictionnaire(d, m);
				break;
			case 1:
				d = add_to_tail_dictionnaire(d, m);
				break;
		}
	else{
		tmpPred = d;
		tmpSucc = tmpPred->succ;

		while(tmpSucc->succ != NULL && compare_mots(m, tmpSucc->m) > 0){
			tmpSucc = tmpSucc->succ;
			tmpPred = tmpPred->succ;
		}
		
		if(compare_mots(m, tmpSucc->m) < 1)
			if(compare_mots(m, tmpSucc->m) == 0)
				tmpSucc->m = add_emplacement_mot(tmpSucc->m, l, c);
			else
				tmpPred = add_inside_dictionnaire(tmpPred, tmpSucc, m);
		else if(tmpSucc->succ == NULL)
			d = add_to_tail_dictionnaire(d, m);
	}
	return d;
}

void affichage(pDictionnaire d){
	pDictionnaire tmp = d;
	while (tmp != NULL){
		print_mot(tmp->m);
		tmp = tmp->succ;
	}
}
