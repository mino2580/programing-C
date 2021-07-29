#include <stdio.h>
#include "list.h"
#include "data.h"
#include "mymalloc.h"
#include "ioutils.h"

void menu(){
	printf("List test program\n"
	"Zadejte pismeno 0-A pro jednu z nasledujicich cinnosti:\n"
	"q: 2 seznamy\n"
	"0: Init,\n"
	"1: Actualize,\n"
	"2: Insert_First,\n"
	"3: First,\n"
	"4: Copy_First,\n"
	"5: Delete_First,\n"
	"6: Post_Delete,\n"
	"7: Post_Insert,\n"
	"8: Copy,\n"
	"9: Succ,\n"
	"A: Is_Active,\n"
	"M: Vypis menu\n"
	"CTRL+Z (Win) nebo CTRL+D (Unix): Konec programu\n");	
}

void smallmenu(){
	printf("Zadejte znak 0-A, EOF(tj. CTRL+Z nebo CTRL+D)=Konec, M=Menu:\n"
		   "************************************************************\n");
}

void List_Print(List_t *list){
	int cnt = 1;
	List_Node_t *tmp = list->active;
	printf("Obsah seznamu:\n");
	List_First(list);
	while(list->active != NULL){
		printf("%d. prvek: ", cnt);
		Data_Print(&list->active->data);
		list->active = list->active->next;
		cnt++;
		printf("list->active = list->active->next;\n list->active =%d\n",list->active);
	}
	printf("\n");
	list->active = tmp;
	printf("list->active = tmp;\n list->active =%d\n",list->active);
}

void List_Free_Exit(List_t *list){
	List_First(list);				
	while(list->active != NULL){	
		myFree(&list->active->data);
		list->active = list->active->next;
	}
	exit(EXIT_SUCCESS);
}

void List_Active(List_t *list){
	printf("Aktivni polozka:\n");
	if (list->active != NULL) Data_Print(&list->active->data);
	else printf("NULL\n");
}


/********************************************************************/
void Data_Print( Data_t * data )
{
    printf( "Jmeno=%s, vek=%0.1lf, vaha=%0.1lf, vyska=%0.1lf\n",
            data->jmeno, data->vek, data->vaha, data->vyska );
}

////////////////////////////
void print_seznam(List_t  *list){
    printf("Aktivni polozka:\n");

    if(list->active != NULL){
        Data_Print(&list->active->data);
    }
    else
     printf("NULL\n");

    printf("Obsah seznamu:\n");

    List_Node_t *tmp  = list->first;
    int i = 1;
    while(tmp != NULL){
        printf("%d. prvek: ", i);
        Data_Print(&tmp->data);
		
        tmp = tmp->next;
        i++;
    }
}	
/////////////////////////////////	
Data_t vloz_data( char * jmeno, double vek, double vaha, double vyska )
{
    Data_t data;
    strcpy(data.jmeno, jmeno);
    data.vek = vek;
    data.vaha = vaha; 
    data.vyska = vyska;
    return data;
}
/////////////////////////////////

List_Node_t *pt=NULL; //globalni promnena pro funkce obsah a mozne dalsi

/////////////////////////////////
/*
void obsah(List_t *lis){
    printf("Obsah seznamu: \n");
    if(lis->first!=NULL){
        for(pt=lis->first;pt!=NULL;pt=pt->next)
            Data_Print(&pt->data);
    }
}
*/
/////////////////////////////////////
int Data_cmp( Data_t * data_a, Data_t * data_b )
{
	printf(" %2.lf   %2.lf\n",data_a->vek,data_b->vek);

        if(data_a->vek == data_b->vek){//menim bud vyostupne alebo obracen		
        return -1;
		}
       else {
		   return 1;
	   }

}
//////////////////////////////////////
void List_Last(List_t* const list){
    list->active = list->first;
    while(list->active->next != NULL)
        list->active = list->active->next;
}
//////////////////////////////////////

void serad(List_t* lis){ 
    List_Node_t* pom=lis->first;
	
    for(List_Node_t* n=pom;n!=NULL;n=n->next){//probehne vsechnz adresy listu
        Data_t dat;//aby sem prosel vsechnz pruchody bublesort,pouziju dva cykly
		
        for(List_Node_t* m=pom;m->next!=NULL;m=m->next){
		
            if((Data_cmp(&m->data, &m->next->data))<0){
                dat=m->next->data;//prehazovznie datovej casti medzi sebu
                m->next->data=m->data;//bublesort
                m->data=dat;
                                                      }
           }
     }
}
//////////////////////////////////////////
void prunik(List_t *vys, List_t *s1, List_t *s2)
{
   // serad(s1);
   // serad(s2);
	print_seznam(s1);
	print_seznam(s2);
    List_First(s1);//list->active = list->first;
    List_First(s2);//
    while(s1->active!=NULL || s2->active!=NULL)
    {
        int cmp;
        if (s2->active==NULL&&s1->active!=NULL)
		{
		    List_Succ(s1);
			if(s1->active!=NULL) List_First(s2);
			
		}
		 
		 
       if(s1->active!=NULL)
		   {   
		cmp=Data_cmp(&s1->active->data, &s2->active->data);
		if(cmp < 0){//ak sa rovnaju
		List_Insert_First(vys, s1->active->data);// List_Insert_First(vys, s2->active->data);//Posune aktivitu na následující prvek seznamu.
		List_Succ(s2);}    
		else List_Succ(s2);
		   }         
        
       
    }
	print_seznam(vys);
} 
/********************************************************************/
int main()
{
	List_t l;  //first,activ uakzatel
	menu();
	char ch[255];
	Data_t d;  //data jmeno, vek, vyska,vaha
	List_Init(&l);//inicializace fist a aktiv na null
	bool ex = false;
	while (io_utils_get_string(ch, 255)){  
		//if (!io_utils_get_string( ch, 255 )) return 0;
		//io_utils_get_string( ch, 255 );
		printf("Vase volba=%c\n", (int)ch[0]); 
		switch (ch[0]){
			
			
/*********************************************************************/			
				case'q':
			//spojeni dvou seznamu do jedneho ,kterz bude serazeni
    printf("Ukazka funkcnosti - prunik\n");

    List_t s3, s2, s1;
    Data_t data;

    printf("Inicializace a naplneni...\n");
    List_Init(&s3);//activ,firts ==Null
    List_Init(&s2);
    List_Init(&s1);

    printf("\nseznam 2...\n");
    List_Insert_First(&s2, vloz_data("a1", 1, 68.4, 180));
    List_Insert_First(&s2, vloz_data("a2", 2, 82.7, 178));
    List_Insert_First(&s2, vloz_data("a3", 3, 77.4, 186));
    List_Insert_First(&s2, vloz_data("a4",4, 61.8, 168));
    print_seznam(&s2);

    printf("\nseznam 1...\n");
    List_Insert_First(&s1, vloz_data("b1", 2, 58.4, 167));
    List_Insert_First(&s1, vloz_data("b2", 4, 60.2, 173));
    List_Insert_First(&s1, vloz_data("b3", 5, 58.7, 177));
    List_Insert_First(&s1, vloz_data("b4", 6, 48.9, 167));
    print_seznam(&s1);

    printf("\nkompet seznam - spojeny seznam\n");
    prunik(&s3,&s2,&s1);
   while(s2.first != NULL) {
	   List_Delete_First(&s2.first);
   }
	printf("\nkonec\n");
	break;
/************************************************************************/	
	
			case'0':	//Init
				printf("Init - inicializace seznamu\n");
				List_Init(&l);//nastaveni na nulu 
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'1':	//Actualize		
				printf("Actualize - prepis dat aktivni polozky\n");
				if (Data_Get(&d)) List_Actualize(&l, d);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'2':	//Insert_First
				printf("Insert_First - vlozeni nove polozky na 1. misto seznamu\n");
				if (Data_Get(&d)) List_Insert_First(&l, d);
				else ex = true;
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'3':	//First
				printf("First - nastaveni aktivni polozky na 1.prvek\n");
				List_First(&l);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'4':	//Copy_First
				printf("Copy_First - Vypis 1.prvku seznamu\n");		
				if (List_Copy_First(l, &d))	Data_Print(&d);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'5':	//Delete_First
				printf("Delete_First - vymaz  1.prvek\n");		
				List_Delete_First(&l);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'6':	//Post_Delete
				printf("Post_Delete - vymaz prvek za aktivnim prvkem\n");		
				List_Post_Delete(&l);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'7':	//Post_Insert	
				printf("Post_Insert - vloz novy prvek za aktivni prvek\n");		
				Data_Get(&d);
				List_Post_Insert(&l, d);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'8':	//Copy
				printf("Copy - ziskani hodnoty aktivniho prvku \n");		
				if (List_Copy(l, &d)) Data_Print(&d);
				List_Active(&l);
				List_Print(&l);
				smallmenu();	 				
			break;
			case'9':	//Succ
				printf("Succ - posuv ukazatel aktivniho prvku na dalsi prvek\n");		
				List_Succ(&l);
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
		
		

        	case'A':	//Is_Active
				printf("Is_Active - zjisteni, zda je seznam aktivni\n");
				if (List_Is_Active(l)) printf("Is_Active=true\n");
				else printf("Is_Active=false\n");
				List_Active(&l);
				List_Print(&l);
				smallmenu();
			break;
			case'M':	//Vypis menu
				menu();
			break;
			default:
				//return 0;
			break;
		}
		
		
		if (ex){			//uvolneni pameti bez snahy nacist dalsi znak, kdyz je eof v Data_Get()			
			List_Free_Exit(&l);  //aby v testu 4 nenapsal podruhe konec souboru...
		}
	}
	List_Free_Exit(&l);
	return 0;
}