#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "CurvaS.h"

int nivelRecursionCurvaS;
double miX0CurvaS;
double miY0CurvaS;
double diag;
LOGO *tortugaAuxCurvaS;

int CurvaS(int n, LOGO *tortuga);

int iniciaCurvaS(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCurvaS=n;
  miX0CurvaS=x;
  miY0CurvaS=y;
  diag=l/sqrt(2);
  tortugaAuxCurvaS = tortuga;
  
  return 0;
}

int dibujaCurvaS(void){
  int i;
  inicia(miX0CurvaS, miY0CurvaS, 0, ABAJO, tortugaAuxCurvaS);
  
  for(i=0; i<4; i++){
  	CurvaS(nivelRecursionCurvaS, tortugaAuxCurvaS);
  	der(45, tortugaAuxCurvaS);
  	avanza(diag, tortugaAuxCurvaS);
  	der(45, tortugaAuxCurvaS);
  }
  return 0;
}

int CurvaS(int n, LOGO *tortuga)
{
  if (n<=0){
    return 0;
  }
  CurvaS(n-1, tortuga);
  der(45, tortuga);
  avanza(diag, tortuga);
  der(45, tortuga);
  CurvaS(n-1, tortuga);
  izq(90, tortuga);
  avanza(diag, tortuga);
  izq(90, tortuga);
  CurvaS(n-1, tortuga);
  der(45, tortuga);
  avanza(diag, tortuga);
  der(45, tortuga);
  CurvaS(n-1, tortuga);
  
  return 0;
}
