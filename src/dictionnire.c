#include "dictionnaire.h"

void insertion_dictionnaire(pDictionnaire d, char *mot, int l, int c){
	pDictionnaire tmpSucc = d->succ;
	pDictionnaire tmpPred = d;
	int bEnd = 0;
	while(tmpPred != NULL && !bEnd){
		if()
	}
	if(tmp == NULL)

}

void affichage(pDictionnaire d){
	if (d != NULL){
		while (d->succ != NULL){
			print_mot(d->m);
			d = d->succ;
		}
	}
}
