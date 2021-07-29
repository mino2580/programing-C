#  Zpracování textů - konečný automat #
Nakreslete a naprogramujte **konečný Mealyho automat**, který ze vstupního souboru v jazyce C/C++ odstraní poznámky (tzn. vše mezi znaky /* */ nebo // \n).

Nezapomeňte ošetřit vstupy typu: 

- _puts("Toto je řetězec //a toto ani /* toto */ neni poznámka");_
- _putchar('"'); /* Toto byl znak uvozovky, ne řetězec. Takže toto je poznámka */_
- backslash: puts _("Toto \" je stále řetězec");_ // to samé platí i pro znakové konstanty  v apostrofech: _'\''_

Automat implementujte standardním způsobem s tím, že výsledný program bude jako vstupní soubor používat buď:

- soubor zadaný jako 1. parametr na příkazové řádce
- standardní vstup (stdin), pokud parametr není zadán

Výstup programu bude
- do souboru, který byl zadán jako 2. parametr na příkazové řádce
- na standardní výstup (stdout), pokud 2. parametr není zadán

Příklady možností spuštění programu:
- bez vstupních argumentů: `./task4`
- vstupní soubor jako argument: `./task4 input.txt`
- vstupní a výstupní soubor jako argument: `./task4 input.txt output.txt`

Pokud je na příkazové řádce pouze 1 parametr, bere se tento parametr jako jméno vstupního souboru.

Abyste nemuseli mít ve vašem kódu 2 různé větve - jednu pro operace se standardním vstupem/výstupem, druhou pro operace se soubory - můžete s výhodou použít soubory standardního vstupu a výstupu (stdin, stdout).

Součástí řešení bude dokumentace s obrázkem a popisem funkce vašeho konečného automatu, a to ve formátu PDF - [a relative ukázka v adresáři example](example/sablonaDokumentace.doc).

Ukazka pro jazyk C - jak zpracovat argumenty příkazové řádky v adresaři example.
