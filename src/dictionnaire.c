#include "dictionnaire.h"

/** Add a Mot to the head of a Dictionnaire list. */
pDictionnaire add_to_head_dictionnaire(pDictionnaire d, Mot m){
	pDictionnaire toAdd = malloc(sizeof(Dictionnaire));
	toAdd->m = m;
	toAdd->succ = d;
	return toAdd;
}

/** Add a Mot to the tail of a Dictionnaire list. */
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

/** Add a Mot inside a Dictionnaire list. */
pDictionnaire add_inside_dictionnaire(pDictionnaire pred, pDictionnaire succ, Mot m){
	pDictionnaire toAdd = malloc(sizeof(Dictionnaire));
	toAdd->m = m;
	toAdd->succ = succ;
	pred->succ = toAdd;
	return pred;
}

/** Add a Mot to a Dictionnaire list. */
pDictionnaire insertion_dictionnaire(pDictionnaire d, char *mot, int l, int c){
	pDictionnaire tmpSucc;
	pDictionnaire tmpPred;

	Mot m;
	creer_mot(&m, mot, l, c);

	if(d == NULL)
		return add_to_head_dictionnaire(NULL, m);
	else if(d->succ == NULL || compare_mots(m, d->m) < 1)
		if(compare_mots(m, d->m) == 0)
			d->m = add_emplacement_mot(d->m, l, c);
		else if(compare_mots(m, d->m) < 0)
			d = add_to_head_dictionnaire(d, m);
		else
			d = add_to_tail_dictionnaire(d, m);
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

/** Display a Dictionnaire list. */
void affichage(pDictionnaire d){
	pDictionnaire tmp = d;
	while (tmp != NULL){
		print_mot(tmp->m);
		tmp = tmp->succ;
	}
	free(tmp);
}

/** Release of the memory used by a Dictionnaire list. */
void freeDictionnaireList(pDictionnaire *d){
	pDictionnaire tmp;
	while(*d != NULL){
		tmp = *d;
		*d = (*d)->succ;
		freeMot(&(tmp->m));
	}
}

/** Display a Dictionnaire list with associated maillons */
void affichageMaillons(pDictionnaire d){
	pDictionnaire tmp = d;
	printf("\t#########################################################################################\n");
	printf("\t\tListe des maillons correspondants : \n");
	printf("\t#########################################################################################\n");
	while (tmp != NULL){
		printf("\t#########################################################################################\n");
		printf("\tMot : ");
		print_mot(tmp->m);
		printf("\t#########################################################################################\n");
		print_maillon(tmp->m.tete_mot);
		printf("\n");
		tmp = tmp->succ;
	}
	free(tmp);
}
