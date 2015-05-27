/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 * Sara OOUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "dico.h"

void init(map* dic)
{
	dic = calloc(1, sizeof(map));

	if(dic == NULL)
	{
		printf("Allocation error...\n");
		exit(EXIT_FAILURE);
	}

	dic->size = BEGINING_SIZE;

	/* TODO : Ajouter les caractères de base */

}

// TODO
int hash(char* o)
{
	return 0;
}

bool set_code(char* o, map* dic, int code)
{
	int h = hash(o);
	elem* add_here;

	// Pas assez d'espace, augmentation d'une puissance de 2
	if(h > dic->size)
		// TODO : Size up

	add_here = &(dic->tab[h]);

	// Gestion des collisions avec une liste
	if(add_here != NULL)
	{
		while(add_here->next != NULL)
			add_here = add_here->next;
		add_here->next = calloc(1, sizeof(elem));
		add_here = add_here->next;
	}
	else
	{
		add_here = calloc(1, sizeof(elem));
	}
	//

	// Echec du calloc
	if(add_here == NULL)
		return false;

	add_here->data = o;
	add_here->code = code;

	return true;
}

// TODO
bool is_set(char* o, map* dic)
{
	int h = hash(o);
	elem* current;

	if(dic->tab[h].data == o)
		return true;
	else
	{
		current = &(dic->tab[h]);
		while(current != NULL && current->data != o)
			current = current->next;
	}

	return current != NULL && current->data == o;
}

int get_code(char* o, map* dic)
{
	int h = hash(o);
	elem* current;

	if(h > dic->size)
		return 0;

	current = &(dic->tab[h]);

	if(current == NULL)
		return 0;

	while(current !=  NULL && current->data != o)
		current == current->next;

	if(current == NULL)
		return 0;

	return current->code;
}