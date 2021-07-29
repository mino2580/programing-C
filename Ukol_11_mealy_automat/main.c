#include <stdio.h>
 
typedef enum{
	START,MOZNAPOZNAMKA,JEDNORADKOVA,VICERADKOVA,MOZNAKONEC,NEMAZSTRING,NEMAZLOMITKA 
	} tStavy;

int main()
{
	 
	tStavy stav=START;
	int znak;
	while( (znak=getchar()) !=EOF)   
	{
		switch(stav)
		{
			case START:
			if(znak=='/') {
				stav=MOZNAPOZNAMKA;
			} 
			else if(znak=='"') {
				putchar(znak);
				stav=NEMAZSTRING;
			}
              else if(znak=='\'') {
				stav=NEMAZLOMITKA;
				putchar(znak);
			  }
			    
			else {
				putchar(znak);
			}
			
			break;
			
/**************************************/			
			case MOZNAPOZNAMKA:
			if(znak=='/') {
				stav=JEDNORADKOVA;
			} 
			else if(znak=='*') {
				stav=VICERADKOVA;
			} 
			else {
				stav=START;
				putchar('/');
				putchar(znak);
			}	
			break;
			
/************************************/			
			case VICERADKOVA:
			  if(znak=='*') {
				stav=MOZNAKONEC;
			}
			/* 
			if(znak=='\n') {
				 
			putchar('\n');
			stav=VICERADKOVA;}
			 */
			break;
			
/*************************************/			
			case JEDNORADKOVA:
			if(znak=='\n') {
				stav=START;
				putchar('\n');
			}
               break;
				
/***************************************/			
			 case MOZNAKONEC:
			 if(znak=='/') {
				 stav=START;
			 }
              else stav=VICERADKOVA;
			 break;
			 
/*************************************/			 
			 case NEMAZSTRING:
			 if(znak=='"') {
				 stav=START;
			 } 
			 else if(znak=='\'') {
				 stav=NEMAZLOMITKA;
			 }
			 else if(znak==';') {
				 stav=START;
			 }
			 putchar(znak);
             break;   
		     
/***************************************/			 
			 case NEMAZLOMITKA:
			 if(znak=='\'') {
				stav=START;
			  }
			   if(znak==';') {
				stav=START;
			  }
			  
			  putchar(znak);
			  break;
	/********************************/		 
	 
             
		}
	}
	
	
 
	
	return 0;
}
