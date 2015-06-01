/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include "dico.h"
#include "data.h"
#include "lect-ecri-bin.h"

int main(int argc, char* argv[])
{
	
	FILE *fichier_sortie;
	
	//fichier_entree = fopen("entre.txt", "r");

	fichier_sortie = fopen("sortie.txt", "w+");
	
	int buffer_env=0;
	
	//void writer_code(FILE* file,unsigned int code, unsigned int taille, int* buffer, int* reste);
	int reste = 8;
	
	writer_code(fichier_sortie, 'a', 9, &buffer_env, &reste);
	writer_code(fichier_sortie, 'b', 9, &buffer_env, &reste);
	writer_code(fichier_sortie, 256, 9, &buffer_env, &reste);
	/*writer_code(fichier_sortie, 'c', 9, &buffer_env, &reste);
	
	writer_code(fichier_sortie, 'd', 9, &buffer_env, &reste);
	writer_code(fichier_sortie, 259, 9, &buffer_env, &reste);
	writer_code(fichier_sortie, 'd', 9, &buffer_env, &reste);
	writer_code(fichier_sortie, 10, 9, &buffer_env, &reste);
	writer_code(fichier_sortie, 256, 9, &buffer_env, &reste);
	
	//writer_code(fichier_sortie, 98, 9, &buffer_env,7 );
	//write_code(fichier_sortie, 258, 9, &buffer_env, 6);
	//write_code(fichier_sortie, 99, 9, &buffer_env, 5);
	*/
	fclose(fichier_sortie);

	
	return EXIT_SUCCESS;	
	
}
