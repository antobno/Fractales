#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "Gosper.h"

int nivelRecursionGosper;
double longitudGosper;
double miX0Gosper;
double miY0Gosper;
double aux;
LOGO *tortugaAuxGosper;

int RGosper(int n, double l, LOGO *tortuga);
int LGosper(int n, double l, LOGO *tortuga);

int iniciaGosper(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionGosper=n;
  longitudGosper = l;
  miX0Gosper=x;
  miY0Gosper=y;
  aux=1.0/sqrt(7.0);
  tortugaAuxGosper = tortuga;
  
  return 0;
}

int dibujaGosper(void){
  inicia(miX0Gosper, miY0Gosper, 0, ABAJO, tortugaAuxGosper);

  return RGosper(nivelRecursionGosper, longitudGosper, tortugaAuxGosper);
}

int RGosper(int n, double l, LOGO *tortuga)
{
  double laux;
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  laux=l*aux;
  der(75, tortuga);
  LGosper(n-1, laux, tortuga);
  izq(60, tortuga);
  RGosper(n-1, laux, tortuga);
  RGosper(n-1, laux, tortuga);
  izq(120, tortuga);
  RGosper(n-1, laux, tortuga);
  izq(60, tortuga);
  LGosper(n-1, laux, tortuga);
  der(120, tortuga);
  LGosper(n-1, laux, tortuga);
  der(60, tortuga);
  RGosper(n-1, laux, tortuga);
  izq(15, tortuga);
  
  return 0;
}

int LGosper(int n, double l, LOGO *tortuga)
{
  double laux;
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  laux=l*aux;
  der(15, tortuga);
  LGosper(n-1, laux, tortuga);
  izq(60, tortuga);
  RGosper(n-1, laux, tortuga);
  izq(120, tortuga);
  RGosper(n-1, laux, tortuga);
  der(60, tortuga);
  LGosper(n-1, laux, tortuga);
  der(120, tortuga);
  LGosper(n-1, laux, tortuga);
  LGosper(n-1, laux, tortuga);
  der(60, tortuga);
  RGosper(n-1, laux, tortuga);
  izq(75, tortuga);

  return 0;
}
