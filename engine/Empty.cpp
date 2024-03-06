#include "Empty.hpp"

Empty::Empty (int x, int y, int vx, int vy, int w, int h, std::vector<Collider*> &colliders) : collider(x, y, w, h) {
  pos.x = x;
  pos.y = y;
  vel.x = vx;
  vel.y = vy;
  accel.x = 0;
  accel.y = 0;
  size.x = w;
  size.y = h;
  colliders.push_back(&collider);
};
void Empty::update (float dt, std::vector<Collider*> &colliders) {
  friction();

  vel.x += accel.x * dt;
  vel.y += accel.y * dt;

  for (Collider* other : colliders) {
    if (&collider != other) {
      if (collider.collidesWith(*other)) {
        Vector2 diff;
        diff.x = collider.pos.x - other->pos.x;
        diff.y = collider.pos.y - other->pos.y;
        float d = std::sqrt(diff.x * diff.x + diff.y * diff.y);
        float overlap = (collider.size.x + other->size.x - d) / 2;

        diff.x /= d;
        diff.y /= d;

        pos.x += diff.x * overlap;
        pos.y += diff.y * overlap;

        vel.x = 0;
        vel.y = 0;
      }
    }
  }

  pos.x += vel.x;
  pos.y += vel.y;  

  if(fabs(vel.x) < minVel) {
    vel.x = 0;
  }
  if(fabs(vel.y) < minVel) {
    vel.y = 0;
  }

  collider.pos.x = pos.x;
  collider.pos.y = pos.y;

};

void Empty::friction () {
  if(vel.x > 0) {
    accel.x = -5;
  } else if(vel.x < 0) {
    accel.x = 5;
  } else {
    accel.x = 0;
  }

  if(vel.y > 0) {
    accel.y = -5;
  } else if(vel.y < 0) {
    accel.y = 5;
  } else {
    accel.y = 0;
  }
}

void Empty::draw () {
  DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);
}