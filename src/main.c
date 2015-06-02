/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "codage.h"

#define _COMPRESS "-c"
#define _DECOMPRESS "-d"
#define _APP_NAME "lwz"
#define _EXTENSION ".lwz"

void help();
bool is_directory(const char *path);

int main(int argc, char* argv[])
{
	int i;
	char* out, *t;

	if(argc <= 2)
		help();
	else
	{
		if(!strcmp(argv[1], _COMPRESS))
		{
			for(i = 2; i < argc; i++)
			{
				if(access(argv[i], F_OK) == -1)
					printf("\t%s does not exist...\n", argv[i]);
				else if(is_directory(argv[i]))
					printf("\t%s is a directory\n", argv[i]);
				else
				{
					out = malloc(strlen((argv[i]) + 4) * sizeof(char));
					if(out == NULL)
					{
						fprintf(stderr, "Allocation error : main.c/main\n");
						exit(EXIT_FAILURE);
					}

					strcpy(out, argv[i]);
					strcat(out, _EXTENSION);
					printf("Compressing %s as %s...\n", argv[i], out);
					codage(argv[i], out);
					free(out);
				}
			}
		}
		else if(!strcmp(argv[1], _DECOMPRESS))
		{
			for(i = 2; i < argc; i++)
			{
				if(access(argv[i], F_OK) == -1)
					printf("\t%s does not exist...\n", argv[i]);
				else if(is_directory(argv[i]))
					printf("\t%s is a directory\n", argv[i]);
				else
				{
					if(strstr(argv[i], _EXTENSION) == NULL)
						printf("\t%s does not have the right extension.\n", argv[i]);
					else
					{
						out = malloc(strlen((argv[i]) - 4) * sizeof(char));
						if(out == NULL)
						{
							fprintf(stderr, "Allocation error : main.c/main\n");
							exit(EXIT_FAILURE);
						}

						strcpy(out, argv[i]);
						t = strstr(out, _EXTENSION);
						while(strstr(t + 1, _EXTENSION) != NULL)
							t = strstr(t + 1, _EXTENSION);
						*t = '\0';
						t = out;
						out = malloc((strlen(out) + 1) * sizeof(char));
						out[0] = '_';
						strcat(out, t);
						free(t);
						printf("Decompressing %s as %s...\n", argv[i], out);
						decodage(argv[i], out);
						free(out);
					}
				}
			}
		}
		else
			help();
	}

	return EXIT_SUCCESS;
}

void help()
{
	printf("Utilisation : %s [%s | %s] file1 [file2 ...]\n\t%s : Compression de fichiers\n\t%s : Décompression de fichiers\n", _APP_NAME, _COMPRESS, _DECOMPRESS, _COMPRESS, _DECOMPRESS);
}

bool is_directory(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}