/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#ifndef _BIN_
#define _BIN_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * LIT LE BINAIRE
 * bin -> 9bits -> Décomprésseur
 * @param file : Fichier entree
 * @param taille : Taille du dico
 * @param k : Le reste du buffer vari de 1 à 8
 * @param buffer : Buffer de reception  contient les bits restants après la lecture et ensuite mis à jour
 * @return : Le code sur taille bit
 */
int read_code(FILE* file, int taille, int k, int* buffer);

/*
 * Texte -> Compresseur -> 8bits
 * @param file : Fichier sortie
 * @param code : Code du caractère 
 * @param taille : Taille du dico
 * @param buffer : Buffer d'envoie  contient les bits restants après la lecture et ensuite mis à jour
 * @param k : Le reste du buffer vari de 8 à 1
 * @return : Le code sur 8 bit
 */
void write_code(FILE* file, int code, int taille, char* buffer, int k);

/*
 * Ecrit un caractere dans le fichier spécifié
 * @param fichier : Fichier sortie 
 * @param car : Caractere à insérer dans le fichier
 */
void write (FILE* fichier, char car);

/*
 * Lit un caractere dans le fichier spécifié
 * @param fichier : Fichier entree
 * @return : Le code ASCII du caractere
 */
int read (FILE *fichier);

#endif
