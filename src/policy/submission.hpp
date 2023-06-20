#pragma once
#include "../state/state.hpp"

class Sub{
public:
  static Move get_move(State *, int );
  static int minimax(State *state, int, int , int , int );
};