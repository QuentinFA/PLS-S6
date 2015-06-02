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
#include "data.h"

/*
 * Création d'une donnée à partir d'un tableau d'entiers
 * @param tab : Le tableau contenant les données
 * @param tab_size : Le nombre de données dans le tableau
 * @return : La structure data contenant les valeurs du tableau
 */
data* create_data(int* tab, int tab_size)
{
	int i;
	data *d, *current;

	d = malloc(sizeof(data));
	if(d == NULL)
	{
		fprintf(stderr, "Allocation error : data.c/create_data\n");
		exit(EXIT_FAILURE);
	}

	current = d;
	current->d = tab[0];

	for(i = 1; i < tab_size; i++)
	{
		current->next = malloc(sizeof(data));
		current = current->next;

		if(current == NULL)
		{
			fprintf(stderr, "Allocation error : data.c/create_data\n");
			exit(EXIT_FAILURE);
		}

		current->d = tab[i];
	}

	current->next = NULL;

	d->size = tab_size;

	return d;
}

/*
 * Comparaison de deux data
 * @param d1 : La première donnée
 * @param d2 : La seconde donnée
 * @return : Un bolléen indiquant si les deux data sont égales
 */
bool data_equals(data d1, data d2)
{
	if(d1.size != d2.size || d1.d != d2.d)
		return false;

	data *c1 = d1.next, *c2 = d2.next;

	while(c1 != NULL && c1->d == c2->d)
	{
		c1 = c1->next;
		c2 = c2->next;
	}

	return c1 == NULL && c2 == NULL;
}

/*
 * Supression d'une donnée
 * @param d : La data à effacer
 */
void remove_data(data* d)
{
	data *c, *p;

	p = d;
	c = d->next;

	while(c != NULL)
	{
		free(p);
		p = c;
		c = c->next;
	}

	free(p);
}

/*
 * Ajouter une partie à une donnée existante
 * @param d : La data à modifier
 * @param add : La valeur à ajouter
 */
void add_data(data* d, int add)
{
	data* c;

	if(d != NULL)
	{
		c = d;
		while(c->next != NULL)
			c = c->next;
		c->next = malloc(sizeof(data));
		c->d = (short int) add;
		c->next->next = NULL;
		c->next->size = 0;
		d->size++;
	}
}

/*
 * Fusion de 2 données dans la 1ere
 */
void fus_data(data* d1, data* d2)
{
	if(d1 == NULL || d2 == NULL)
		return;

	data* c;

	c = d1;

	d1->size += d2->size;

	while(c->next != NULL)
		c = c->next;

	c->next = d2;
}

/*
 * Fonction de hashage
 */
int hash(data o)
{
	data *c = &o;
	int h = 0;

	while(c != NULL)
	{
		h += c->d;
		c = c->next;
	}

	return h;
}