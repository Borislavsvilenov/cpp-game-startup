#include "Player.hpp"

Player::Player (int x, int y, int vx, int vy, int w, int h, std::vector<Collider>& colliders) : collider(x, y, w, h) {
  pos.x = x;
  pos.y = y;
  vel.x = vx;
  vel.y = vy;
  accel.x = 0;
  accel.y = 0;
  width = w;
  height = h;
  colliders.push_back(collider);
};
void Player::update (float dt) {
  getInput();

  vel.x += accel.x * dt;
  vel.y += accel.y * dt;

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


void Player::getInput () {
  if(IsKeyDown(KEY_RIGHT)) {
    accel.x = 20;
  } else if(IsKeyDown(KEY_LEFT)) {
    accel.x = -20;
  } else {
    if(vel.x > 0) {
      accel.x = -5;
    } else if(vel.x < 0) {
      accel.x = 5;
    } else {
      accel.x = 0;
    }
  } 

  if(IsKeyDown(KEY_UP)) {
    accel.y = -20;
  } else if(IsKeyDown(KEY_DOWN)) {
    accel.y = 20;
  } else {
    if(vel.y > 0) {
      accel.y = -5;
    } else if(vel.y < 0) {
      accel.y = 5;
    } else {
      accel.y = 0;
    }
  }
};

void Player::draw () {
  DrawRectangle(pos.x, pos.y, width, height, WHITE);
}