#pragma once
#include <raylib.h>
#include <vector>
#include <cmath>
#include "Collider.hpp"
#include "Player.hpp"
#include "Empty.hpp"

class Game {
public:
  int WindowWidth;
  int WindowHeight;

  std::vector<Collider*> colliders;
  std::vector<Empty> NPCs;

  Player player;

  Game(int w, int h);

  const bool run();

  void initWindow();
  void closeWindow();
  void update();
};