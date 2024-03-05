#pragma once
#include <raylib.h>
#include <cmath>

class Collider {
public:
  Vector2 pos;
  Vector2 size;

  Collider(int x, int y, int w, int h);

  const bool collidesWith(const Collider& other);
};