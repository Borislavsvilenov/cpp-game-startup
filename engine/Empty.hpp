#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "Collider.hpp"

class Empty {
public:
  Vector2 pos;
  Vector2 vel;
  Vector2 accel;
  Vector2 size;
  Collider collider;
  float minVel = 0.01f;
  int id;

  Empty(int x, int y, int vx, int vy, int w, int h, std::vector<Collider> &colliders, int i);

  void update(float dt, std::vector<Collider> &colliders);

  void draw();
};