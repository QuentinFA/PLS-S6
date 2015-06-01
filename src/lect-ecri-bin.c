/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lect-ecri-bin.h"

//on a un buffer avec une variable a l'interieur
//on va lire un nouvel octet et completer le buffer 
//puis le renvoyer avec la bonne taille 
//et enfin on met a jour le buffer avec le reste du 
//mot lu
//faire une boucle avec k de 1 a 8 pour le reste 
//(decallages) 
int read_code(FILE* file, int taille, int k, int* buffer){
	*buffer = *buffer << k;
	int new = read(file);
	int tmp = new >> (8 - k);
	*buffer = *buffer | tmp;
	tmp = *buffer;
	*buffer = (new << k) >> k;
	return tmp;
}

//on a un buffer sur 8 oct avec une variable a l'interieur
//on va prendre le nouveau code et completer le buffer 
//puis le renvoyer complet 
//et enfin on met a jour le buffer avec le reste du 
//code qui depasse des 8 bits
//faire une boucle avec k de 8 a 1 pour le reste 
void write_code(FILE* file, int code, int taille, char* buffer, int k){
	*buffer = *buffer << (taille - k);
	int tmp = code >> k;
	*buffer = *buffer + tmp;
	char mot = *buffer;
	*buffer = (code << (taille - k)) >> (taille - k);
	write(file, mot); 
}

/*
* ma version
*/
void writer_code(FILE* file,unsigned int code, unsigned int taille, int* buffer, int* reste){
	if(*reste != (taille-8) && code != 256){	
		//printf("%x\n",code);
		*buffer = *buffer | (code);
		//printf("%x\n",*buffer);
		unsigned char mot = *buffer >> (taille - *reste);
		//printf("%x \n",mot);
		write(file, mot);
		*buffer = *buffer << taille;
		*reste = *reste -1;
	}else if (code == 256 && *reste != (taille-8)){ 
		printf("ici");
		printf("%x\n",code);
		*buffer = *buffer | (code);
		printf("%x\n",*buffer);
		unsigned char mot = *buffer >> (taille - *reste);
		printf("%x \n",mot);
		write(file, mot);
		mot = *buffer << (8-(taille - *reste));
		printf("%x \n",mot);
		*buffer = *buffer << taille;
		write(file, mot);
		*reste = *reste -1;
	}else{
		printf("ici\n");
		*buffer = *buffer | (code);
		printf("buffer avant envoie %x\n \n",*buffer);
		unsigned char mot = *buffer >> 8;
		printf("mot avant envoie %x\n \n",mot);
		write(file,mot);
		mot = *buffer & 255;
		write(file,mot);
		*buffer = 0;
		*reste = 8;
	}
}

/*
// ecrit dans le fichier ,le caractère
*/
void write (FILE* fichier, unsigned char car){

	if(fichier == NULL){
		fprintf (stderr, "Echec de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	//printf("0x%x\n",car);
	//fprintf(fichier,"%x", car);
	fwrite(&car, sizeof(car), 1, fichier);
	//fputc(car, fichier);
}

/*
// lit le caractère dans le fichier
*/
int read (FILE *fichier){
	int res;
	if(fichier == NULL){
		fprintf (stderr, "Echec de l'ouverture du fichier ");
		exit(EXIT_FAILURE);
	}
	
	res = fgetc(fichier);
	return res;
}





