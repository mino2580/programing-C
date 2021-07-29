 
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int main()
{
	  FILE * p_soubor_2 = fopen("output_2.csv", "w");
    if (p_soubor_2 == NULL)
    {
        printf("Soubor se nepodařilo otevřít pro zápis, zkontrolujte prosím oprávnění.");
        return 1;
    }
	
	
	 
	
	 //cteni ze souboru
	 /*
	      FILE * p_soubor = fopen("dopis.txt", "r");
    if (p_soubor == NULL)
    {
        printf("Soubor se nepodařilo otevřít pro čtení, zkontrolujte prosím zda existuje.");
        return 1;
    }

    char buffer[1024];
    while (fscanf(p_soubor, " %1023[^\n]", buffer) != EOF)
    {
        printf("%s\n", buffer);
    }

    if (fclose(p_soubor) == EOF)
    {
        printf("Soubor se nepodařilo uzavřít.");
        return 1;
    }
	  */
	
     
	 
 int vek = 20;
    int vyska = 150, vaha = 50;
    char jmeno[256];
    int status;
    char retezec[256];
	char nejmladsi[256];
	char nejstarsi[256];
	int soucet_veku=0,soucet_vysky=0,soucet_vahy=0;
	 int pocet_radku=0; 
	 int min_vek=0,max_vek=0;
	 //puts dava novy radek bez\n
    // puts("Zadej CSV radky ve formatu jmeno;vek;vyska;vaha;");
    // puts("Konec=EOF neboli na klavesnici CTRL+Z...");
	
	//fscanf nacita ze souboru,to same scanf nacita s klavesnice
	FILE * p_soubor = fopen("data.csv", "r");//otevreni datoveho proudu
	 if (p_soubor == NULL)
    {
        printf("Soubor se nepodařilo otevřít pro čtení, zkontrolujte prosím zda existuje.");
        return 1;
    }
	 
	
	//fgets nacitani jedneho radku,ze souboru do retezca
	   while   (fgets(retezec, sizeof(retezec), p_soubor) != NULL)
    {
		
		 
		//printf("%s ",retezec);
        // printf("%s;%lf;%d;%d;\n", jmeno, &vek, &vyska, &vaha);
        //rozfazovani do scanf 
		//sscanf nacita retezce bufera,scanf nacita s klavesnice
		//vstup se bere retezece,s tama se to ma brat
        status = sscanf(retezec, "%[^;];%d;%d;%d;", jmeno, &vek, &vyska, &vaha);
        //sscanf 
        // printf("Status=%d, jmeno=%s, vek=%.2f, vyska=%d a vaha=%d\n", status, jmeno, vek, vyska, vaha);
        if (status<4)//eof nemuze nastat
        {
			
            printf("Chyba! Cekal jsem cislo, ne: %s\n", retezec);
        }
     else
	 {
		 if(pocet_radku==0)
	     {
		 max_vek=vek;
		 min_vek=vek;
		 }
		 
		if(vek>max_vek)
		{
		max_vek=vek;
		strcpy(nejstarsi,jmeno);//kopirovani textoveho pole do pole jmeno
		}
		
		if(vek<min_vek)
		{
			strcpy(nejmladsi,jmeno);
		min_vek=vek;
		}
 
          
		 
		 soucet_veku+=vek;
		 soucet_vysky+=vyska;
         soucet_vahy+=vaha;
		 pocet_radku++;
		  
	 }
	 
	}
printf("Prumerna vaha je: %d kg\n",soucet_vahy/pocet_radku);
fprintf(p_soubor_2, "Prumerna vaha je: %d kg\n",soucet_vahy/pocet_radku );

printf("Prumerna vyska je: %d cm\n",soucet_vysky/pocet_radku);
fprintf(p_soubor_2,"Prumerna vyska je: %d cm\n",soucet_veku/pocet_radku);

printf("Prumerny vek je: %d\n",soucet_veku/pocet_radku);
fprintf(p_soubor_2,"Prumerny vek je: %d\n",soucet_veku/pocet_radku);

printf("Nejmladsim je %s s vekem %d\n",nejmladsi,min_vek);
fprintf(p_soubor_2,"Nejmladsim je %s s vekem %d\n",nejmladsi,min_vek);

printf("Nejstarsim je %s s vekem %d\n",nejstarsi,max_vek);
fprintf(p_soubor_2,"Nejstarsim je %s s vekem %d\n",nejstarsi,max_vek);
     
	 if (fclose(p_soubor) == EOF)         //podminka ukonceni,zavreni suboru
    {
        printf("Soubor se nepodařilo uzavřít.");
        return 1;
    }	

 
    //fprintf(p_soubor_2, "opatruj se, Malcolm unikl a jistě si pro mne brzy přijde jako pro prvního.\n");
    //fprintf(p_soubor_2, "Musíš navést Brandona, dovést ho k amuletu, klíčem k zaříkávadlu by možná\n");
    //fprintf(p_soubor_2, "mohla být levandulová růže.\n\n");
    //fprintf(p_soubor_2, "Kallak\n");




  
  //fprintf(p_soubor_2,retezec);
  

   if (fclose(p_soubor_2) == EOF)
    {
        printf("Soubor se nepodařilo uzavřít.");
        return 1;
    }
 
	/*  
    double vek = 20;
    int vyska = 150, vaha = 50;
    char jmeno[256];
    int status;
    char retezec[256];
	char nejmladsi[256];
	char nejstarsi[256];
	double soucet_veku=0,soucet_vysky=0,soucet_vahy=0;
	 int pocet_radku=0; 
	 double min_vek=0,max_vek=0;
	 //puts dava novy radek bez\n
     puts("Zadej CSV radky ve formatu jmeno;vek;vyska;vaha;");
     puts("Konec=EOF neboli na klavesnici CTRL+Z...");
    while (fgets(retezec, 256, stdin) != NULL)//vysani retezce do buferu,ak sa nenacita,cyklus neprobehne
	{
	    //rozfazovani do scanf 
		//sscanf nacita retezce bufera,scanf nacita s klavesnice
       
		//vstup se bere retezece,s tama se to ma brat
        status = sscanf(retezec, "%[^;];%lf;%d;%d;", jmeno, &vek, &vyska, &vaha);
       //sscanf 
        printf("Status=%d, jmeno=%s, vek=%.2f, vyska=%d a vaha=%d\n", status, jmeno, vek, vyska, vaha);
        if (status<4)//eof nemuze nastat
        {
			
            printf("Chyba! Cekal jsem cislo, ne: %s\n", retezec);
        }
     else
	 {
		 if(pocet_radku==0)
	     {
		 max_vek=vek;
		 min_vek=vek;
		 }
		 
		if(vek>max_vek)
		{
		max_vek=vek;
		strcpy(nejstarsi,jmeno);//kopirovani textoveho pole do pole jmeno
		}
		
		if(vek<min_vek)
		{
			strcpy(nejmladsi,jmeno);
		min_vek=vek;
		}
 
		 soucet_veku+=vek;
		 soucet_vysky+=vyska;
         soucet_vahy+=vaha;
		 pocet_radku++;
		  
	 }
	 
	}
printf("pocet radku=%d, prumerny vek =%.2lf, vyska=%lf a vaha=%lf\n",
 pocet_radku,soucet_veku/pocet_radku,soucet_vysky/pocet_radku,soucet_vahy/pocet_radku);
 printf("max vek %.2lf,min vek %.2lf,nejmladsi %s,nejstarsi %s,",
 max_vek,min_vek,nejmladsi,nejstarsi);
//open shel   Debug\Ukol_1_Csv.exe < data.csv
 */
 
 //druha verze
 /*
  double vek = 20;
    int vyska = 150, vaha = 50;
    char jmeno[256];
    int status;
    do {
        printf("Zadej jmeno, vek, vysku a vahu:\n");
        status = scanf("%[^;];%lf;%d;%d;", jmeno, &vek, &vyska, &vaha);
        printf("Status=%d, jmeno=%s, vek=%.2f, vyska=%d a vaha=%d\n", status, jmeno, vek, vyska, vaha);
        if (status<4 && status!=EOF) {
            char retezec[256];
            fgets(retezec, 256, stdin);
            printf("Chyba! Cekal jsem cislo, ne: %s\n", retezec);
        }
    } while (status != EOF);
	 */
 
 return 0;
 
 
}

 