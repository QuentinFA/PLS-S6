/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 * Sara OOUNISSI - Adrien SIPASSEUTH *
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
	/*map* d;
	int a = 1, b[] = {1, 2}, c[] = {1,8};
	data* dd = create_data(&a, 1);

	d = init_map();

	printf(is_set(*dd, d) ? "Is set 1 ? yes\n" : "Is set 1 ? no\n");
	dd = create_data(c, 2);
	printf(is_set(*dd, d) ? "Is set (1,8) ? yes\n" : "Is set (1,8) ? no\n");
	dd = create_data(b, 2);
	set_code(dd, d);
	printf(is_set(*dd, d) ? "Is set (1,2) ? yes\n" : "Is set (1,2 )? no\n");
	printf("Code of (1,2) : %d\n", get_code(*dd, d));
	printf("Donnée de code 8 : ");
	dd = get_data(8, d);
	while(dd != NULL)
	{
		printf("%d\n", dd->d);
		dd = dd->next;
	}

	free_map(d);
	*/
///////////////////////////////////////////////////////////////////////////////////
	
	FILE *fichier_entree ,*fichier_sortie;
	
	//fichier_entree = fopen("entre.txt", "r");
	fichier_sortie = fopen("sortie.txt", "w+");
	
	int buffer_rec=0;
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
	
	/*int a1,a2,a3,a4;
	buffer_rec= buffer_rec + read(fichier_entree);
	a1=read_code(fichier_entree, 9, 1, &buffer_rec);
	a2=read_code(fichier_entree, 9, 2, &buffer_rec);
	a3=read_code(fichier_entree, 9, 3, &buffer_rec);
	a4=read_code(fichier_entree, 9, 4, &buffer_rec);
	
	printf("%c %c %c %c\n",a1,a2,a3,a4);
	*/
	
	//fclose(fichier_entree);
	fclose(fichier_sortie);
	
	
	return EXIT_SUCCESS;	
	
}
