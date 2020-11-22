#ifndef __NICOLAS_HPP
#define __NICOLAS_HPP
#include <iostream>
#include <vector>
#include<stdlib.h>
using namespace std;

struct Move{//ESTRUCTURA MOVA QUE GUARDA UNA CASILLA Y EL VALOR DE UTILIDAD ASOCIADO A DICHA CASILLA
  int i;
  int utilidad;
};
//CLASE TABLERO
class tablero{
private:
    vector<char> number;//VECTOR CON EL NUMERO DE CADA CASILLA EN CHAR
    char win;//GANADOR DEL JUEGO
public:
  tablero();//CONSTRUCTOR DE LA CLASE
  void print();//MOSTRAR EL TABLERO
  void cleanall();//REINICIAR TODAS LAS CASILLAS
  void cleanwin() { win = ' '; }//REINICIAR EL GANADOR
  void clean();//REINICIAR LAS CASILLAS Y EL GANADOR
  char getWin() { return win; }//RETORNAR EL GANADOR
  bool empty(int p);// VERIFICAR SI UNA CASILLA ESPECIFICA(P) ESTA VACIA
  bool pmove();//VERIFICAR SI HAY CASILLAS VACIAS AUN
  vector<int> freec();//GUARDAR QUE CASILLAS ESTAN VACIAS
  bool winner(char s);//SABER SI GANO UN JUGADOR
  void move(char s, int i); //REALIZAR UN MOVIMIENTO EN EL TABLERO
  void cleanc(int i);//REINICIAR UNA CASILLAS
};

//CLASE PERSON PARA EL JUGADOR QUE VA EN CONTRA DEL ALGORITMO
class Person{
private:
  char s;//SIMBOLO DEL JUGADOR: 'O'
public:
  Person(){ s = 'O';}//CONSTRUCTOR CLASE PERSON
  int movep(tablero leo);//FUNCION PARA RETORNAR EL NUMERO DE CASILLA ELEGIDA POR EL USUARIO
  char get_psymbol(){ return s;}//RETORNAR EL SIMBOLO DEL JUGADOR
};

class SmartPlayer{
private:
  char s;//SIMBOLO DEL JUGADOR: 'x'
public:
  SmartPlayer(){ s = 'X';}// CONSTRUCTOR
  int bestmove(tablero leo);//RETORNA LA CASILLA SEGUN EL MEJOR MOVIMIENTO
  char get_Spsymbol(){ return s;}//RETORNA EL SIMBOLO DEL JUGADOR
  Move minimax(tablero inicial, char ismax);//ELIGE EL MEJOR MOVIMIENTO SEGUN EL TABLERO Y UN CARACTER
};

class Triqui{
private:
  tablero b;//EL TABLERO DE JUEGO
  Person player;//EL USUARIO QUE VA A JUGAR
  SmartPlayer bestcompu;// EL JUGADOR QUE TRATARA DE GANAR O EMPATAR
  int turns;//UN CONTADOR QUE GUARDA EL TURNO EN EL QUE VA EL JUEGO
  void vc(int n, char jugada);//FUNCION PRIVADA QUE VERIFICA SI UNA CASILLA ESTA VACIA Y SI SI HACE EL CAMBIO DE ESTA POR EL SIMBOLO DEL JUGADOR
public:
  Triqui();//CONSTRUCTOR DE LA CLASE
  void smartgame();//MODALIDAD DEL JUEGO CONTRA EL OPONENTE QUE BUSCA NO PERDER
  bool conti();//VERIFICAR SI SE PUEDE CONTINUAR EL JUEGO
  void printwinner();//MOSTRAR LE GANADOR O SI HUBO EMPATE
};
#endif
