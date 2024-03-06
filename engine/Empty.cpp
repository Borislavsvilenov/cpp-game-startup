#include "Empty.hpp"

Empty::Empty (int x, int y, int vx, int vy, int w, int h, std::vector<Collider> &colliders, int i) : collider(x, y, w, h) {
  pos.x = x;
  pos.y = y;
  vel.x = vx;
  vel.y = vy;
  accel.x = 0;
  accel.y = 0;
  size.x = w;
  size.y = h;
  id = i;
  colliders.push_back(collider);
};
void Empty::update (float dt, std::vector<Collider> &colliders) {
  vel.x += accel.x * dt;
  vel.y += accel.y * dt;

  for (int i = 0; i < colliders.size(); i++) {
    if (id != i) {
      if (collider.collidesWith(colliders[i])) {
        Vector2 diff;
        diff.x = collider.pos.x - colliders[i].pos.x;
        diff.y = collider.pos.y - colliders[i].pos.y;
        float d = std::sqrt(diff.x * diff.x + diff.y * diff.y);
        float overlap = (collider.size.x + colliders[i].size.x - d) / 2;

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

void Empty::draw () {
  DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);
}