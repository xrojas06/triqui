#ifndef __NICOLAS_HPP
#define __NICOLAS_HPP
#include <iostream>
#include <vector>
#include<stdlib.h>
using namespace std;

struct Move{
  int i;
  int utilidad;
};
class tablero{
private:
    vector<char> number;//VECTOR CON EL NUMERO DE CADA CASILLA EN CHAR
    char win;
public:
  tablero();//CONSTRUCTOR DE LA CLASE
  void print();//MOSTRAR EL TABLERO
  void cleanall();
  void cleanwin() { win = ' '; }
  void clean();
  void change(char s, int i);//INTERCAMBIAR EL NUMERO DE LA CASILLA POR EL SIMBOLO DEL JUGADOR
  char getc(int i){return number[i];}
  char getWin() { return win; }
  bool empty(int p);//FUNCION PARA VERIFICAR SI UNA CASILLA ESPECIFICA(P) ESTA VACIA
  bool pmove();
  vector<int> freec();
  bool winner(char s);
  void move(char s, int i);
};

//CLASE PERSON PARA EL JUGADOR QUE VA EN CONTRA DEL ALGORITMO
class Person{
private:
  char s;//SIMBOLO DEL JUGADOR: 'O'
public:
  Person(char sb){ s = sb;}//CONSTRUCTOR CLASE PERSON
  int movep(tablero leo);//FUNCION PARA RETORNAR EL NUMERO DE CASILLA ELEGIDA POR EL USUARIO
  char get_psymbol(){ return s;}//RETORNAR EL SIMBOLO DEL JUGADOR
};

class SmartPlayer{
private:
  char s;
  Move SPrandommove(vector<int> c);
public:
  SmartPlayer(char sb){ s = sb;}
  int bestmove(tablero leo);
  char get_Spsymbol(){ return s;}
  Move minimax(tablero red, char blue);
};
#endif
