#include "engine/Game.hpp"

int main() {
  Game game = Game(600, 800);
  game.initWindow();

  while(game.run()) {
    game.update();
  };

  game.closeWindow();
  return 0;
};