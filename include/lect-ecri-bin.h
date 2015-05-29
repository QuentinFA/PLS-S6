#ifndef _BIN_
#define _BIN_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

int read_code(FILE* file, int taille, int k, int* buffer);
void write_code(FILE* file, int code, int taille, char* buffer, int k);
void write (FILE* fichier, char car);
int read (FILE *fichier);

#endif
