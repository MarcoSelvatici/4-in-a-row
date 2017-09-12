#include "State.h"

State::State()
{
    for(int i = 0; i < 7; i++)
        height[i] = 0;

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 7; j++)
            grid[i][j] = '-';
}

State::~State()
{
    //dtor
}

void State::print_grid(){
    cout << "\n\n";
    for(int i = 5; i >= 0; i--){
        cout << "\n  ";
        for(int j = 0; j < 7; j++){
            cout << grid[i][j] << " ";
        }
    }
    cout << "\n  _____________\n  0 1 2 3 4 5 6";
}

void State::insert_coin(char player, int index){
    grid[height[index]][index] = player;
    height[index]++;
}

void State::remove_coin(int index){
    height[index]--;
    grid[height[index]][index] = '-';
}

char State::winner(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(grid[i][j] != '-'){
                // oriz
                if(j + 4 < 7){
                    int tmp = 0;
                    for(int k = 0; k < 4; k++){
                        if( grid[i][j] == grid[i][j+k] )
                            tmp++;
                        else if(grid[i][j+k] != grid[i][j]){
                            break;
                        }
                    }
                    if(tmp == 4){
                        return grid[i][j];
                    }
                    tmp = 0;
                }

                // vert
                if( i + 4 < 6){
                    int tmp = 0;
                    for(int k = 0; k < 4; k++){
                        if( grid[i][j] == grid[i+k][j])
                            tmp++;
                        else
                            break;
                    }
                    if(tmp == 4){
                        return grid[i][j];
                    }
                    tmp = 0;
                }

                // obliq up
                if( i + 4 < 6 && j + 4 < 7){
                    int tmp = 0;
                    for(int k = 0; k < 4; k++){
                        if( grid[i][j] == grid[i+k][j+k] )
                            tmp++;
                        else if(grid[i+k][j+k] != grid[i][j]){
                            break;
                        }
                    }
                    if(tmp == 4){
                        return grid[i][j];
                    }
                    tmp = 0;
                }

                // obliq down
                if( i - 4 >= 0 && j + 4 < 7){
                    int tmp = 0;
                    for(int k = 0; k < 4; k++){
                        if( grid[i][j] == grid[i-k][j+k] )
                            tmp++;
                        else if(grid[i-k][j+k] != grid[i][j]){
                            break;
                        }
                    }
                    if(tmp == 4){
                        return grid[i][j];
                    }
                    tmp = 0;
                }
            }
        }
    }
    return 'N';
}
