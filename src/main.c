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
        }
        affichage(d);
    }
    return 0;
}

int main (int argc, char* argv[]){
	FILE *file;

	/*Storage n = 0x0000000000000000;
	set_charnum(&n, 0, 26);
	displayBinary(n);
	printf("%d\n", get_charnum(n, 0));
	
	pMaillon c = string_to_maillon("abcdefghijklmnopqrstuvwxyz");
	pMaillon d = string_to_maillon("aaaaaaaaaaaaaaaaaaaaaaaaaa");
	print_Maillon(c);
	print_Maillon(d);*/

	if(argc == 1){
        file = stdin;
				printf("#############################################################################################\n");
				printf("Fichier : stdin\n");
				printf("#############################################################################################\n");
        return traitement(file);
	}
  else if(argc == 2){
				printf("#############################################################################################\n");
				printf("Fichier : %s\n",argv[1] );
				printf("#############################################################################################\n");
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
						printf("#############################################################################################\n");
						printf("Fichier : %s\n",argv[varLoop] );
						printf("#############################################################################################\n");
            status = traitement(file);
            fclose(file);
            varLoop++;
        }
        return status;
	}
	return 0;
}
