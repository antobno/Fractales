#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "CurvaH.h"

int nivelRecursionCurvaH;
int paridadCurvaH=1;
double longitudCurvaH;
double miX0CurvaH;
double miY0CurvaH;
LOGO *tortugaAuxCurvaH;

int CurvaH(int n, double l, int p, LOGO *tortuga);

int iniciaCurvaH(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCurvaH=n;
  longitudCurvaH = l;
  miX0CurvaH=x;
  miY0CurvaH=y;
  tortugaAuxCurvaH = tortuga;
  
  return 0;
}

int dibujaCurvaH(void){
  inicia(miX0CurvaH, miY0CurvaH, 0, ABAJO, tortugaAuxCurvaH);

  return CurvaH(nivelRecursionCurvaH, longitudCurvaH, paridadCurvaH, tortugaAuxCurvaH);
}

int CurvaH(int n, double l, int p, LOGO *tortuga)
{
  if (n<=0){
    return 0;
  }
  izq(p*90,tortuga);
  CurvaH(n-1,l,-p,tortuga);
  avanza(l,tortuga);
  der(p*90,tortuga);
  CurvaH(n-1,l,p,tortuga);
  avanza(l,tortuga);
  CurvaH(n-1,l,p,tortuga);
  der(p*90,tortuga);
  avanza(l,tortuga);
  CurvaH(n-1,l,-p,tortuga);
  izq(p*90,tortuga);
  return 0;
}

