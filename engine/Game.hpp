#pragma once
#include <raylib.h>
#include <vector>
#include <cmath>
#include "Collider.hpp"
#include "Player.hpp"

class Game {
public:
  int WindowWidth;
  int WindowHeight;

  std::vector<Collider*> colliders;

  Player player;

  Game(int w, int h);

  const bool run();

  void initWindow();
  void closeWindow();
  void update();
};