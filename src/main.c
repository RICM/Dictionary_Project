#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "read_word.h"
#include "dictionnaire.h"

int traitement (FILE *file){
	char *out;
	unsigned int nbl, nbc;
	pDictionnaire d = NULL;

    if(!file){
        fprintf(stderr, "Error : file is inaccessible.\n");
        return 1;
    }
    else{
        while(!feof(file)){
            out = next_word(file, &nbl, &nbc);
            d = insertion_dictionnaire(d, out, nbl, nbc);
            //printf("%s (%d,%d)\n", out, nbl, nbc);
        }
        affichage(d);
    }
    return 0;
}

int main (int argc, char* argv[]){
	FILE *file;
	//set_charnum(0xFF0000FF, 1, 26);
	/*pMaillon c = string_to_maillon("abcdefghijklmnopqrstuvwxyz");
	pMaillon d = string_to_maillon("aaaaaaaaaaaaaaaaaaaaaaaaaa");
	print_Maillon(c);
	print_Maillon(d);

	char str[length(c)*6+1];
	maillon_to_string(c, str);
	printf("String : %s\n", str);

	Mot m;
	creer_mot(&m, "b", 1, 2);
	pEmplacement emp = malloc(sizeof(Emplacement));
	emp->l = 3;
	emp->c = 4;
	emp->succ = NULL;
	m.tete_liste = add_emplacement(m.tete_liste, emp);
	m.queue_liste = emp;
	print_mot(m);
	Mot m1;
	creer_mot(&m1, "al", 1, 2);
	print_mot(m1);
	printf("%d\n", compare_mots(m, m1));
	

	/*pDictionnaire d = NULL;
	d = insertion_dictionnaire(d, "b", 1, 2);
	d = insertion_dictionnaire(d, "a", 2, 2);
	d = insertion_dictionnaire(d, "blabla", 2, 2);
	d = insertion_dictionnaire(d, "alabla", 2, 2);
	printf("Dictionnaire : \n\n");
	affichage(d);
	printf("\n\n");*/

	if(argc == 1){
        file = stdin;
        return traitement(file);
	}
    else if(argc == 2){
        file = fopen(argv[1], "r");
        return traitement(file);
    }
    else{
        int status = 0;
        int startLoop = 3;
        int endLoop = argc;
        int varLoop = startLoop;
        while ( varLoop < endLoop && status == 0){
            file = fopen(argv[varLoop], "r");
            status = traitement(file);
            fclose(file);
            varLoop++;
        }
        return status;
	}
	return 0;
}
