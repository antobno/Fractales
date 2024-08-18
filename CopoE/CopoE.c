#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "CopoE.h"

int nivelRecursionCopoE;
double longitudCopoE;
double miX0CopoE;
double miY0CopoE;
LOGO *tortugaAuxCopoE;

int RCopoE(int n, double l, LOGO *tortuga);
int LCopoE(int n, double l, LOGO *tortuga);

int iniciaCopoE(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCopoE=n;
  longitudCopoE = l;
  miX0CopoE=x;
  miY0CopoE=y;
  tortugaAuxCopoE = tortuga;
  
  return 0;
}

int dibujaCopoE(void){
  inicia(miX0CopoE, miY0CopoE, 0, ABAJO, tortugaAuxCopoE);

  return RCopoE(nivelRecursionCopoE, longitudCopoE, tortugaAuxCopoE);
}

int RCopoE(int n, double l, LOGO *tortuga)
{
  double laux, laux2;
  
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  laux=l/3.0;
  laux2=l*2.0*(sin(60*G2R))/9.0;
  izq(60, tortuga);
  LCopoE(n-1, laux, tortuga);
  RCopoE(n-1, laux, tortuga);
  der(60, tortuga);
  RCopoE(n-1, laux, tortuga);
  der(60, tortuga);
  RCopoE(n-1, laux, tortuga);
  der(150, tortuga);
  RCopoE(n-1, laux2, tortuga);
  LCopoE(n-1, laux2, tortuga);
  izq(60, tortuga);
  RCopoE(n-1, laux2, tortuga);
  izq(60, tortuga);
  LCopoE(n-1, laux2, tortuga);
  RCopoE(n-1, laux2, tortuga);
  izq(90, tortuga);
  LCopoE(n-1, laux, tortuga);
  RCopoE(n-1, laux, tortuga);

  return 0;
}

int LCopoE(int n, double l, LOGO *tortuga)
{
  double laux, laux2;
  
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  laux=l/3.0;
  laux2=l*2.0*sin(60*G2R)/9.0;
  LCopoE(n-1, laux, tortuga);
  RCopoE(n-1, laux, tortuga);
  der(90, tortuga);
  LCopoE(n-1, laux2, tortuga);
  RCopoE(n-1, laux2, tortuga);
  der(60, tortuga);
  LCopoE(n-1, laux2, tortuga);
  der(60, tortuga);
  RCopoE(n-1, laux2, tortuga);
  LCopoE(n-1, laux2, tortuga);
  izq(150, tortuga);
  LCopoE(n-1, laux, tortuga);
  izq(60, tortuga);
  LCopoE(n-1, laux, tortuga);
  izq(60, tortuga);
  LCopoE(n-1, laux, tortuga);
  RCopoE(n-1, laux, tortuga);
  der(60, tortuga);

  return 0;
}
