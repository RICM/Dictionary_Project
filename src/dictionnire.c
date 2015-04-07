#include "dictionnaire.h"

void insertion_dictionnaire(pDictionnaire d, char *mot, int l, int c){
	pDictionnaire tmpSucc;
	pDictionnaire tmpPred;

	Mot m;
	creer_mot(&m, mot, l, c);

	int bEnd = 0;
	if(d == NULL){
		d->m = m;
	}
	else{
		tmpPred = d;
		tmpSucc = tmpPred->succ;
		while(tmpSucc != NULL && !bEnd){
			switch(compare(m, tmpPred->m)){
				case 0:
					pEmplacement emp = malloc(sizeof(Emplacement));
			    	emp->l = l;
			    	emp->c = c;
			    	emp->succ = NULL;

			    	d->m.queue_liste = emp;
			    	bEnd = 1;
					break;
				case -1:
					Dictionnaire toAdd = malloc(sizeof(Dictionnaire));
					toAdd.m = m;
					toAdd.succ = tmpSucc;
					tmpPred->succ = toAdd;
					bEnd = 1;
					break;
				case 1:
					tmpSucc = tmpSucc->succ;
					tmpPred = tmpPred->succ;
					break;
			}
		}
		if(tmpSucc == NULL && !bEnd){
			switch(compare(m, tmpPred->m)){
				case 0:
					pEmplacement emp = malloc(sizeof(Emplacement));
			    	emp->l = l;
			    	emp->c = c;
			    	emp->succ = NULL;

			    	d->m.queue_liste = emp;
					break;
				case -1:
					Dictionnaire toAdd = malloc(sizeof(Dictionnaire));
					toAdd.m = m;
					toAdd.succ = tmpSucc;
					tmpPred->succ = toAdd;
					break;
				case 1:
					Dictionnaire toAdd = malloc(sizeof(Dictionnaire));
					toAdd.m = m;
					tmpPred->succ = toAdd;
					break;
			}
		}
	}
	

}