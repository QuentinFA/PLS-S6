/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#ifndef _DATA_H
#define _DATA_H

#include <stdbool.h>

/*
 * Structure pour les données sur plusieurs octets
 * byte : Contient la valeur pour cet octet
 * next_byte : Adresse de l'octet suivant
 */
typedef struct data data;
struct data
{
	short int d;
	data *next;
	int size;
};

/*
 * Création d'une donnée à partir d'un tableau d'entiers
 * @param tab : Le tableau contenant les données
 * @param tab_size : Le nombre de données dans le tableau
 * @return : La structure data contenant les valeurs du tableau
 */
data* create_data(int* tab, int tab_size);

/*
 * Comparaison de deux data
 * @param d1 : La première donnée
 * @param d2 : La seconde donnée
 * @return : Un bolléen indiquant si les deux data sont égales
 */
bool data_equals(data d1, data d2);

/*
 * Supression d'une donnée
 * @param d : La data à effacer
 */
void remove_data(data* d);

/*
 * Fonction de hashage
 */
int hash(data o);

#endif