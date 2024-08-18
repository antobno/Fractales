#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "CurvaC.h"

int nivelRecursionCurvaC;
double longitudCurvaC;
double miX0CurvaC;
double miY0CurvaC;
LOGO *tortugaAuxCurvaC;

int CurvaC(int n, double l, LOGO *tortuga);

int iniciaCurvaC(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCurvaC=n;
  longitudCurvaC = l;
  miX0CurvaC=x;
  miY0CurvaC=y;
  tortugaAuxCurvaC = tortuga;
  
  return 0;
}

int dibujaCurvaC(void){
  inicia(miX0CurvaC, miY0CurvaC, 0, ABAJO, tortugaAuxCurvaC);

  return CurvaC(nivelRecursionCurvaC, longitudCurvaC, tortugaAuxCurvaC);
}

int CurvaC(int n, double l, LOGO *tortuga)
{

  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  CurvaC(n-1, l, tortuga);
  der(90, tortuga);
  CurvaC(n-1, l, tortuga);
  izq(90, tortuga);

  return 0;
}
