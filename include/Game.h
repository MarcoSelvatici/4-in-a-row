#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "Minimax_agent.h"
#include "Player.h"
#include "iostream"
#include "stdlib.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        State game_state;
        Minimax_agent agent;
        Player player;
        void play();
};

#endif // GAME_H
