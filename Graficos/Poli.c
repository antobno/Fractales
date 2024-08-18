#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "Poli.h"

int anguloPoli;
double longitudPoli;
double miX0Poli;
double miY0Poli;
double limitePoli;
LOGO *tortugaAuxPoli;

int Poli(int a, double l, int g, LOGO *tortuga);
int Poliaux(int a, double l, LOGO *tortuga);

int iniciaPoli(int a, double l, double x, double y, double lm, int g, LOGO *tortuga)
{
  anguloPoli=a;
  longitudPoli=l;
  miX0Poli=x;
  miY0Poli=y;
  limitePoli=lm;
  tortugaAuxPoli = tortuga;
  
  return 0;
}

int dibujaPoli(void){
  inicia(miX0Poli, miY0Poli, 0, ABAJO, tortugaAuxPoli);

  return Poli(anguloPoli, longitudPoli, 0, tortugaAuxPoli);
}

int Poli(int a, double l, int g, LOGO *tortuga)
{

  if (l<=limitePoli){
    return 0;
  }
  Poliaux(a, l, tortuga);
  g+=a;
  if(g%360!=0){
  	Poli(a, l, g, tortuga);
  }

  return 0;
}

int Poliaux(int a, double l, LOGO *tortuga)
{
  avanza(l, tortuga);
  Poli(-a, l/2.0, 0, tortuga);
  der(a, tortuga);

  return 0;
}
