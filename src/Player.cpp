#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

State Player::do_action(State curr_state){
    cout << "\n\nInsert position of your coin: ";
    int p;
    do{
        cin >> p;
    }while((p < 0 || p > 6) || curr_state.height[p] >= 6);
    curr_state.insert_coin('O', p);
    return curr_state;
}
