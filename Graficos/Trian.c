#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "Trian.h"

int nivelRecursionTrian;
double longitudTrian;
double miX0Trian;
double miY0Trian;
LOGO *tortugaAuxTrian;

int Trian(int n, double l, LOGO *tortuga);

int iniciaTrian(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionTrian=n;
  longitudTrian = l;
  miX0Trian=x;
  miY0Trian=y;
  tortugaAuxTrian = tortuga;
  
  return 0;
}

int dibujaTrian(void){
  inicia(miX0Trian, miY0Trian, 0, ABAJO, tortugaAuxTrian);
  	
  return Trian(nivelRecursionTrian, longitudTrian, tortugaAuxTrian);
}

int Trian(int n, double l, LOGO *tortuga)
{
  int i;
  
  if (n<=0){
    return 0;
  }
  for(i=0; i<3; i++){
  	Trian(n-1, l/2.0, tortuga);
  	avanza(l, tortuga);
  	der(120, tortuga);
  }
  
  return 0;
}
