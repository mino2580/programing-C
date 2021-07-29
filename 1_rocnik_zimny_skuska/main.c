
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>                   // kniznica pre bool
#define DELKA 3                      //definece pole
#define N 4                          // deklaracia pole o velikosti 4 cisel,,,,priklad pre kopirovanie  pole do pole
//#include "stdafx.h"                nefunguje  kniznica!!!!
#define POCET 3

//deklarace funkce,,ma nezavisle premenne ohladom celeho programu, 
//zavolam funkci a on mi priradi hodnotu a spat hodnoty vracia
int VratSoucet(int x, int y)  
 
{
	int soucet = x + y;

	return soucet;
}
// funkce void vynuluj, void nevracia ziadnu hodnotu ako pri return,,prepise 3 na nulu ,  
//  ,nema navratovy typ,0 plati len pre adresu priradenu pre x   vnutri funkcie void
void vynuluj(int x)
{
	x = 0;
	 
}


void Napln(int pole[], int pocetPrvku, int hodnota)
{
	for (int i = 0; i < pocetPrvku; i++)
	{
		pole[i] = hodnota;
	}
}

void pozdrav(void)
{
	printf("Ahoj, vrele tetu vitam!\n");
}

int obsahCtverce(int a, int b)
{
	int obsah = a * b;
	return obsah;
}

void reverze(int pole[], int delka_pole)
{
	// {1,2,3,4,5}
	for (int i = 0; i < delka_pole / 2; i++)
	{
		int pomocna = 0;
		pomocna = pole[i];
		pole[i] = pole[delka_pole - 1 - i];
		pole[delka_pole - 1 - i] = pomocna;

	}
}
void rada(void)
{
	for (int i = 0; i < 10; i++)
		printf(" %d \n", i);
}
/*
int vrat_naj_cis_v_poli(int pole, int delka)
{
	int  min;
	min = pole[delka];
	for (int i = 0; i < delka; i++)
		if (min < pole[i])
			min = pole[i];
	return(pole);
}
*/

int main()

{
//  funkce vrati nejvetsi prvek s pole
	/*
    
    int pole[]={0,2,3,4,5}
	int delka = sizeof(pole) / sizeof(int);
	vrat_naj_cis_v_poli(pole, delka);
*/
//  najmensi prvok pola,pocet sudych a lichych
/*
	int pole[] = { 5,1,2,3,4,7 };
	int delka = sizeof(pole) / sizeof(int);
	int min,i;
	min =pole[0];
	float prumer;
	int suda=0, licha=0;


	for (i = 0; i < delka; i++)
	{
		if (min > pole[i])
		{
			min = pole[i];
			printf("najmensi prvok pola je %d\n", min);
		}
	}


	printf("pole \n");
	for (i = 0; i < delka; i++)
	{
		

		printf(" %d\n", pole[i]);
	}
	prumer = delka / 2;
	printf("\nprumer je %.1f ",prumer);


	printf("  \n\n");
	for (i = 0; i < delka; i++)
	{
		if (pole[i] % 2 == 0)
		{
			suda++;
			printf("\t suda %d,\n", pole[i]);
		}
		else
		{
			licha++;
			printf(" licha  %d\n", pole[i]);
		}
	}
	printf("pocet sudych %d a pocet lichych je %d\n\n\n", suda, licha);
	printf("\n\n\n");
	*/


//  vytvor funkci ktera mi vypise libovolnou radu
/*
 void rada(void)
{
	for (int i = 0; i < 10; i++)
		printf(" %d \n", i);
}
*/   
/*
	rada();
	*/
 

//  funkce vynuluj ,typ void 
/*
int  x = 3;
vynuluj(x);
printf(" %d", x);
/*
/*

void vynuluj(int x)
{
	x = 0;
	 
}

*/


//  volani funkce vrat soucet
/*
int a = 3;
int b = 2;

int z = VratSoucet(a, b);
printf("soucet = %d\n", z);
 */


 // obsah ctverce pomoci funkci obsahctverce
/*

	   int a = 5;
	   int b = 10;
	   int i = 102;

	   int obsah = obsahCtverce(a, b);

	   printf("obsah ctverce=%d", obsah);
	   */


//  pole priradenie prvkov
/*
	   int pole[POCET] = { 0 };

	   Napln(pole, POCET, 1);
	   for (int i = 0; i < POCET; i++)
	   {
		   printf("%i ", pole[i]);
	   }
	*/

/*
int pole[10];
int i;
for (i = 0; i < 10; i++)
{
	pole[i] = i + 1;
}

for (i = 0; i < 10; i++)
{
	printf("%d ", pole[i]);
}
return (EXIT_SUCCESS);
*/


//  funkce k  void reverze(int pole[], int delka_pole)
/*
void reverze(int pole[], int delka_pole)      //funkce pro reverzni pole
{
	// {1,2,3,4,5}
	for (int i = 0; i < delka_pole / 2; i++)
	{
		int pomocna = 0;
		pomocna = pole[i];
		pole[i] = pole[delka_pole - 1 - i];
		pole[delka_pole - 1 - i] = pomocna;


	}
}

 
 */

 //      reverzni pole
 /* 
int pole[] = { 1,2,3,4,5 }; // {5,4,3,2,1}
for (int i = 0; i < sizeof(pole) / sizeof(int); i++)
{
	printf("%d ", pole[i]);

}

reverze(pole, sizeof(pole) / sizeof(int));

printf("\n");

for (int i = 0; i < sizeof(pole) / sizeof(int); i++)
{
	printf("%d ", pole[i]);

}
*/
 


	 //pole  nejmensi prvek

/*
int cisla[] = { 0, 1, 2, 3 };
	int min =cisla[0];
	int velikost_pole = sizeof(cisla) / sizeof(int);
	for (int i = 0; i < velikost_pole; i++)
	{
		if (min > cisla[i])
			min = cisla[i];


	}

	printf("pocet prvku  pole je :%d\n\n", velikost_pole);
	printf("nejmensi prvek pole je :%d", min);

	return 0;
	*/


//  zadani 7)   pole sude
/* 
 int pole[] = { 10,5,7,1,10,21 };
 int min = pole[0];   //najmensie cislo v poli
 int suma = 0;
 float prumer = 0;
 int sude = 0;

 for (int i = 0; i < 6; i = i + 1)
 {
	 if (min < pole[i])
		 min = pole[i];


 }
 printf("minimum je %d \n", min);

 for (int i = 0; i < 6; i = i + 1)
 {
	 suma += pole[i];


 }
 printf("\n suma %d ", suma);
 printf("\n");
 prumer = suma / 6;
 printf("prumer pole je %f\n", prumer);

 for (int i = 0; i < 6; i = i + 1)
 {
	 if (pole[i] % 2 == 0)
		 sude = sude + 1;

 }
 printf("sude cisla %d", sude);
   */


 //  priradeni hodnot prvku poli
/*
int pole[DELKA] = { 0 };

for (int i = 0; i < DELKA; i++)
{
	pole[i] = i * 2;
	int n;
	n = pole[i];
	printf("\t%d ", n);
}
//tisk prvku v poli,ziskavanie prvkov pola
for (int i = 0; i < DELKA; i++)
{

	int prvek = pole[i];

	printf("\n%d ", prvek);
}
 */


//  pole 2  bool testRovnostiHodnot = true 
/*
int poleA[] = { 0, 1, 2, 3 };
int poleB[] = { 0, 2, 2, 3 };

bool testRovnostiHodnot = true;
for (int i = 0; i < 4; i++)
{
	if (poleA[i] != poleB[i])
	{
		testRovnostiHodnot = false;
		break;
	}
}
*/


 //  kopirovanie poli
/*
int poleA[N] = { 0, 1, 2, 3 };
int poleB[N] = { 0 };

for (int i = 0; i < N; i++)
{
	poleB[i] = poleA[i];
}
*/


//  vypise pocet prvkov pole,velikost  pole
/* 
int pole[] = { 0,1,2,4,5 };
int velikost_pole = sizeof(pole) / sizeof(int);
printf(" velikost pole je %d \n", velikost_pole);

for (int i = 0; i < velikost_pole; i++)
{
	int prvky_pola =   pole[i];
	printf("\n %d \n", prvky_pola);
	 
	*/ 


//  porovnavanie dvoch poli
 /* 
int poleA[] = { 0, 1, 2, 3 };
int poleB[] = { 0, 2, 4, 3 };
int a, b,c,d;
//bool testRovnostiHodnot = true;           //funguje to aj bez toho
for (int i = 0; i < 4; i++)
{
	 
	 
	if (poleA[i] != poleB[i])
	{
		a = poleA[i];
		b = poleB[i];
		printf("\nprvek pole a %d  a prvek pole b %d sa nerovnaju\n", a, b);
		//testRovnostiHodnot = false;
		//break;
	}
}
for (int i = 0; i < 4; i++)
{
	c = poleA[i];

	printf("\npole a je %d ", c);
}
printf("\n\n");
for (int i = 0; i < 4; i++)
{
	d = poleB[i];

	printf("\npole b je %d ", d);
}
	*/
	

//  getchar
 /*
   int z = 0;
   while ((z = getchar()) != EOF)
   {
	   putchar(z);
   }
   return 0;
   */

   
//  test ci je cislo sude nebo liche 
/*
int x, y;

	printf("\n Program zisti ci zadene cislo je su nebo liche\n\n zadejte cele cislo");
	scanf_s(" \n%d", &x);
	y = x % 5;

	if (y==0)
	{
		printf("\n cislo %d je sude,zbytek je %d   ", x,y);
	}

	else
	{
		printf("\n cislo %d je liche,zbytek je %d    ", x,y);
	}
	 */


//  delitelne 5 bez zvysku
/*  int x, y;

	printf("\n Program zisti ci zadene cislo je su nebo liche\n\n zadejte cele cislo");
	scanf_s(" \n%d", &x);
	y = x % 5;

	if (y ==0 )
	{
		printf("\n cislo %d je delitelne 5,   ", x );
	}

	else
	{
		printf("\n cislo %d nie je delitelne  5  bez zbytku ", x);
	}

	*/


//  jeden z testov je viac ako 15
/*
int x, y, z;
printf_s(" zadejte test 1\n");
scanf_s("%d", &x);
printf_s(" zadejte test 2\n");
scanf_s("%d", &y);
printf_s(" zadejte test 3\n");
scanf_s("%d", &z);
if (x > 15 || y > 15 || z > 15)
{
	printf_s(" \n\n alespon jeden test je vacsi ako 15\n\n");
}
else
{
	printf_s(" \n\n ziaden test je vacsi ako 15\n\n");
}
*/


// switsch
/*

// moje_prvni_app.cpp : Defines the entry point for the console application.

//



#include "stdafx.h"

#include <math.h>



int main()

{

int stranaA=0, stranaB=0, stranaC=0, menu, obvod=0, s=0;

float obsah=0;

printf("pro vypocet trojuhelniku stiskni 1\npro vypocet ctverce stiskni 2\n");

scanf("%i", &menu);



switch (menu)

{

case 1:

printf("zadej strany trojuhelniku v celych cislech a oddelene mezerou: ");

scanf("%d %d %d", &stranaA, &stranaB, &stranaC);



if ((stranaA + stranaB > stranaC) && (stranaB + stranaC > stranaA) && (stranaA + stranaC > stranaB))

{



obvod = stranaA + stranaB + stranaC;

s = obvod / 2;

obsah = sqrt(s*(s - stranaA)*(s - stranaB)*(s - stranaC));



printf("obvod trojuhelniku je:%d\n", obvod);

printf("obsah trojuhelniku je:%.2f\n", obsah);



}

else

{

printf("CHYBA ZADANI: nesestrojitelny trojuhelnik");

}

break;

case 2:

printf("zadej stranu: ");

scanf("%d", &stranaA);

obvod = 4 * stranaA;

obsah = pow(stranaA, 2);

printf("obvod ctverce je:%d\n", obvod);

printf("obsah ctverce je:%.0f\n", obsah);

break;

default: printf("chyba zadani, mel jsi stisknout 1 nebo 2");

}







	return 0;
	*/


// kasdy test je vacsi ako 15
/*
int x, y, z;
printf_s(" zadejte test 1\n");
scanf_s("%d", &x);
printf_s(" zadejte test 2\n");
scanf_s("%d", &y);
printf_s(" zadejte test 3\n");
scanf_s("%d", &z);
if (x > 15 && y > 15 && z > 15)
{
	printf_s(" \n\n kasdy test je vacsi ako 15\n\n");
}
else
{
	printf_s(" \n\n nie su vsetky testy  vacsie ako 15\n\n");
}
*/


//zadani cislo 4) test int test1 = 5, test2 = 20, test3 = 13;
/*
	int test1 = 5, test2 = 20, test3 = 13;
	int max = 20;
	int min = 0.6*max;
	int uspech = 0;

// reseni 1.
	if (test1 >= min && test2 >= min)
		printf("uspel\n");
	else if (test3 >= min && test2 >= min)
		printf("uspel\n");
	else if (test3 >= min && test1 >= min)
		printf("uspel\n");
	else
		printf("neuspel\n");

// reseni 2.
	if (test1 >= min)
		uspech++;
	if (test2 >= min)
		uspech++;
	if (test3 >= min)
		uspech++;
	if (uspech>=2)
		printf("uspel\n");
	else
		printf("neuspel\n");
 */


 // aspon 2 testy su viac ako 15
/*
int x, y, z;
printf_s(" zadejte test 1\n");
scanf_s("%d", &x);
printf_s(" zadejte test 2\n");
scanf_s("%d", &y);
printf_s(" zadejte test 3\n");
scanf_s("%d", &z);
if (x > 15 && y > 15 || x > 15 && z>15 || y>15 && z>15 )
{
	printf_s(" \n\n dva  testy su viac ako 15\n\n");
}
else
{
	printf_s(" \n\n nie su dva testy viac ako 15\n\n");
}
*/


//suda licha cisla zadejte 10 cisel
/*

int suda = 0, licha = 0, cislo = 0; // deklarace integeru

printf("Zadejte 10 libovolnych cisel a pokazde odradkujte enterem \nProgram vypise kolik jich je sudych a kolik lichych\n"); // privitani v programu

//pro i rovno 0 mensi jak 10 i++ - cili vykonej 10x
for (int i = 0; i < 10; i++)
{

	scanf_s("%d", &cislo); // nacte zdane cislo

	//pokud zadane cislo deleno 2 vyjde beze zbytku tak se k sudym pricte jednicka '%' je modulo zbytek po deleni
	if (cislo % 2 == 1)
	{
		//printf("%d", cislo);

		 suda++;
	}




	//jinak pricte licha
	else
	{
		licha++;
	}

}

//vypise se kolik je sudych a lichych
printf("Sudych je %d, lichych je %d \n", suda, licha);

  */


  //zadani cislo 4) test int test1 = 5, test2 = 20, test3 = 13;
/*
	  int test1 = 5, test2 = 20, test3 = 13;
	  int max = 20;
	  int min = 0.6*max;
	  int uspech = 0;

  // reseni 1.
	  if (test1 >= min && test2 >= min)
		  printf("uspel\n");
	  else if (test3 >= min && test2 >= min)
		  printf("uspel\n");
	  else if (test3 >= min && test1 >= min)
		  printf("uspel\n");
	  else
		  printf("neuspel\n");

  // reseni 2.
	  if (test1 >= min)
		  uspech++;
	  if (test2 >= min)
		  uspech++;
	  if (test3 >= min)
		  uspech++;
	  if (uspech>=2)
		  printf("uspel\n");
	  else
		  printf("neuspel\n");
   */


 // modulo
/*
int x = 6;
int y = -3;

int v1 = x % 2; // v1 = 0
int v2 = x % 5; // v2 = 2
printf(" %d \n", v1);
 */


 // cyklus for 256 128 64 32 16
/*
int i;
for (i = 256; i <= 256 && i >= 16; i = i / 2)
{
	printf(" %d", i);
}
*/


//cyklus for 10,100,1000,10000,1 000 000
/*
int i;
for (i = 10; i <= 10000; i*=10)
{
	printf(" %d", i);

}
if (i = 10000);
i *= 100;
printf(" %d", i);
*/


//cyklus for licha cisla a zaroven vetsi nez 10
/*
	for (int i = 11; i > 10 && i < 100; i++)
	{
		if (i % 2 == 1)
		{
			printf("\n liche cislo %d", i);
		}
	}
	*/


//rada pomoci   cyklus for,while,do while
/*
int x = 100;

printf("rada 100 - 96 pomoci FOR\n");

for (int i = 100; i > 95; i--)

{

	printf("%d, ", i);

}

*/

/*

int x = 100;
printf("rada 100 - 96 pomoci DO-WHILE\n");

do

{

	printf("%d ", x);

	x--;

} while (x >= 96);

printf("\n\n");



printf("rada 100 - 96 pomoci WHILE\n");

*/

/*
	int x=100;
while (x > 95)

{

	if (x > 96)

	{

		printf("%i, ", x);

	}

	else
	{
		printf("%i, ", x);
	}
	--x;

}

printf("\n");

 */


 // zadani  6     )for (int i = 10; i <= 1000000; i = i * 10)
/*
   for (int i = 10; i <= 1000000; i = i * 10)
	  {
		  if (i != 100000)
			  printf("%d ", i);

	  }
	  printf("\n");

	  int i = 1;

	  do {
		  i = i * 10;
		  if (i != 100000)
			  printf("%d ", i);


	  } while (i <= 100000);

	  printf("\n");
	  int x = 10;
	  while (x<= 1000000) {
		  if(x!=100000)
			  printf("%d ", x);
		  x *= 10;
	  }
		*/


////kalkulacka  switsch   nefunkcni
 
int cisloA = 0;
int cisloB = 0;
char operace, opakovani;



	printf("zadejte vyraz ve formatu [cislo][operace][cislo]:");           // 4+5
	scanf("\n%d%c%d", &cisloA, &operace, &cisloB);
	while (true)
	{
		switch (operace)
		{
		case '+': printf("vysledek = %d", cisloA + cisloB);
			break;
		case '-': printf("vysledek = %d", cisloA - cisloB);
			break;
		case '*': printf("vysledek = %d", cisloA * cisloB);
			break;
		case '/': printf("vysledek = %.1f", cisloA / cisloB);
			break;
		default: printf("neznamy operator");
			break;




			printf("pro ukonceni programu stisknete K(onec)");

			scanf(" %c", &opakovani);

			if (opakovani == 'K' || opakovani == 'k')

				break;
		}
	}
	 








  
	 
return(0);
}