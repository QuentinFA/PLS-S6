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
#include "data.h"

#define BEGINING_SIZE 512
#define NO_CODE -1

typedef struct elem elem;
struct elem
{
	data* data;
	int code;
	elem* next;
};

typedef struct map map;
struct map
{
	int size;
	int nb_elem;
	elem** tab;
};

/*
 * Initialisation d'un dictionnaire
 * @param dic : Un pointeur vers le dictionnaire à créer
 */
map* init_map();

/*
 * Ajoute un code correspondant à une donnée
 * @param o : La donnée
 * @param dic : Le dictionnaire à modifier
 * @param code : Le code correspondant à o à ajouter
 * @return : True si l'ajout a réussi, False sinon
 */
void set_code(data* o, map* dic);

/*
 * Vérifie si une donnée est présente dans la map
 * @param o : La donnée recherchée
 * @param dic : Le dictionnaire dans lequel chercher
 * @return : Un booléen testant la présence de o dans dic
 */
bool is_set(data o, map* dic);

/*
 * Permet de récupérer le code d'une donnée dans la map
 * @param o : La donnée
 * @param dic : Le dictionnaire
 * @return : Le code correspendant à la donnée
 */
int get_code(data o, map* dic);

/*
 * Supprime un dictionnaire
 * @param dic : Un pointeur sur le dictionnaire à supprimer
 */
void free_m(map* dic);

#endif