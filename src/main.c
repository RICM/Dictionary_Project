#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "read_word.h"
#include "maillon.h"

int main (int argc, char* argv[]){
	FILE *file;
	char *out;

	unsigned int nbl, nbc;

	//set_charnum(0xFF0000FF, 1, 26);
	pMaillon c = string_to_maillon("abcdefghijklmnopqrstuvwxyz");
	pMaillon d = string_to_maillon("aaaaaaaaaaaaaaaaaaaaaaaaaa");
	print_Maillon(c);
	print_Maillon(d);

	char str[length(c)*6+1];
	maillon_to_string(c, str);
	printf("String : %s\n", str);

	if(argc == 1)
		file = stdin;
	else if(argc == 2)
		file = fopen(argv[1], "r");
	else{
		fprintf(stderr, "TODO - handle multiple files.\n");
		return 0;
	}
	
	if(!file)
		fprintf(stderr, "Error : file is inaccessible.\n");
	else{
		while(!feof(file)){
			out = next_word(file, &nbl, &nbc);
			printf("%s (%d,%d)\n", out, nbl, nbc);
		}
	}
	return 0;
}