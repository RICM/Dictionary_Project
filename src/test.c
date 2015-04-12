#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#include "mot.h"

Storage rand_64bits(){
	uint64_t a = rand()&0x7FFF;
	uint64_t b = rand()&0x7FFF;
	uint64_t c = rand()&0x7FFF;
	uint64_t d = rand()&0x7FFF;
	uint64_t e = rand()&0x7FFF;
	uint64_t random = (a<<60)+(b<<45)+(c<<30)+(d<<15)+e;
    return random;
}

char rand_char(){
	return rand()%('z'+1-'a') + 'a';
}

void test_set_get_charnum(){
	Storage n, toAdd;
	char c = rand_char();
	int position = rand()%(SIZE/5);
	if(sizeof(Storage) == 8)
		n = rand_64bits();
	else
		n = rand();

	printf("\nNombre aleatoire de taille %dbits, n : \n\t", SIZE);
	displayBinary(n);

	printf("\nCaractere a ajouter : %c\n", c);
	toAdd = char_to_num(c);
	printf("\nCaractere sous forme decimal : %d\n\t", (uint8_t)toAdd);
	displayBinary(toAdd);

	printf("\nAjout de %c a la position %d : \n\t", c, position);
	set_charnum(&n, position, toAdd);
	displayBinary(n);

	printf("\nValidation : caractere a la position %d : %c\n\n", position, num_to_char(get_charnum(n, position)));
}

void test_string_to_maillon_to_string(){
	pMaillon m = string_to_maillon("abcdefghijklmnopqrstuvwxyz");
	char str[length(m)*(SIZE/5)+1];
	printf("\nAffichage de la string \"abcdefghijklmnopqrstuvwxyz\" sous forme de Maillon : \n");
		print_maillon(m);

	maillon_to_string(m, str);
	printf("\nValidation de la conversion --> resultat de la fonction inverse : %s\n", str);

	freeMaillonList(&m);
	printf("\nDesallocation memoire de m : %s\n\n", (m == NULL)? "reussie" : "echec");
}

void test_creer_mot_compare(){
	Mot m, m1;

	creer_mot(&m, "cps", 2, 2);
	printf("\nCreation d'un Mot m contenant \"cps\" et ayant pour emplacement (2, 2) : \n");
	print_mot(m);

	add_emplacement_mot(m, 3, 4);
	printf("\nAjout de l'emplacement (3, 4) a m : \n");
	print_mot(m);

	printf("\nCas ou m est avant m1 dans le dictionnaire : ");
	printf("\n============================================\n");

	creer_mot(&m1, "ricm", 1, 2);
	printf("\nCreation d'un Mot m1 contenant \"ricm\" et ayant pour emplacement (1, 2) : \n");
	print_mot(m1);

	printf("\nResultat de la comparaison de m et m1 : %d\n", compare_mots(m, m1));

	printf("\nCas ou m est apres m1 dans le dictionnaire : ");
	printf("\n============================================\n");

	creer_mot(&m1, "cms", 2, 4);
	printf("\nTransformation de m1 en un mot contenant \"cms\" et ayant pour emplacement (2, 4) : \n");
	print_mot(m1);

	printf("\nResultat de la comparaison de m et m1 : %d\n", compare_mots(m, m1));

	printf("\nCas ou m est egal a m1 dans le dictionnaire : ");
	printf("\n=============================================\n");

	creer_mot(&m1, "cps", 3, 5);
	printf("\nTransformation de m1 en un mot contenant \"cps\" et ayant pour emplacement (3, 5) : \n");
	print_mot(m1);

	printf("\nResultat de la comparaison de m et m1 : %d\n", compare_mots(m, m1));

	freeMot(&m);
	printf("\nDesallocation memoire de m : %s", (m.tete_mot == NULL && m.tete_liste == NULL)? "reussie" : "echec");
	freeMot(&m1);
	printf("\nDesallocation memoire de m1 : %s\n\n", (m1.tete_mot == NULL && m1.tete_liste == NULL)? "reussie" : "echec");
}

int main (int argc, char* argv[]){
	srand(time(NULL));

	printf("\n");
	printf("#################################################################################\n");
	printf("#\t\t\tTest sur des donnees de taille %dbits\t\t\t#\n", SIZE);
	printf("#################################################################################\n\n");

	printf("\t#################################################################\n");
	printf("\t#                Test set_charnum et get_charnum                #\n");
	printf("\t#################################################################\n");
	test_set_get_charnum();

	printf("\t#################################################################\n");
	printf("\t#          Test string_to_maillon et maillon_to_string          #\n");
	printf("\t#################################################################\n");
	test_string_to_maillon_to_string();

	printf("\t#################################################################\n");
	printf("\t#                 Test creer_mot et compare_mots                #\n");
	printf("\t#################################################################\n");
	test_creer_mot_compare();
	return 0;
}
