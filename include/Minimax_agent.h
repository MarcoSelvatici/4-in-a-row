#ifndef MINIMAX_AGENT_H
#define MINIMAX_AGENT_H

#include "State.h"
#include "vector"
#include "iostream"
#include "stdlib.h"
#include "time.h"

using namespace std;

class Minimax_agent
{
    public:
        Minimax_agent();
        virtual ~Minimax_agent();

        int limit_depth;

        double discount(double val, int depth);
        double max_value(State state, int depth, double alpha, double beta);
        double min_value(State state, int depth, double alpha, double beta);
        State do_action(State curr_state);
        std::vector<State> get_successors(State state, char next_player);
        double evaluate_state(State state);
};

#endif // MINIMAX_AGENT_H
