#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "CopoC.h"

int nivelRecursionCopoC;
double longitudCopoC;
double miX0CopoC;
double miY0CopoC;
LOGO *tortugaAuxCopoC;

int CopoC(int n, double l, LOGO *tortuga);

int iniciaCopoC(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCopoC=n;
  longitudCopoC = l;
  miX0CopoC=x;
  miY0CopoC=y;
  tortugaAuxCopoC = tortuga;
  
  return 0;
}

int dibujaCopoC(void){
  int i;
  inicia(miX0CopoC, miY0CopoC, 0, ABAJO, tortugaAuxCopoC);
  
  for(i=0; i<4; i++){
  	CopoC(nivelRecursionCopoC, longitudCopoC, tortugaAuxCopoC);
  	der(90, tortugaAuxCopoC);
  }

  return 0;
}

int CopoC(int n, double l, LOGO *tortuga)
{
  double laux;
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  laux=l/4.0;
  CopoC(n-1, laux, tortuga);
  izq(90, tortuga);
  CopoC(n-1, laux, tortuga);
  der(90, tortuga);
  CopoC(n-1, laux, tortuga);
  der(90, tortuga);
  CopoC(n-1, laux, tortuga);
  CopoC(n-1, laux, tortuga);
  izq(90, tortuga);
  CopoC(n-1, laux, tortuga);
  izq(90, tortuga);
  CopoC(n-1, laux, tortuga);
  der(90, tortuga);
  CopoC(n-1, laux, tortuga);

  return 0;
}
