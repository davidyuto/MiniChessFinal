
#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./minimax.hpp"


Move Minimax::get_move(State *state, int depth){
    Move bestmove;
    int eval;
    if(!state->legal_actions.size())
        state->get_legal_actions();
    int max = INT_MIN;
    int min = INT_MAX;
    int myself=state->player;
    for(auto& move :state->legal_actions){
        if(state->player){
            int val = minimax(state->next_state(move), depth-1, !state->player);
            if(val < min){
                min = val;
                bestmove = move;
            }
        }
        else{
            int val = minimax(state->next_state(move), depth-1, !state->player);
            if(val > max){
                max = val;
                bestmove = move;
            }
        }   
    }
    return bestmove;
}

int Minimax::minimax(State* state, int depth, int player){
    if (depth == 0 || !state->legal_actions.size()) return state->evaluate();
    int value=0;
    if(!state->legal_actions.size())
        state->get_legal_actions();
    if (player==0) { // 最大化玩家
        value=INT_MIN;
        for (auto& move : state->legal_actions) {
            int eval = minimax(state->next_state(move), depth - 1, 1 );
            value = std::max(value, eval);
        }
    } else { // 最小化玩家
        value=INT_MAX;
        for (auto& move : state->legal_actions) {
            int eval = minimax(state->next_state(move), depth - 1, 0);
            value = std::min(value, eval);
        }
    }
    return value;
}

