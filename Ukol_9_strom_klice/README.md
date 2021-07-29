# Binární strom #
Naprogramujte binární strom.

Popis jednotlivých funkcí máte v souboru tree.h, potřebnou teorii máte ve slajdech přednášky o seznamu.

## Vizualizace ##
Pro lepší pochopení funkce binárního stromu navštivte [tento odkaz](https://www.cs.usfca.edu/~galles/visualization/BST.html). Je možné vidět, jak jsou jednotlivé operace binárního stromu vykonávány. Nejsložitějším úkolem je pravděpodobně mazání a na lepší pochopení zkuste zadat následující strom. `F-B-S-A-D-L`
![relative Tree](doc/tree.png)

Zkuste teď postupně zkusit smazat uzel `F`, `D`, `S` a `A`. Tyto čtyři možnosti mohou nastat, když budete mazat uzel ve vaší implementaci, takže je musíte vyřešit. 

Aby bylo lépe vidět, jak probíhá mazání uzlu, který má oba podstromy, zkuste si do původního stromu přidat ještě uzely `C` a `E`, a opět proveďte smazání uzlu `F` a poté `E`.
![relative Tree extended](doc/tree2.png)

```
Strom v1.0
----------

1 - tree_init()
2 - tree_clear()
3 - tree_insert()
4 - tree_delete()
5 - tree_find_node()
6 - tree_get_node_count()
7 - tree_proces()
M - zobraz toto menu
K - konec
Pro ukonceni stiskni CTRL+D (Linux) nebo CTRL+Z (Windows).

Vase volba: 7
Strom neni inicializovan!

Vase volba: 1
Strom byl inicializovan.

Vase volba: 7
Pruchod:
1 - preorder
2 - inorder
3 - postorder

Vase volba: 1


Vase volba: 3
Data uzlu stromu:
Zadejte jmeno osoby: Zadejte vek, vahu a vysku (oddelene Enter):
myMalloc: prideluji 296 bajtu, celkove prideleno 296 bajtu

Vase volba: 3
Data uzlu stromu:
Zadejte jmeno osoby: Zadejte vek, vahu a vysku (oddelene Enter):
myMalloc: prideluji 296 bajtu, celkove prideleno 592 bajtu

Vase volba: 3
Data uzlu stromu:
Zadejte jmeno osoby: Zadejte vek, vahu a vysku (oddelene Enter):
myMalloc: prideluji 296 bajtu, celkove prideleno 888 bajtu

Vase volba: 6
Pocet uzlu stromu: 3

Vase volba: 7
Pruchod:
1 - preorder
2 - inorder
3 - postorder

Vase volba: 2

Jmeno=Anna, vek=30.0, vaha=60.0, vyska=160.0
 | L -> NULL | R -> NULL
Jmeno=Franta, vek=50.0, vaha=80.0, vyska=180.0
 | L -> Jmeno=Anna, vek=30.0, vaha=60.0, vyska=160.0
 | R -> Jmeno=Xaver, vek=60.0, vaha=70.0, vyska=175.0

Jmeno=Xaver, vek=60.0, vaha=70.0, vyska=175.0
 | L -> NULL | R -> NULL

Vase volba: 4
Zadej mazana data:
Zadejte jmeno osoby: Zadejte vek, vahu a vysku (oddelene Enter):
myFree: uvolnuji 296 bajtu, celkove prideleno 592 bajtu

Vase volba: 7
Pruchod:
1 - preorder
2 - inorder
3 - postorder

Vase volba: 2

Jmeno=Anna, vek=30.0, vaha=60.0, vyska=160.0
 | L -> NULL | R -> Jmeno=Xaver, vek=60.0, vaha=70.0, vyska=175.0

Jmeno=Xaver, vek=60.0, vaha=70.0, vyska=175.0
 | L -> NULL | R -> NULL

Vase volba: 5
Zadej hledana data:
Zadejte jmeno osoby: Zadejte vek, vahu a vysku (oddelene Enter):
Data nebyla ve strome nalezena.

Vase volba: 5
Zadej hledana data:
Zadejte jmeno osoby: Zadejte vek, vahu a vysku (oddelene Enter):
Data byla nalezena v uzlu

Vase volba: 2
myFree: uvolnuji 296 bajtu, celkove prideleno 296 bajtu
myFree: uvolnuji 296 bajtu, celkove prideleno 0 bajtu
Obsah stromu byl odstranen.

Vase volba: K
Konec.
```
