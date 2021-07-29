/*  _____ _______         _                      _              
 * |_   _|__   __|       | |                    | |             
 *   | |    | |_ __   ___| |___      _____  _ __| | __  ___ ____
 *   | |    | | '_ \ / _ \ __\ \ /\ / / _ \| '__| |/ / / __|_  /
 *  _| |_   | | | | |  __/ |_ \ V  V / (_) | |  |   < | (__ / / 
 * |_____|  |_|_| |_|\___|\__| \_/\_/ \___/|_|  |_|\_(_)___/___|
 * 
 * IT ZPRAVODAJSTVÍ  <>  PROGRAMOVÁNÍ  <>  HW A SW  <>  KOMUNITA
 * 
 * Tento zdrojový kód je součástí výukových seriálů na 
 * IT sociální síti WWW.ITNETWORK.CZ	
 *	
 * Kód spadá pod licenci prémiového obsahu a vznikl díky podpoře
 * našich členů. Je určen pouze pro osobní užití a nesmí být šířen.
 */

#include <stdio.h>
#include <stdlib.h>

// Uzel seznamu
typedef struct uzel {
    int hodnota; // Hodnota v uzlu
    struct uzel *p_dalsi; // Odkaz na první uzel seznamu
} UZEL;

// Seznam
typedef struct {
    int pocet; // Počet prvků v seznamu
    UZEL *p_hlava; // Odkaz na první uzel
    UZEL *p_ocas; // Odkaz na poslední uzel
} SEZNAM;

// Vytvoří nový seznam bez uzlů a vrátí na něj ukazatel
SEZNAM *vytvor_seznam()
{
    SEZNAM *p_seznam = (SEZNAM *) malloc(sizeof(SEZNAM));
    p_seznam->p_hlava = NULL;
    p_seznam->p_ocas = NULL;
    return p_seznam;
}

// Uvolní paměť po uzlech seznamu a seznam samotný
void uvolni_seznam(SEZNAM *p_seznam)
{
    UZEL *p_aktualni = p_seznam->p_hlava;
    UZEL *p_stara;
    // Proiteruje seznam až na konec
    while (p_aktualni != NULL)
    {
        p_stara = p_aktualni;
        p_aktualni = p_aktualni->p_dalsi; // Posun aktuální pozice na další uzel     
        free(p_stara);
    }
    free(p_seznam);
}

// Přidá uzel na konec seznamu
UZEL *pridej_do_seznamu(SEZNAM *p_seznam, int hodnota)
{
    UZEL *p_novy;
    p_novy = (UZEL *) malloc(sizeof(UZEL));
    if (p_novy == NULL)
    {
        printf("Chyba - Nedostatek paměti.\n");
        exit(1);
    }
    p_novy->p_dalsi = NULL;

    // Seznam není prázdný
    if(p_seznam->p_ocas != NULL)
    {        
        // Připojí nový uzel za poslední
        p_seznam->p_ocas->p_dalsi = p_novy;
        // Nastaví nový ocas
        p_seznam->p_ocas = p_novy;
    }
    else // Seznam je prázdný, jen do něj vložíme uzel
    {
        p_seznam->p_hlava = p_novy;
        p_seznam->p_ocas = p_novy;
    }
    p_novy->hodnota = hodnota;
    p_seznam->pocet++;
    return p_novy;
}

int main(int argc, char** argv) {
    // Vytvoření prázdného seznamu
    SEZNAM *p_seznam = vytvor_seznam();
        
    // Zkouška seznamu - přidáme do něj 1000 prvků
    int i;
    for (i = 0; i < 1000; i++)
    {
        pridej_do_seznamu(p_seznam, i); // Přidá na konec pole číslo i
    }
    
    // Nyní prvky seznamu vypíšeme
    UZEL *p_aktualni = p_seznam->p_hlava;
    while(p_aktualni != NULL)
    {
        printf("%d ", p_aktualni->hodnota);
        p_aktualni = p_aktualni->p_dalsi;
    }        
    
    // Uvolnění seznamu
    uvolni_seznam(p_seznam);
    return (EXIT_SUCCESS);
}