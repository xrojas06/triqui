#include "nicolas.hpp"
//METODOS CLASE TABLERO

tablero::tablero(){
  number={48,49,50,51,52,53,54,55,56};//INICIALIZAR EL TABLERO CON LOS NUMEROS DEL 1 AL 9 EN CHAR
  clean();//FUNCION QUE REINCIA EL GANADOR Y EL TABLERO
}

void tablero::print(){
  //FUNCION PARA MOSTRAR EL TABLERO
  int u=0;
  for (int i = 0; i < 9; i++) {
     int j=0;
     if (i%3==0) {
        cout<<"  -------------------------"<<endl;
     }
     while (j!=4) {
        j++;
        if ( i%3==1 and j<4) {
           cout<<"  |   "<<(number[u])<<"\t";
           u++;
        }else{
          cout<< "  |\t";
        }
     }cout<<endl;
  }cout<<"  -------------------------"<<endl;
}

void tablero::cleanall(){//REINICIA CADA CASILLA CON SU VALOR CORRESPONDIENTE
  for (int i = 0; i < 9; i++) {
    number[i] = char(i+48);
  }
}

void tablero::clean(){
      cleanall();
      cleanwin();
}
bool tablero::empty(int p){
  //VERIFICAR SI LA CASILLA ESTA VACIA
  if (number[p] ==char(p+48)) {//SI LA CASILLA ES IGUAL A SU NUMERO EN CHAR ENTONCES ESTA VACIA
     return true;
  }return false;
}
bool tablero::pmove(){//FUNCION QUE VERIFICA SI HAY O NO CASILLAS VACIAS
  for (int i = 0; i < 9; i++){
    if (empty(i))
      return true;
  }return false;
}
vector<int> tablero::freec(){
  //CREACION DEL VECTOR QUE GUARDARA LAS CASILLAS LIBRES
  vector<int> c;
  for (int i = 0; i < 9; i++) {
    if (empty(i)) {
      c.push_back((i));
    }
  }return c;
}

bool tablero::winner(char s){//FUNCION QUE VERIFICA SI GANO EL JUGADOR DEL CARACTER QUE LE PASEMOS
//TODAS LAS POSIBLES FORMAS DE GANAR
  if (number[0]==number[3] && number[3]==number[6] && number[6]==s)
      return true;
  else if (number[1]==number[4] && number[4]==number[7] && number[7]==s)
    return true;
  else if (number[2]==number[5] && number[5]==number[8] && number[8]==s)
    return true;
  else if (number[0]==number[1] && number[1]==number[2] && number[2]==s)
    return true;
  else if (number[3]==number[4] && number[4]==number[5] && number[5]==s)
    return true;
  else if (number[6]==number[7] && number[7]==number[8] && number[8]==s)
    return true;
  else if (number[0]==number[4] && number[4]==number[8] && number[8]==s)
    return true;
  else if (number[2]==number[4] && number[4]==number[6] && number[6]==s)
    return true;
  return false;
}

void tablero::move(char s, int i){
  //FUNCION QUE REEMPLAZA EL NUMERO DE UNA CASILLA POR X o O Y REVISA SI GANO Y GUARDANDO EN LA VARIABLE WIN EL GANADOR
  number[i] = s;
  if (winner(s))
      win = s;
}

void tablero::cleanc(int i){//FUNCION QUE REINICIA UNA CASILLA DADA
  number[i] = char(i+48);
}
//METODDS DE LA CLASE PERSON
int Person::movep(tablero leo){//FUNCION PARA REALIZAR UN MOVIMIENTO, GUARDANDO EL NUMERO DE LA CASILLA QUE DIGITA EL USUARIO
  int index;
  cout << "  ELIGA UNA CASILLA: ";
  cin >> index;
  return index;
}

//METODOS DE LA CLASE SMARTPLAYER

int SmartPlayer::bestmove(tablero leo){//FUNCION QUE LLAMA A MINIMAX Y RETORNA UN ENTERO CON LA CASILLA QUE SE HA GUARDADO EN EL MOVIMIENTO ELEGIDO POR MINIMAX
  Move smartmove;
  smartmove = minimax(leo, get_Spsymbol());
  return smartmove.i;
}
Move SmartPlayer::minimax(tablero inicial, char ismax ){//FUNCION RECURSIVA
  //inicial.print();
  // cout<<endl;
  char max = s;
  char rival = (ismax == 'X') ? 'O' : 'X'; //DEPENDIENDO DE QUE JUGADOR ESTA EN EL MOMENTO ENTONCES GUARDAREMOS EL CONTRARIO
  Move best;
  Move maxmini;
  if (inicial.winner(rival)){//SI EL JUGADOR ANTERIOR GANO
      if (rival != max)//SI ES DISTINTO A EL QUE QUEREMOS MAXIZIMAR LE DAMOS EL MENOR VALOR
          best.utilidad = -100;
      else {//SI SI ES, ENTONCES LE DAMOS EL MAYOR VALOR
              best.utilidad = 100;
      }//RETORNAMOS EL MOVIMIENTO CON EL VALOR
      return best;
  }
  if (!inicial.pmove()){//SI NO HAY GANADOR PERO NO HAY MAS CASILLAS VACIAS = EMPATE
      best.utilidad = 0;//SI ES EMPATE EL VALOR UTIL ES 0
      return best;
  }
  if (ismax == max){// SI EL JUGADOR QUE ESTA JUGANDO AHORA ES EL QUE VA A MAXIMIZAR, LO INICIALIZAMOS CON EL MENOR VALOR POSIBLE
      best.utilidad = -100;
  }else{// SI ES EL QUE SE VA A MINIMIZAR, LO INICIALIZAMOS CON EL MAYOR VALOR POSIBLE
      best.utilidad = 100;
  }
  //GUARDAMOS EN UN VECTOR TODAS LAS CASILLAS LIBRES EN EL MOMENTO  CON LA FUNCION FREEC
  vector<int> moves = inicial.freec();
  for (int i = 0; i < moves.size(); i++)//ITERAMOS EN CADA UNA DE LAS CASILLAS LIBRES
  {
      inicial.move(ismax, moves[i]);//HACEMOS EL CAMBIO POR EL JUGADOR DEL MOMENTO EN UNA CASILLA DEL VECTOR
      maxmini= minimax(inicial, rival);//HACEMOS LA LLAMADA RECURSIVA Y LA GUARDAMOS
      //inicial.print();
      //cout<<inicial.getWin()<<" ";
      inicial.cleanc(moves[i]);//REINICIAMOS LA CASILLA QUE CAMBIAMOS
      inicial.cleanwin();//REINICIAMOS EL GANADOR
      maxmini.i = moves[i];//GUARDAMOS LA CASILLA QUE PROBAMOS EN UN MOVIMIENTO POSIBLE
      //cout<<"NICOLAS: "<<nicolas.utilidad<<" BEST: "<<best.utilidad<<endl;
      if (ismax == max){//SI ES EL JUGADOR ES MAX ENTONCES REMPLAZAREMOS EL VALOR DE BEST POR EL MAYOR ENTRE SI MISMO Y EL QUE RETORNAMOS CON MINIMAX
          if (maxmini.utilidad > best.utilidad)
              best = maxmini;
      }else{//SI NO, REEMPLAZAMOS POR EL MENOR
          if (maxmini.utilidad < best.utilidad)
              best = maxmini;
      }//cout<<best.utilidad<<endl;
  }
  return best;
}

//METODOS CLASE TRIQUI
Triqui::Triqui(){ //CONSTRUCTOR
  turns = 0;
}
void Triqui::vc(int n, char jugada){
  //VERIFICAR QUE LA CASILLA QUE HA SIDO ESCOGIDA POR EL JUGADOR ESTE VACIA Y CAMBIAR POR EL SIMBOLO DE DICHO JUGADOR
  if (b.empty(n)){
    b.move(jugada, n);
    turns++;
  }else{
    cout<<"  CASILLA OCUPADA! PORFAVOR ELIJA OTRA"<<endl;
  }
}
bool Triqui::conti(){//FUNCION PARA VERIFICAR SI SE CONTINUA EL JUEGO DEPENDIENDO DE SI HAY GANADOR O SI NO HAY MAS CASILLAS VACIAS
  if (b.winner('O') or b.winner('X') or b.pmove()==false){
    return false;
  }return true;
}
void Triqui::printwinner(){//FUNCION QUE MUESTRA EL GANADOR DEL JUEGO O SI ES EMPATE
  if (!b.winner('X') and !b.winner('O')) {
    cout<<"       T     I     E"<<endl;
  }else{
    cout<<"   W  I  N  N  E  R  :   "<<b.getWin();}
}
void Triqui::smartgame(){
  b.print();
  int n=0;//N QUE GUARDARA LA CASILLA ELEGIDA POR EL JUGADOR
  char jugada;//CHAR JUGADA QUE GUARDARA EL SIMBOLO DEL JUGADOR
  do {//CICLO DO WHILE HASTA QUE HAYA UN GANADOR O UN EMPATE
    if (turns%2==1) {//SI EL TURNO ES IMPAR LE TOCA AL USUARIO
        n = player.movep(b);//GUARDAR SU CASILLA ELEGIDA
        jugada = player.get_psymbol();//GUARDAR SU SIMBOLO
    }else{
       n = bestcompu.bestmove(b);//GUARDAR LA CASILLA ELEGIDA POR LA IA
       jugada = bestcompu.get_Spsymbol();//GUARDAR EL SIMBOLO
       cout<<"  CASILLA ELEGIDA: "<<n<<endl;
    } vc(n,jugada);//VERIFICAR LA CASILLA VACIA Y CAMBIAR POR EL SIMBOLO JUGADA
    b.print();//MOSTRAR EL NUEVO TABLERO CON LOS CAMBIOS
  } while(conti());
  printwinner();
}
