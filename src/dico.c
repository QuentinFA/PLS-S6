/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "dico.h"
#include "data.h"

/*
 * Initialisation d'un dictionnaire
 * @return : Un pointeur vers le dictionnaire à créer
 */
map* init_map()
{
	int i;
	map* dic;

	dic = malloc(sizeof(map));

	if(dic == NULL)
	{
		fprintf(stderr, "Allocation error : dico.c/init_map\n");
		exit(EXIT_FAILURE);
	}

	dic->tab = calloc(BEGINING_SIZE, sizeof(elem));

	if(dic->tab == NULL)
	{
		fprintf(stderr, "Allocation error : dico.c/init_map\n");
		exit(EXIT_FAILURE);
	}

	dic->nb_elem = 0;
	dic->size = BEGINING_SIZE;
	dic->code_size = 9;

	// Initialisation des valeurs possibles et de leur encodage sur 1 octet et EOF = 256
	for(i = 0; i < 256; i++)
	{
		set_code(create_data(&i, 1), dic);
	}

	i = _EOF;
	set_code(create_data(&i, 1), dic);

	return dic;
}

/*
 * Ajoute un code correspondant à une donnée
 * @param o : La donnée
 * @param dic : Le dictionnaire à modifier
 */
 void set_code(data* o, map* dic)
{
	if(is_set(*o, dic))
		return;

	int h = hash(*o) % dic->size;
	elem* add_here;

	add_here = dic->tab[h];

	// Gestion des collisions avec une liste
	if(add_here != NULL)
	{
		while(add_here->next != NULL)
			add_here = add_here->next;
		add_here->next = calloc(1, sizeof(elem));

		if(add_here == NULL)
		{
			fprintf(stderr, "Allocation error : dico.c/set_code\n");
			exit(EXIT_FAILURE);
		}

		add_here = add_here->next;
	}
	else
	{
		add_here = calloc(1, sizeof(elem));

		if(add_here == NULL)
		{
			fprintf(stderr, "Allocation error : dico.c/set_code\n");
			exit(EXIT_FAILURE);
		}
		
		dic->tab[h] = add_here;
	}

	if(add_here == NULL)
	{
		fprintf(stderr, "Allocation error : data.c/create_data\n");
		exit(EXIT_FAILURE);
	}

	add_here->data = o;
	add_here->code = dic->nb_elem++;

	if(dic->nb_elem >= 2 << dic->code_size)
		dic->code_size++;

}

/*
 * Vérifie si une donnée est présente dans la map
 * @param o : La donnée recherchée
 * @param dic : Le dictionnaire dans lequel chercher
 * @return : Un booléen testant la présence de o dans dic
 */
bool is_set(data o, map* dic)
{
	int h = hash(o) % dic->size;
	elem* current;

	if(dic->tab[h] == NULL)
		return false;

	if(data_equals(*(dic->tab[h]->data), o))
		return true;
	else
	{
		current = dic->tab[h];
		while(current != NULL && !data_equals(*(current->data), o))
		{
			current = current->next;
		}
	}

	return current != NULL && data_equals(*(current->data), o);
}

/*
 * Permet de récupérer le code d'une donnée dans la map
 * @param o : La donnée
 * @param dic : Le dictionnaire
 * @return : Le code correspendant à la donnée
 */
int get_code(data o, map* dic)
{
	int h = hash(o) % dic->size;
	elem* current;

	/*if(h > dic->size)
		return NO_CODE;*/

	current = dic->tab[h];

	if(current == NULL)
		return NO_CODE;

	while(current !=  NULL && !data_equals(*(current->data), o))
		current = current->next;

	if(current == NULL)
		return NO_CODE;

	return current->code;
}

/*
 * Récupération de la donnée corrrespondant à un code
 * @param code : Le code dont on veut la donnée
 * @param dic : Un pointeur sur le dictionnaire dans lequel chercher
 * @return : La donnée correspondante, ou NULL si non présent
 */
data* get_data(int code, map* dic)
{
	// TODO : A optimiser en temps de recherche (Not optimized)
	elem* current;
	int i;

	for(i = 0; i < dic->size; i++)
	{
		current = dic->tab[i];
		if(current != NULL)
		{
			while(current != NULL && current->code != code)
				current = current->next;
			if(current != NULL && current->code == code)
				return current->data;
		}
	}

	return (data*) NULL;
}

/*
 * Supprime un dictionnaire
 * @param dic : Un pointeur sur le dictionnaire à supprimer
 */
void free_map(map* dic)
{
	elem* prev, *current;
	int i;

	for(i = 0; i < dic->size; i++)
	{
		if(dic->tab[i] != NULL)
		{
			current = dic->tab[i];
			while(current != NULL)
			{
				prev = current;
				current = current->next;
				remove_data(prev->data);
				free(prev);
			}
		}
	}
	free(dic);
}