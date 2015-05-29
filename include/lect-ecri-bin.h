#ifndef _BIN_
#define _BIN_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/*LIT LE BINAIRE
// bin -> 9bits -> décomprésseur
//@param fichier entree
//@param taille du dico
//@param le reste du buffer vari de 1 à 8
//@param buffer de reception  contient les bits restants après la lecture et ensuite mis à jour
//@return le code sur taille bit
*/
int read_code(FILE* file, int taille, int k, int* buffer);

/*LIT LE BINAIRE
// texte -> compresseur -> 8bits
//@param fichier sortie
//@param code du caractère 
//@param taille du dico
//@param le reste du buffer vari de 8 à 1
//@param buffer d'envoie  contient les bits restants après la lecture et ensuite mis à jour
//@return le code sur 8 bit
*/
void write_code(FILE* file, int code, int taille, char* buffer, int k);

/*ecrit un caractere dans le fichier spécifié
//@param fichier sortie 
//@param caractere à insérer dans le fichier
//@return rien
*/
void write (FILE* fichier, char car);

/*lit un caractere dans le fichier spécifié
//@param fichier entree
//@return le code ASCII du caractere
*/
int read (FILE *fichier);

#endif
