/*#pragma once
#include "../state/state.hpp"

class MiniMax{
public:
  static Move get_move(State *, int );
  static int minimax(State* ,int ,int , int);
};*/

#pragma once
#include "../state/state.hpp"

class Minimax{
public:
  static Move get_move(State *, int );
  static int minimax(State *, int , int);
};