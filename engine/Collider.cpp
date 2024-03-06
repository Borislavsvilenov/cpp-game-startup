#include "Collider.hpp"

Collider::Collider(int x, int y, int w, int h) {
  pos.x = x;
  pos.y = y;
  size.x = w;
  size.y = h;
};

const bool Collider::collidesWith(const Collider& other) {
  return (pos.x < other.pos.x + other.size.x &&
          pos.x + size.x > other.pos.x &&
          pos.y < other.pos.y + other.size.y &&
          pos.y + size.y > other.pos.y);
};
