/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#ifndef _RWBIN_H
#define _RWBIN_H

#define RW_SIZE 8

/*
 * Ecrit un code dans un fichier
 * @param file : Le fichier dans lequel lire
 * @param code_size : La taille du code à lire
 * @param nb_prev : Le décalage par rapport au code précédent lu, et celui pour le suivant en sortie
 * @param for_next : Le code qui sera utile pour la prochaine lecture
 * @param from_prev : Le code lu lors de la lecture précédente
 * @return : Le code lu
 * Exemple d'utilisation :
 * 		int cr = 0, nb_prev = 0, n;
 *		int i = 0;
 *		FILE* file = fopen("a.out", "rb");
 *
 *		do
 *		{
 *			cr = read_c(file, 9, &nb_prev, &n, n);
 *			i++;
 *		} while(cr != 256);
 */
int read_c(FILE* file, int code_size, int* nb_prev, int* for_next, int from_prev);

/*
 * Ecrit un caractere dans le fichier spécifié
 * @param fichier : Fichier sortie 
 * @param car : Caractere à insérer dans le fichier
 */
void write (FILE* file, unsigned char car);

/*
 * Texte -> Compresseur -> 8bits
 * @param file : Fichier sortie
 * @param code : Code du caractère 
 * @param taille : Taille du code
 * @param buffer : Buffer contenant le reste auquel le code suivant sera ajouté
 * @param k : Le nombre de bit à écrire pour completer l'octet
 * Exemple:
 * FILE *fichier_sortie;
 *
 * fichier_sortie = fopen("sortie.txt", "w+");
 *	
 *int buffer_env=0;
 * 
 *int reste = 8;
 *
 *writer_c(fichier_sortie, 'a', 9, &buffer_env, &reste);
 *writer_c(fichier_sortie, 'b', 9, &buffer_env, &reste);
 *writer_c(fichier_sortie, 256, 9, &buffer_env, &reste);
 */
void write_c(FILE* file, unsigned int code, unsigned int taille, int* buffer, int* reste);

#endif
