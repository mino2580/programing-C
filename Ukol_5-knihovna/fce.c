
void minimax(int * pole, int delka, int *minimum, int *maximum){
      int min =pole[0];
	  int max =pole[0];
  for( int i=0;i<delka;i++){
     
	if (pole[i]<min){
		min=pole[i];
	   }
	
	if (pole[i]>max){
		max=pole[i]; 
       }
    }  
	   *minimum=min;
	   *maximum=max;
       
	
  }
 
 
 int get_min(int * pole, int delka){
  int min =pole[0];
  for(int i=0;i<delka;i++)
     if (pole[i]<min)
		 min=pole[i];
	  return min;
	  }
 
 
int get_max(int * pole, int delka){
int max=pole[0];
  for( int i=0;i<delka;i++)
     if (pole[i]>max)
		 max=pole[i];
	  return max;
 }



double fact(double n){ 
	double vysledek=1;
	for(double i=2;i<=n;i++)
		vysledek =vysledek * i;
		return vysledek;
	}
int fibonacci(int n){ 
	if (n<=0){
	return 0;	
	}
	
	if (n==1){
		return 1;
		
	}
	
	//return fibonacci(n-1)+ fibonacci(n-2);
    int vysl=1,predchozi=0;
	
	for (int i=2;i<=n;i++){
		int pom=vysl;
	    vysl=vysl + predchozi;
	    predchozi=pom;
	    }
     return vysl;
  }
  

//>gcc main.c fce.c ioutils.c
//vytvoreni a.exe v slozke kde je umiestneni debug