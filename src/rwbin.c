/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include "rwbin.h"

/*
 * Lecture d'un octet dans un fichier
 * @param file : Le fichier dans lequel lire
 * @return : L'octet lu
 */
unsigned char read(FILE* file)
{
	if(file == NULL)
	{
		fprintf(stderr, "Null file pointer : rwbin.c/read\n");
		exit(EXIT_FAILURE);
	}

	unsigned char read;

	fread(&read, sizeof(read), 1, file);

	return read;
}

/*
 * Ecrit un code dans un fichier
 * @param file : Le fichier dans lequel lire
 * @param code_size : La taille du code à lire
 * @param nb_prev : Le décalage par rapport au code précédent lu, et celui pour le suivant en sortie
 * @param for_next : Le code qui sera utile pour la prochaine lecture
 * @param from_prev : Le code lu lors de la lecture précédente
 * @return : Le code lu
 * Exemple d'utilisation :
 * 		int cr = 0, nb_prev = 0, n;
 *		int i = 0;
 *		FILE* file = fopen("a.out", "rb");
 *
 *		do
 *		{
 *			cr = read_c(file, 9, &nb_prev, &n, n);
 *			i++;
 *		} while(cr != 256); // Correspond à EOF
 */
int read_c(FILE* file, int code_size, int* nb_prev, int* for_next, int from_prev)
{
	int i;
	int res = from_prev;
	int nb_read = (code_size / RW_SIZE) + 1;
	int fn = RW_SIZE - (code_size - *nb_prev) % RW_SIZE;
	int mask;
	unsigned char r;

	if(fn == RW_SIZE)
		fn = 0;

	if(*nb_prev == 0)
		i = 0;
	else
		i = 1;

	while(i < nb_read)
	{
		r = read(file);
		res <<= RW_SIZE;
		res += r;
		i++;
	}
	
	mask = (1 << fn) - 1;
	*for_next = res & mask;
	res >>= fn;

	*nb_prev = fn;

	return res;
}

/*
 * Ecrit un caractere dans le fichier spécifié
 * @param fichier : Fichier sortie 
 * @param car : Caractere à insérer dans le fichier
 */
void write (FILE* file, unsigned char car){

	if(file == NULL)
	{
		fprintf(stderr, "Null file pointer : rwbin.c/write\n");
		exit(EXIT_FAILURE);
	}
	fwrite(&car, sizeof(car), 1, file);
}

/*
 * Texte -> Compresseur -> 8bits
 * @param file : Fichier sortie
 * @param code : Code du caractère 
 * @param taille : Taille du code
 * @param buffer : Buffer contenant le reste auquel le code suivant sera ajouté
 * @param k : Le nombre de bit à écrire pour completer l'octet
 */
void writer_code(FILE* file,unsigned int code, unsigned int taille, int* buffer, int* reste){
	if(*reste != (taille-8) && code != 256){	
		*buffer = *buffer | (code);
		unsigned char mot = *buffer >> (taille - *reste);
		write(file, mot);
		*buffer = *buffer << taille;
		*reste = *reste -1;
	}else if (code == 256 && *reste != (taille-8)){ 
		*buffer = *buffer | (code);
		unsigned char mot = *buffer >> (taille - *reste);
		write(file, mot);
		mot = *buffer << (8-(taille - *reste));
		*buffer = *buffer << taille;
		write(file, mot);
		*reste = *reste -1;
	}else{
		*buffer = *buffer | (code);
		unsigned char mot = *buffer >> 8;
		write(file,mot);
		mot = *buffer & 255;
		write(file,mot);
		*buffer = 0;
		*reste = 8;
	}
}