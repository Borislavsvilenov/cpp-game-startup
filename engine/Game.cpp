#include "Game.hpp"

Game::Game(int w, int h) : WindowWidth(w), WindowHeight(h), player(300, 600, 0, 0, 10, 10, colliders) {
  SetTargetFPS(60);
};

void Game::initWindow () {
  InitWindow(WindowWidth, WindowHeight, "engine");
};

void Game::closeWindow() {
  CloseWindow();
};

const bool Game::run() {
  return !WindowShouldClose();
};

void Game::update() {
  BeginDrawing();
  ClearBackground((Color){7, 17, 37, 100});

  player.update(0.01f);
  player.draw();

  EndDrawing();
};