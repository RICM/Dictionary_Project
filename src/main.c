#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "read_word.h"
#include "dictionnaire.h"

int menu (){
	int resultat;
	printf("\n");
	printf("\t#########################################################################################\n");
	printf("\t# \t\t\t\t\tMenu : \t\t\t\t\t\t#\n");
	printf("\t#1. Afficher le dictionnaire\t\t\t\t\t\t\t\t#\n");
	printf("\t#2. Afficher les maillons\t\t\t\t\t\t\t\t#\n");
	printf("\t#3. Quitter l'application\t\t\t\t\t\t\t\t#\n");
	printf("\t#########################################################################################\n");
	printf("\n");
	scanf("%d", &resultat);
	return resultat;
}

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
            d = insertion_dictionnaire(d, out, nbl, nbc); // ajout trié du mot out dans le dictionnaire d
        }
        affichage(d);   // affichage de l'ensemble du dictionnaire
        printf("\n");
        freeDictionnaireList(&d); // libération de la mémoire utilisé par d
        printf("\tDesallocation du dictionnaire : %s\n", (d == NULL)? "reussie" : "echec");
    }
    return 0;
}

int traitement2 (FILE *file){
	char *out;
	unsigned int nbl, nbc;
	pDictionnaire d = NULL;

    if(!file){
        fprintf(stderr, "Error : file is inaccessible.\n");
        return -1;
    }
    else{
        while(!feof(file)){
            out = next_word(file, &nbl, &nbc);
            d = insertion_dictionnaire(d, out, nbl, nbc);
        }
        affichageMaillons(d);
        printf("\n");
				freeDictionnaireList(&d); // libération de la mémoire utilisé par d
        printf("\tDesallocation du dictionnaire : %s\n", (d == NULL)? "reussie" : "echec");
    }
    return 0;
}

int main (int argc, char* argv[]){
	FILE *file;
	int menures;

	if(argc == 1){
    file = stdin;
		printf("\n");
		printf("\t#########################################################################################\n");
		printf("\t# \t\t\t\tFichier : stdin\t\t\t\t#\n");
		printf("\t#########################################################################################\n");
		printf("\n");
		return traitement(file);
	}
  	else if(argc == 2){
			int status = 0;
  		printf("\n");
			printf("\t#########################################################################################\n");
			printf("\t# \t\t\t\tFichier : %s\t\t\t\t#\n",argv[1] );
			printf("\t#########################################################################################\n");
			printf("\n");
				menures = menu();
				while (menures !=3 && status !=1){
					switch (menures){
						case 1:
							file = fopen(argv[1], "r");
							status = traitement(file);
							fclose(file);
							menures = menu();
							break;
						case 2:
							file = fopen(argv[1], "r");
							status = traitement2(file);
							fclose(file);
							menures = menu();
							break;
						default:
							return 1;
					}
				}

	}
  else{
        int status = 0;
        int startLoop = 1;
        int endLoop = argc;
        int varLoop = startLoop;
					menures = menu();
					while (menures !=3){
						switch (menures){
							case 1:
							 status = 0;
			         startLoop = 1;
			         endLoop = argc;
			         varLoop = startLoop;
			        while ( varLoop < endLoop && status == 0){
			            file = fopen(argv[varLoop], "r");
									if (!file)
										return 1;
			            printf("\n");
									printf("\t#########################################################################################\n");
									printf("\t# \t\t\t\tFichier : %s\t\t\t\t#\n",argv[varLoop] );
									printf("\t#########################################################################################\n");
									printf("\n");
			            status = traitement(file);
			            if(file)
			                fclose(file);
			            varLoop++;
			        }
								menures = menu();
								break;
							case 2:
							 status = 0;
							 startLoop = 1;
							 endLoop = argc;
							 varLoop = startLoop;
							while ( varLoop < endLoop && status == 0){
									file = fopen(argv[varLoop], "r");
									printf("\n");
									printf("\t#########################################################################################\n");
									printf("\t# \t\t\t\tFichier : %s\t\t\t\t#\n",argv[varLoop] );
									printf("\t#########################################################################################\n");
									printf("\n");
									status = traitement2(file);
									if(file)
											fclose(file);
									varLoop++;
							}
								menures = menu();
								break;
							default:
								return 1;
						}
					}
				}

				return 0;
	}
