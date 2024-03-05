#pragma once
#include <raylib.h>
#include "Player.hpp"

class Game {
public:
  int WindowWidth;
  int WindowHeight;

  Player player;

  Game(int w, int h);

  const bool run();

  void initWindow();
  void closeWindow();
  void update();
};