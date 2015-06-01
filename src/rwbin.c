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
 *		} while(cr != 256);
 */
int read_c(FILE* file, int code_size, int* nb_prev, int* for_next, int from_prev)
{
	if(file == NULL)
	{
		fprintf(stderr, "Null file pointer : rwbin.c/read_c\n");
		exit(EXIT_FAILURE);
	}

	int i;
	int res = from_prev;
	int nb_read = (code_size / RW_SIZE) + 1;
	int fn = RW_SIZE - (code_size - *nb_prev) % RW_SIZE;
	int mask;
	unsigned char read;

	if(fn == RW_SIZE)
		fn = 0;

	if(*nb_prev == 0)
		i = 0;
	else
		i = 1;

	while(i < nb_read)
	{
		fread(&read, sizeof(read), 1, file);
		res <<= RW_SIZE;
		res += read;
		i++;
	}
	
	mask = (1 << fn) - 1;
	*for_next = res & mask;
	res >>= fn;

	*nb_prev = fn;

	return res;
}

void write_c(FILE* file, int code_size, int* w_prev, int* for_next, int from_prev)
{
	if(file == NULL)
	{
		fprintf(stderr, "Null file pointer : rwbin.c/write_c\n");
		exit(EXIT_FAILURE);
	}

	/*int i;

	unsigned char write;*/
}