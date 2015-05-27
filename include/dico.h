/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 * Sara OOUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#ifndef _DICO_H
#define _DICO_H

#include <stdbool.h>

typedef struct elem elem;
struct elem
{
	char data;
	int code;
	elem* g;
	elem* d;
};

/*
 *
 */
elem* init();

/*
 *
 */
bool set_code(char o, elem* dic);

/*
 *
 */
bool is_set(char o, elem* dic);

/*
 *
 */
int get_code(char o, elem* dic);

/*
 *
 */
int get_code(char o, elem* dic);

#endif