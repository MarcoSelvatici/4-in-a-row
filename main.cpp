#include <iostream>
#include <windows.h>

#include "Game.h"

using namespace std;

int main()
{
    //system("color f0");
    char choice;
    do{
        Game game;
        game.play();
        cout << "\n\nPress C to close\nPress any other key to play again ";
        cin >> choice;
        system("CLS");
    }while(choice != 'c' && choice != 'C');
    return 0;
}
