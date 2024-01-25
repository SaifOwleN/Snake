#include "../include/Snake.hpp"

int main() {
  Snake snake;
  Manager game(snake);
  game.run();
  return 0;
}
