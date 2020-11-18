#include "nicolas.hpp"

//METODOS CLASE TABLERO

tablero::tablero(){
  number={48,49,50,51,52,53,54,55,56};//INICIALIZAR EL TABLERO CON LOS NUMEROS DEL 1 AL 9 EN CHAR
  clean();
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

void tablero::cleanall(){
  for (int i = 0; i < 9; i++) {
    number[i] = char(i+48);
  }
}

void tablero::clean(){
      cleanall();
      cleanwin();
}
void tablero::change(char s, int i){
  number[i] = s;
}
bool tablero::empty(int p){
  //VERIFICAR SI LA CASILLA ESTA VACIA
  if (number[p] ==char(p+48)) {//SI LA CASILLA ES IGUAL A SU NUMERO EN CHAR ENTONCES ESTA VACIA
     return true;
  }return false;
}
bool tablero::pmove(){
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

bool tablero::winner(char s){
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
else if (number[0] !='0' && number[1] != '1' && number[2] != '2' && number[3] != '3' && number[4] != '4' && number[5] != '5' && number[6] != '6' && number[7] !=7
  && number[8]!= '8')
  return true;
//TODAS LAS CASILLAS LLENAS PERO NINGUN GANADOR
return false;
}

void tablero::move(char s, int i){
  number[i] = s;
  if (winner(s))
      win = s;
}

int Person::movep(tablero leo){
  int index;
  while (1)
  {
      cout << "\nEnter index: ";
      cin >> index;

      if (leo.empty(index))
          return index;

      cout << "Wrong Move";
  }
}
Move SmartPlayer::SPrandommove(vector<int> c){
  //GENERAR NUMERO ALEATORIO CON EL TAMAÑO DEL VECTOR
  Move random;
  int randomc;
  int sz=c.size();
  randomc =  rand()%sz;
  cout<<"  Casilla elegida: "<<c[randomc]<<endl;
  random.i = c[randomc];
  return random;
}
int SmartPlayer::bestmove(tablero leo){
  Move smartmove;
  if (leo.freec().size() == 9)
      smartmove = SPrandommove(leo.freec());
  else
      smartmove = minimax(leo, get_Spsymbol());
  return smartmove.i;
}
Move SmartPlayer::minimax(tablero red, char current){
  char max = s;
  char other_player = (curr_player == 'X') ? 'O' : 'X';
  
}
