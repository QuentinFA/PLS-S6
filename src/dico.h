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

#define BEGINING_SIZE 32

typedef struct elem elem;
struct elem
{
	char* data;
	int code;
	elem* next;
};

typedef struct map map;
struct map
{
	int size;
	elem* tab;
};

/*
 * Initialisation d'un dictionnaire
 * @param dic : Un pointeur vers le dictionnaire à créer
 */
void init(map* dic);

/*
 * Ajoute un code correspondant à une donnée
 * @param o : La donnée
 * @param dic : Le dictionnaire à modifier
 * @param code : Le code correspondant à o à ajouter
 * @return : True si l'ajout a réussi, False sinon
 */
bool set_code(char* o, map* dic, int code);

/*
 * Fonction de hashage TODO
 */
int hash(char* o);

/*
 * Vérifie si une donnée est présente dans la map
 * @param o : La donnée recherchée
 * @param dic : Le dictionnaire dans lequel chercher
 * @return : Un booléen testant la présence de o dans dic
 */
bool is_set(char* o, map* dic);

/*
 * Permet de récupérer le code d'une donnée dans la map
 * @param o : La donnée
 * @param dic : Le dictionnaire
 * @return : Le code correspendant à la donnée
 */
int get_code(char* o, map* dic);

#endif