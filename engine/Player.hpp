#pragma once
#include <raylib.h>
#include <cmath>

class Player {

public:
  Vector2 pos;
  Vector2 vel;
  Vector2 accel;
  float minVel = 0.01f;

  Player(int x, int y, int vx, int vy);

  void getInput();
  void update(float dt);

  void draw();
};