#ifndef STATE_H
#define STATE_H

#include "iostream"

using namespace std;

class State
{
    public:
        State();
        virtual ~State();

        char grid[6][7];
        int height[7];

        void insert_coin(char next_player, int index);
        void remove_coin(int index);
        char winner();
        void print_grid();
};

#endif // STATE_H
