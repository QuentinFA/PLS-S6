#include <stdlib.h>
#include <stdio.h>
#include "dico.h"
#include "data.h"
#include <string.h>

int * codage(FILE* f, map* dic)
{ 
         dic = init_map();
         FILE* pfile=f;
         if(!(pfile=fopen(filename,"r")))
	 {
		 printf("faut");
	 }
	 fseek(pfile,0L,SEEK_END);
	 int flen=ftell(pfile);
	 char *p=(char*)malloc(flen+1);
         if(p==NULL)
         {
               fprintf(stderr, "Allocation error ");
		exit(EXIT_FAILURE);
         }
	 int *q=(int*)malloc(flen);
         if(q==NULL)
         {
               fprintf(stderr, "Allocation error ");
		exit(EXIT_FAILURE);
         }
	 fseek(pfile,0L,SEEK_SET);
	 fread(p,flen,1,pfile);
	 p[flen]=0;
	 int temp=0;
	 int count=1;
	 int sortie=0;
	 while(temp<(flen+1))
	 { 
		 data*d=create_data(&p[temp],count);
		 if(is_set(d,dic))
		 {
			 count++;
			 
		 }
		 else
		 {
			 
			 data*d2=creat_data(&p[temp],(count-1));
			 q[sortie]=get_code(d2,dic);
			 sortie++;
			 set_code(d,dic);
			 temp+=(count-1);
	     	 count=1;
		 }
	 }
	 int*output=(int*)malloc(sortie);
          if(output==NULL)
         {
             fprintf(stderr, "Allocation error ");
		exit(EXIT_FAILURE);
         }
	 for(int i=0;i<sortie;i++)
	 {
		 output[i]=q[i];
	 }
   return output;
     
}

} 
     
}
char*decodage(file *f , map*dic)
{ 
   FILE* pfile=f;
	 if(!(pfile=fopen(filename,"r")))
	 {
		 printf("faut");
	 }
	 fseek(pfile,0L,SEEK_END);
	 int flen=ftell(pfile);
	 int*p=(int*)malloc(flen);
         if(p==NULL)
         {
               fprintf(stderr, "Allocation error ");
		exit(EXIT_FAILURE);
         }
	 fseek(pfile,0L,SEEK_SET);
	 fread(p,flen,1,pfile);
	 int i=0;
	 data*dd;
	 char*prime;
	 char*sec;
	 while(i<flen)
	 {
		 dd=(data*)malloc(sizeof(data)*flen);
                 if(dd==NULL)
                   {
                    fprintf(stderr, "Allocation error ");
		    exit(EXIT_FAILURE);
                   }
		 dd[i]=get_data(p[i],dic);
		 prime=(char)*malloc((dd[i]->size)+1);
                 if(prime==NULL)
                   {
                    fprintf(stderr, "Allocation error ");
		    exit(EXIT_FAILURE);
                   }
                 data dtemp=dd[i];
		 for(int k=0;k<dd[i]->size;k++)
		 {
			 
			 prime[k]=dtemp->d;
			 dtemp=dtemp->next;
		 }
		 data dd[i+1]=get_data(p[i+1],dic);
		 if(dd[i+1]==NULL)
		 {
			 sec=(char*)malloc((dd[i]->size)*2);
                         if(sec==NULL)
                        {
                            fprintf(stderr, "Allocation error ");
		            exit(EXIT_FAILURE);
                         } 

       		         data dtemp1=dd[i];
                         data dtemp2=dd[i];	 
                        for(int k=0;k<(dd[i]->size)*2;k++)
			 {
				 
				 if(k<dd[i]->size)
				 {
				  
				   sec[k]=dtemp1->d;
				   dtemp1=dtemp1->next;
				 }
				 else
				 {
				   
				   sec[k]=dtemp2->d;
				   dtemp2=dtemp2->next;
				 }
			 }
		 }
		 else
		 {
			 sec=(char*)malloc(dd[i+1]->size);
                         if(sec==NULL)
                            {
                               fprintf(stderr, "Allocation error ");
		               exit(EXIT_FAILURE);
                            }
			 data dtemp4=dd[i+1];
			 for(int k=0;k<dd[i+1]->size;k++)
			 {
				 sec[k]=dtemp4->d;
				 dtemp4=dtemp4->next;
			 }
		 }
		 
		 prime[dd[i]->size]=sec[0];
		 data dtemp5=create_data(prime,(dd[i]->size)+1);
		 set_code(dtemp5,dic);
		 i++;
	 }
	 int temp=0;
	 for(int i=0;i<flen;i++)
	 {
		 temp+=dd[i]->size;
	 }
	 char*output=(char*)malloc(temp);
	 int count=0;
	 for(int i=0;i<flen;i++)
	 {
                 data dtemp=dd[i];
		 for(int j=0;j<dd[i]->size;j++)
		 {
			 output[count]=dtemp->d;
			 dtemp=dtemp->next;
			 count++;
		 }
	 }
	 return output;
}
