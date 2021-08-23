
#ifndef FUNCIONES
#define FUNCIONES

#include <iostream>

class Funciones{
  public:
  Funciones();
  int sumaIterativa(int);
  int sumaRecursiva(int);
  int sumaDirecta(int);
};

Funciones::Funciones(){

}

int Funciones::sumaIterativa(int n){
   int acum=0;
  for (int i=0;i<=n;i++){
    acum=acum+i;
  }
	return acum;
}

int Funciones::sumaRecursiva(int n){
   if (n==0){
     return 0;
   }
	return n+sumaRecursiva(n-1);
}

int Funciones::sumaDirecta(int n){
   
	return (n*(n+1))/2;
}
#endif /* RECURSION_H_ */
