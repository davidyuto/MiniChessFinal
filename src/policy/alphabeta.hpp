#pragma once
#include "../state/state.hpp"

class Alphabeta{
public:
  static Move get_move(State *, int );
  static int minimax(State *state, int, int , int , int );
};