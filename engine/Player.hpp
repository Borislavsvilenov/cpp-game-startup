#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "Collider.hpp"

class Player {

public:
  Vector2 pos;
  Vector2 vel;
  Vector2 accel;
  Vector2 size;
  Collider collider;
  float minVel = 0.01f;

  Player(int x, int y, int vx, int vy, int w, int h, std::vector<Collider*> &colliders);

  void getInput();
  void update(float dt, std::vector<Collider*> &colliders);

  void draw();
};