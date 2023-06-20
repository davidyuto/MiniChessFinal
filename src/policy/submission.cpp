#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./submission.hpp"



Move Sub::get_move(State* state, int depth) {
    Move bestmove;
    int eval;
    if(!state->legal_actions.size())
        state->get_legal_actions();
    int max = INT_MIN;
    int min = INT_MAX;
    int alpha=INT_MIN;
    int beta = INT_MAX;
    int myself=state->player;
    for(auto& move :state->legal_actions){
        if(state->player){
            int val = minimax(state->next_state(move), depth-1, !state->player,alpha,beta);
            if(val < min){
                min = val;
                bestmove = move;
            }
        }
        else{
            int val = minimax(state->next_state(move), depth-1, !state->player,alpha,beta);
            if(val > max){
                max = val;
                bestmove = move;
            }
        }   
    }
    return bestmove;
}
int Sub::minimax(State* state, int depth, int player, int alpha, int beta) {
    if (depth == 0 || !state->legal_actions.size()) return state->evaluate();
    if(!state->legal_actions.size())
        state->get_legal_actions();
    if (player == 0) { // 最大化玩家
        int max_eval = INT_MIN;
        for (auto& move : state->legal_actions) {
            int eval = minimax(state->next_state(move), depth - 1, 1, alpha, beta);
            max_eval = std::max(max_eval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break; // Beta cut-off
            }
        }
        return max_eval;
    } else { // 最小化玩家
        int min_eval = INT_MAX;
        for (auto& move : state->legal_actions) {
            int eval = minimax(state->next_state(move), depth - 1, 0, alpha, beta);
            min_eval = std::min(min_eval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break; // Alpha cut-off
            }
        }
        return min_eval;
    }
}

