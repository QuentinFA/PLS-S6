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
#include <string.h>


/*
 * Codage d'une donnee lu dans le fichier a coder
 * @param o f : descripteur de fichier
 * @param dic : Le dictionnaire à modifier
 * @return : l'entier du mot code
 */
int * codage(FILE* f, map* dic);

/*
 * Decodage d'une donnee lu dans le fichier
 * @param o f : descripteur de fichier
 * @param dic : Le dictionnaire à modifier
 * @return : chaine de char qui a ete decode
 */
char*decodage(FILE* f , map* dic);
