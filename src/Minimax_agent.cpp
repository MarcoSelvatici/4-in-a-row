#include "Minimax_agent.h"

#define INF 1000

Minimax_agent::Minimax_agent()
{
    cout << "\n Set the depth of your adversary (1->10):\n 4) easy\n 6) medium\n 8) hard\n 10) extreme (sometimes slow)\n ";
    cin >> limit_depth;
    system("CLS");
    //limit_depth = 8;
    srand(time(NULL));
}

Minimax_agent::~Minimax_agent()
{
    //dtor
}

double Minimax_agent::discount(double val, int depth){
    if(val > 0)
        return ( val - 0.001 * (double)depth );
    else if(val < 0)
        return ( val + 0.001 * (double)depth );
    else // val == 0
        return val;
}

double Minimax_agent::max_value(State state, int depth, double alpha, double beta){
    if(state.winner() == 'O')
        return discount(-1, depth);
    if(depth == limit_depth)
        return evaluate_state(state);

    double best_value = -INF;
    for(auto successor: get_successors(state, 'X')){
        best_value = max(best_value, min_value(successor, depth + 1, alpha, beta));
        if(best_value > beta)
            return best_value;
        alpha = max(alpha, best_value);
    }
    return discount(best_value, depth);
}

double Minimax_agent::min_value(State state, int depth, double alpha, double beta){
    if(state.winner() == 'X')
        return discount(1, depth);
    if(depth == limit_depth)
        return evaluate_state(state);

    double best_value = INF;
    for(auto successor: get_successors(state, 'O')){
        best_value = min(best_value, max_value(successor, depth + 1, alpha, beta));
        if(best_value < alpha)
            return best_value;
        beta = min(beta, best_value);
    }
    return discount(best_value, depth);
}

State Minimax_agent::do_action(State curr_state){
    double best_value = -INF;
    vector<State> best_successors;
    cout << "\n";
    for(auto successor: get_successors(curr_state, 'X')){
        double tmp = min_value(successor, 1, -INF, INF);
        cout << " " << tmp;
        if( tmp > best_value){
            best_successors.clear();
            best_value = tmp;
            best_successors.push_back(successor);
        }
        else if(tmp == best_value){
            best_successors.push_back(successor);
        }
    }
    //cout << "\n\n best_value: " << best_value << "\n";
    return best_successors[rand() % best_successors.size()];
}

vector<State> Minimax_agent::get_successors(State state, char next_player){
    vector<State> successors;
    for(int i = 0; i < 7; i++){
        if(state.height[i] < 6){
            state.insert_coin(next_player, i);
            successors.push_back(state);
            state.remove_coin(i);
        }
    }
    return successors;
}

double Minimax_agent::evaluate_state(State state){
    int cont1 = 0;
    int cont2 = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(state.grid[i][j] != '-'){
                // oriz
                if(j + 3 < 7){
                    int tmp = 0;
                    for(int k = 0; k < 3; k++){
                        if( state.grid[i][j] == state.grid[i][j+k] )
                            tmp++;
                        else if(state.grid[i][j+k] != state.grid[i][j] && state.grid[i][j+k] != '-'){
                            tmp = 0;
                            break;
                        }
                    }
                    if(tmp == 3){
                        if(state.grid[i][j] == 'X') cont1++;
                        else cont2++;
                    }
                }

                // vert
                if( i + 3 < 6){
                    int tmp = 0;
                    for(int k = 0; k < 3; k++){
                        if( state.grid[i][j] == state.grid[i+k][j] )
                            tmp++;
                        else if(state.grid[i+k][j] != state.grid[i][j] && state.grid[i+k][j] != '-'){
                            tmp = 0;
                            break;
                        }
                    }
                    if(tmp == 3){
                        if(state.grid[i][j] == 'X') cont1++;
                        else cont2++;
                    }
                }

                // obliq up
                if( i + 3 < 6 && j + 3 < 7){
                    int tmp = 0;
                    for(int k = 0; k < 3; k++){
                        if( state.grid[i][j] == state.grid[i+k][j+k] )
                            tmp++;
                        else if(state.grid[i+k][j+k] != state.grid[i][j] && state.grid[i+k][j+k] != '-'){
                            tmp = 0;
                            break;
                        }
                    }
                    if(tmp == 3){
                        if(state.grid[i][j] == 'X') cont1++;
                        else cont2++;
                    }
                }

                // obliq down
                if( i - 3 >= 0 && j + 3 < 7){
                    int tmp = 0;
                    for(int k = 0; k < 3; k++){
                        if( state.grid[i][j] == state.grid[i-k][j+k] )
                            tmp++;
                        else if(state.grid[i-k][j+k] != state.grid[i][j] && state.grid[i-k][j+k] != '-'){
                            tmp = 0;
                            break;
                        }
                    }
                    if(tmp == 3){
                        if(state.grid[i][j] == 'X') cont1++;
                        else cont2++;
                    }
                }
            }
        }
    }
    if(0.05*(cont1-cont2) >= 1) cout << "\n ######### " << 0.05*(cont1-cont2);
    else if(0.05*(cont1-cont2) <= -1) cout << "\n ######### " << 0.05*(cont1-cont2);
    return 0.05*(cont1-cont2);
}

