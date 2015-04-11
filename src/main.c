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
        return 0;
    }
    else{
        while(!feof(file)){
            out = next_word(file, &nbl, &nbc);
            d = insertion_dictionnaire(d, out, nbl, nbc);
        }
        affichage(d);
        printf("\n");
    }
    return 0;
}

int main (int argc, char* argv[]){
	FILE *file;

	printf("%ld\n", sizeof(Storage));

	if(argc == 1){
        file = stdin;
		printf("\n");
		printf("\t#############################################################################################\n");
		printf("\t# Fichier : stdin\n");
		printf("\t#############################################################################################\n");
		printf("\n");
        return traitement(file);
	}
  	else if(argc == 2){
  		printf("\n");
		printf("\t#############################################################################################\n");
		printf("\t# Fichier : %s\n",argv[1] );
		printf("\t#############################################################################################\n");
		printf("\n");
        file = fopen(argv[1], "r");
        return traitement(file);
  }
  else{
        int status = 0;
        int startLoop = 1;
        int endLoop = argc;
        int varLoop = startLoop;
        while ( varLoop < endLoop && status == 0){
            file = fopen(argv[varLoop], "r");
            printf("\n");
			printf("\t#############################################################################################\n");
			printf("\t# Fichier : %s\n",argv[varLoop] );
			printf("\t#############################################################################################\n");
			printf("\n");
            status = traitement(file);
            if(file)
                fclose(file);
            varLoop++;
        }
        return status;
	}
	return 0;
}
