#include "nicolas.hpp"
#include <iostream>
using namespace std;
void play(tablero game, SmartPlayer x_player, Person o_player)
{
    char letter = 'X';
    int index;
    game.clean();
    while (game.pmove())
    {
        if (letter == 'O')
            index = o_player.movep(game);
        else
            index = x_player.bestmove(game);

        game.move(letter, index);
        cout << endl
             <<"   " <<letter << " makes move to " << index  << endl;
        game.print();
        cout << endl;

        if (game.winner(letter))
        {
            cout << endl
                 << letter << " wins !";
            return;
        }

        letter = (letter == 'X') ? 'O' : 'X';
    }
    cout << endl
         << "Draw";
}
int main(){
  cout<<"\n   T   R   I   Q   U   I\n"<<endl;
  tablero board;
  SmartPlayer p('X');
  Person p2('O');
  play(board, p, p2);
  return 0;
}
