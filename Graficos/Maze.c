#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "Maze.h"

int nivelRecursionMaze;
double longitudMaze;
double miX0Maze;
double miY0Maze;
int paridad;
LOGO *tortugaAuxMaze;

int Maze(int n, double l, LOGO *tortuga);
int Mazeaux(double l, LOGO *tortuga);

int iniciaMaze(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionMaze=n;
  longitudMaze = l;
  miX0Maze=x;
  miY0Maze=y;
  tortugaAuxMaze = tortuga;
  
  return 0;
}

int dibujaMaze(void){
  paridad=-1;
  inicia(miX0Maze, miY0Maze, 0, ABAJO, tortugaAuxMaze);

  return Maze(nivelRecursionMaze, longitudMaze, tortugaAuxMaze);
}

int Maze(int n, double l, LOGO *tortuga)
{
  double laux;
  int i, j;
  if (n<=0){
    MazeAux(l, tortuga);
    return 0;
  }
  laux=l/3.0;
  Maze(n-1, laux, tortuga);
  izq(90, tortuga);
  Maze(n-1, laux, tortuga);
  for(i=0; i<3; i++){
  	der(90, tortuga);
    Maze(n-1, laux, tortuga);	
  }
  for(j=0; j<3; j++){
  	izq(90, tortuga);
    Maze(n-1, laux, tortuga);
  }
  der(90, tortuga);
  Maze(n-1, laux, tortuga);
  
  return 0;
}

int MazeAux(double l, LOGO *tortuga)
{
  double laux;
  
  paridad=-paridad;
  laux=l/5.0;
  paridad=1;
  izq(45, tortuga);
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
  der(90*paridad, tortuga);
  avanza(4.0*laux, tortuga);
  izq(45, tortuga);

  return 0;
}
