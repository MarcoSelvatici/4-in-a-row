#include "Game.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::play(){
    int moves = 0;
    game_state.print_grid();
    do{
        if(moves % 2 == 0)
            game_state = player.do_action(game_state);
            //game_state = agent.do_action(game_state);
        else
            game_state = agent.do_action(game_state);
            //game_state = player.do_action(game_state);
        system("CLS");
        game_state.print_grid();
        moves++;
    }
    while(game_state.winner() == 'N' && moves < 42);
    std::cout << "\n\n  End of the game. Winner: " <<game_state.winner() << std::endl;
}

