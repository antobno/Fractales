#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "Hilbert.h"

int nivelRecursionHilbert;
double longitudHilbert;
double miX0Hilbert;
double miY0Hilbert;
LOGO *tortugaAuxHilbert;

int Hilbert(int n, double l, int par, LOGO *tortuga);

int iniciaHilbert(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionHilbert=n;
  longitudHilbert = l;
  miX0Hilbert=x;
  miY0Hilbert=y;
  tortugaAuxHilbert = tortuga;
  
  return 0;
}

int dibujaHilbert(void){
  inicia(miX0Hilbert, miY0Hilbert, 0, ABAJO, tortugaAuxHilbert);

  return Hilbert(nivelRecursionHilbert, longitudHilbert, 1, tortugaAuxHilbert);
}

int Hilbert(int n, double l, int par, LOGO *tortuga)
{
  if (n<=0){
    return 0;
  }
  izq(90*par, tortuga);
  Hilbert(n-1, l, -par, tortuga);
  avanza(l, tortuga);
  der(90*par, tortuga);
  Hilbert(n-1, l, par, tortuga);
  avanza(l, tortuga);
  Hilbert(n-1, l, par, tortuga);
  der(90*par, tortuga);
  avanza(l, tortuga);
  Hilbert(n-1, l, -par, tortuga);
  izq(90*par, tortuga);
  
  return 0;
}
