/*************************************
 * Projet Logiciel Niveau Système    *
 *   Antoine BLANC - Quentin FAURE   *
 *  Sara OUNISSI - Adrien SIPASSEUTH *
 *             Sun BIN               *
 *              RICM 3               *
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dico.h"
#include "data.h"
#include "codage.h"
#include "rwbin.h"

/*
 * Codage d'une donnee lu dans le fichier a coder
 * @param f_entrer : nom du fichier en entree (fichier a coder)
 * @param f_sortie : nom du fichier en sortie (fichier code)
 */
void codage(char* f_entrer,char* f_sortie) 
{ 
	//Declaration du dico et initialisation
	map*dic = init_map(); 
	
	FILE* pfile; 

	//Ouverture du fichier
	if(!(pfile=fopen(f_entrer,"r"))) 
	{ 
		printf("faut"); 
	} 
	
	//Recupere le nombre d'element a lire dans le fichier ouvert
	fseek(pfile,0L,SEEK_END); 
	int flen=ftell(pfile); 
	
	//Declare un tableau ou on va stocker tous les element a lire
	//Dans le fichier
	int*p=(int *)malloc(flen*sizeof(int)); 

	if(p==NULL) 
	{ 
		fprintf(stderr, "Allocation error "); 
		exit(EXIT_FAILURE);
	} 

	//Declare le tableau qui va contenir les codes
	
	fseek(pfile,0L,SEEK_SET); 

 	//Lecture du fichier
	int i;  
	for(i=0;i<flen;i++) 
	{ 
		p[i]=fgetc(pfile); 
	} 

	//Declaration des variables pour le codage et l'ajoue dans le dico 
	int temp=0; 
	int count=1; 
	data* d1,*d2; 
	
	//Gestion de l'ecriture dans le fichier de sortie
	FILE* f_sor;                                                     
	int buffer=0;
	int reste=8; 
	if(!(f_sor=fopen(f_sortie,"wb"))) 
	{ 
		printf("faut"); 
	} 

	//Parcours le tableau de char
	//Si la chaine de char existe dans le dico on lui ajoute un nouveau char
	//Si la chaine n'existe pas on affiche le code de la chaine precendente
	//Dans le fichier de sortie, et on ajoute dans le dico la nouvelle chaine
	while(temp<flen) 
	{ 
		d1=create_data(&p[temp],count);  
		if(is_set(*d1,dic)) 
		{ 
			count+=1; 
		} 
		else 
		{ 
			d2=create_data(&p[temp],(count-1)); 
 
			if(temp<flen -1)
			{
				write_c(f_sor,get_code(*d2,dic),dic->code_size,&buffer,&reste);  
			}

			set_code(d1,dic); 
			temp+=(count-1);  
			count=1; 
		} 
	} 
	
	//Gestion de la fin de fichier
	int end = _EOF;
	data * fin=create_data(&end,1);
	write_c(f_sor,get_code(*fin,dic),dic->code_size,&buffer,&reste);
	
	//Liberation des pointeur
	free(p);
	free_map(dic);
}

void decodage(char *name_in, char *name_out)
{
	FILE *f_in, *f_out;
	int cr = 0, nb_prev = 0, n = 0, i_eof = _EOF;
	data* data, *d_eof = create_data(&i_eof, 1), *t, *f;
	map* d = init_map();

	f_in = fopen(name_in, "rb");
	if(f_in == NULL)
	{
		fprintf(stderr, "Null file pointer : codage.c/decodage\n");
		exit(EXIT_FAILURE);
	}

	f_out = fopen(name_out, "wb+");
	if(f_in == NULL)
	{
		fprintf(stderr, "Null file pointer : codage.c/decodage\n");
		exit(EXIT_FAILURE);
	}

	cr = read_c(f_in, d->code_size, &nb_prev, &n, n);
	data = get_data(cr, d);

	while(!data_equals(*data, *d_eof))
	{
		cr = read_c(f_in, d->code_size, &nb_prev, &n, n);
		fus_data(data, get_data(cr, d));

		while(is_set(*data, d))
		{
			cr = read_c(f_in, d->code_size, &nb_prev, &n, n);
			fus_data(data, get_data(cr, d));
		}

		set_code(data, d);

		t = data;
		f = data;

		// Ecriture de la donnée sauf la dernière partie, qui sera utilisée au prochain tour
		while(t->next != NULL && t != NULL)
		{
			write_b(f_out, t->d);
			data = t;
			t = t->next;
		}

		data->next = NULL;
		remove_data(f);

		data = t;
		data->size = 1;
	}

	fclose(f_in);
	fclose(f_out);

}