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
#include "rwbin.h"
#include "codage.h"

int main(int argc, char* argv[])
{
	map* d = init_map();

	int cr, nb_prev = 0, n;
	int end = _EOF;
	int i = 0;
	data d_eof = *create_data(&end, 1);
	FILE* file = fopen("a.out", "rb");

	do
	{
		cr = read_c(file, 9, &nb_prev, &n, n);
		printf("0x%x\n", cr);
		i++;
	} while(cr != get_code(d_eof, d));
	
	free_map(d);

	return EXIT_SUCCESS;	
	
}
