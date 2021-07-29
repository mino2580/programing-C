# ADT List #
Naprogramujte ADT List (lineární seznam).

Popis jednotlivých funkcí máte v souboru list.h, potřebnou teorii máte ve slajdech přednášky o seznamu.
```
#~/MathLib$ ./a.out 
List test program
Zadejte pismeno 0-A pro jednu z nasledujicich cinnosti:
0: Init,
1: Actualize,
2: Insert_First,
3: First,
4: Copy_First,
5: Delete_First,
6: Post_Delete,
7: Post_Insert,
8: Copy,
9: Succ,
A: Is_Active,
M: Vypis menu
CTRL+Z (Win) nebo CTRL+D (Unix): Konec programu
2
Vase volba=2
Insert_First - vlozeni nove polozky na 1. misto seznamu
Zadejte jmeno osoby: Franta
Zadejte vek, vahu a vysku (oddelene Enter):
30
80
180
myMalloc: prideluji 288 bajtu, celkove prideleno 288 bajtu
Aktivni polozka:
NULL
Obsah seznamu:
1. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
2
Vase volba=2
Insert_First - vlozeni nove polozky na 1. misto seznamu
Zadejte jmeno osoby: Josef
Zadejte vek, vahu a vysku (oddelene Enter):
45
90
185
myMalloc: prideluji 288 bajtu, celkove prideleno 576 bajtu
Aktivni polozka:
NULL
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
2. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
2
Vase volba=2
Insert_First - vlozeni nove polozky na 1. misto seznamu
Zadejte jmeno osoby: Adela
Zadejte vek, vahu a vysku (oddelene Enter):
20
60
171
myMalloc: prideluji 288 bajtu, celkove prideleno 864 bajtu
Aktivni polozka:
NULL
Obsah seznamu:
1. prvek: Jmeno=Adela, vek=20.0, vaha=60.0, vyska=171.0
2. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
3. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
3
Vase volba=3
First - nastaveni aktivni polozky na 1.prvek
Aktivni polozka:
Jmeno=Adela, vek=20.0, vaha=60.0, vyska=171.0
Obsah seznamu:
1. prvek: Jmeno=Adela, vek=20.0, vaha=60.0, vyska=171.0
2. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
3. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
9
Vase volba=9
Succ - posuv ukazatel aktivniho prvku na dalsi prvek
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Adela, vek=20.0, vaha=60.0, vyska=171.0
2. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
3. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
7
Vase volba=7
Post_Insert - vloz novy prvek za aktivni prvek
Zadejte jmeno osoby: Lenka
Zadejte vek, vahu a vysku (oddelene Enter):
18
70
180
myMalloc: prideluji 288 bajtu, celkove prideleno 1152 bajtu
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Adela, vek=20.0, vaha=60.0, vyska=171.0
2. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
3. prvek: Jmeno=Lenka, vek=18.0, vaha=70.0, vyska=180.0
4. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
6
Vase volba=6
Post_Delete - vymaz prvek za aktivnim prvkem
myFree: uvolnuji 288 bajtu, celkove prideleno 864 bajtu
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Adela, vek=20.0, vaha=60.0, vyska=171.0
2. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
3. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
5
Vase volba=5
Delete_First - vymaz  1.prvek
myFree: uvolnuji 288 bajtu, celkove prideleno 576 bajtu
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
2. prvek: Jmeno=Franta, vek=30.0, vaha=80.0, vyska=180.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
6
Vase volba=6
Post_Delete - vymaz prvek za aktivnim prvkem
myFree: uvolnuji 288 bajtu, celkove prideleno 288 bajtu
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
4
Vase volba=4
Copy_First - Vypis 1.prvku seznamu
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
8
Vase volba=8
Copy - ziskani hodnoty aktivniho prvku 
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
A
Vase volba=A
Is_Active - zjisteni, zda je seznam aktivni
Is_Active=true
Aktivni polozka:
Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
9
Vase volba=9
Succ - posuv ukazatel aktivniho prvku na dalsi prvek
Aktivni polozka:
NULL
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
A
Vase volba=A
Is_Active - zjisteni, zda je seznam aktivni
Is_Active=false
Aktivni polozka:
NULL
Obsah seznamu:
1. prvek: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=185.0

Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:
************************************************************
8
Vase volba=8
Copy - ziskani hodnoty aktivniho prvku 
Chyba: List_Copy error
first=000339A8, active=00000000
first->data: Jmeno=Josef, vek=45.0, vaha=90.0, vyska=180.0
```
