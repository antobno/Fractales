#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "Weave.h"

int nivelRecursionWeave;
double longitudWeave;
double miX0Weave;
double miY0Weave;
int paridad;
LOGO *tortugaAuxWeave;

int Weave(int n, double l, LOGO *tortuga);
int Weaveaux(double l, LOGO *tortuga);

int iniciaWeave(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionWeave=n;
  longitudWeave = l;
  miX0Weave=x;
  miY0Weave=y;
  tortugaAuxWeave = tortuga;
  
  return 0;
}

int dibujaWeave(void){
  paridad=-1;
  inicia(miX0Weave, miY0Weave, 0, ABAJO, tortugaAuxWeave);

  return Weave(nivelRecursionWeave, longitudWeave, tortugaAuxWeave);
}

int Weave(int n, double l, LOGO *tortuga)
{
  double laux;
  int i, j;
  if (n<=0){
    WeaveAux(l, tortuga);
    return 0;
  }
  laux=l/3.0;
  Weave(n-1, laux, tortuga);
  izq(90, tortuga);
  Weave(n-1, laux, tortuga);
  for(i=0; i<3; i++){
  	der(90, tortuga);
    Weave(n-1, laux, tortuga);	
  }
  for(j=0; j<3; j++){
  	izq(90, tortuga);
    Weave(n-1, laux, tortuga);
  }
  der(90, tortuga);
  Weave(n-1, laux, tortuga);
  
  return 0;
}

int WeaveAux(double l, LOGO *tortuga)
{
  double laux;
  
  paridad=-paridad;
  laux=l/5.0;
  avanza(4.0*laux, tortuga);
  der(90*paridad, tortuga);
  avanza(3.0*laux, tortuga);
  der(90*paridad, tortuga);
  avanza(2.0*laux, tortuga);
  der(90*paridad, tortuga);
  avanza(laux, tortuga);
  der(90*paridad, tortuga);
  avanza(laux, tortuga);
  izq(90*paridad, tortuga);
  avanza(laux, tortuga);
  izq(90*paridad, tortuga);
  avanza(2.0*laux, tortuga);
  izq(90*paridad, tortuga);
  avanza(3.0*laux, tortuga);
  izq(90*paridad, tortuga);
  avanza(4.0*laux, tortuga);
  izq(90*paridad, tortuga);
  avanza(4.0*laux, tortuga);
  der(90*paridad, tortuga);
  

  return 0;
}
