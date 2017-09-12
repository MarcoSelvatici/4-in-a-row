#ifndef PLAYER_H
#define PLAYER_H

#include "State.h"
#include "iostream"

using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();

        State do_action(State curr_state);
};

#endif // PLAYER_H
