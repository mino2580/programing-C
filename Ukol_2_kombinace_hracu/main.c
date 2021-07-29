#include <stdio.h>
#include <string.h>

int main()
{
	 
	//pokracovanie
	
	 puts("zadej jmena  hrac:");
   int pocet=0;
   char jmenaHracu[256][256];
  
 while(fgets(jmenaHracu[pocet],256,stdin)!=NULL)
   {
	   char*jmeno=jmenaHracu[pocet];
	                                   printf("*jmeno=%d\n",*jmeno);
	   int indexKonce=strlen(jmeno)-1;
	                                   printf("indexKonce=%d\n",indexKonce);
	   
	   jmeno[indexKonce]=0;
	                                  printf("jmeno[indexKonce]=%d\n",jmeno[indexKonce]);
	   pocet++;
	    printf(" pocet++;%d\n", pocet );
	   }
	   
   for(int i=0;i<pocet ;i++)
   for(int j=i+1;j<pocet;j++)
	  printf("%s,%s\n",jmenaHracu[i],jmenaHracu[j]);
	return 0;
}
