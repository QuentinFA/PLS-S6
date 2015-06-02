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

#ifndef _CODAGE_H
#define _CODAGE_H

/*
 * Codage d'une donnee lu dans le fichier a coder
 * @param f_entrer : nom du fichier en entree (fichier a coder)
 * @param f_sortie : nom du fichier en sortie (fichier code)
 */
void codage(char* f_entrer,char* f_sortie);

/*
 * Decodage d'une donnee lu dans le fichier
 * @param o f : descripteur de fichier
 * @param dic : Le dictionnaire à modifier
 * @return : chaine de char qui a ete decode
 */
void decodage(char *name_in, char *name_out);

#endif