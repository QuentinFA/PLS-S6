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

int main(int argc, char* argv[])
{
	map* d;
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

	return EXIT_SUCCESS;
}