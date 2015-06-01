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
//#include "codage.h"

#define _COMPRESS "-c"
#define _DECOMPRESS "-d"
#define _APP_NAME "lwz"
#define _EXTENSION ".lwz"

void help();
bool is_directory(const char *path);

int main(int argc, char* argv[])
{
	int i;
	char* out;

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
					strcpy(out, argv[i]);
					strcat(out, _EXTENSION);
					printf("Compressing %s as %s...\n", argv[i], out);
					// SEND TO COMPRESS FUNC
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
						strcpy(out, argv[i]);
						*(strstr(out, _EXTENSION)) = '\0';
						printf("Decompressing %s as %s...\n", argv[i], out);
						// SEND TO DECOMPRESS FUNC
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