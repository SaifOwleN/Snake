#include <cstdlib>
#include <deque>
#include <iostream>
#include <ncurses.h>
#include <utility>
int x = 0;
const short rows = 20;
const short cols = 20;
const int randomB = (int)(rand() / (RAND_MAX + 1.0));

void input() {}

class Universe {
public:
  void print();
};

class Snake {
public:
  void eat();
  void move(char);
  void lose();
  void spawn();
  std::pair<int, int> getPosition();
  void setPosition();

private:
  std::pair<int, int> position;
  std::deque<std::deque<int>> blocks;
};

std::pair<int, int> Snake::getPosition() { return position; }

void Snake::setPosition() {}

class Manager {
public:
  void initialize();
  void run();
  Manager(Universe *, Snake *);

private:
  Universe *universePtr;
  Snake *snakePtr;
};

void Snake::spawn() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      blocks[i][j] = 0;
    }
  }
  blocks[randomB * rows][randomB * cols] = 1;
}

void Snake::move(char dir) {
  if (dir == 't') {
    blocks[]
  } else if (dir == 'b') {

  } else if (dir == 'l') {

  } else if (dir == 'r') {
  }
}

Manager::Manager(Universe *xdd, Snake *xdd2)
    : snakePtr(xdd2), universePtr(xdd){};

void Manager::run() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  universePtr->print();
  int ch;
  while ((ch = getch()) != 27) {
    clear();

    switch (ch) {
    case KEY_UP:

      break;
    case KEY_DOWN:
      printw("You pressed DOWN arrow key");
      break;
    case KEY_LEFT:
      printw("You pressed LEFT arrow key");
      break;
    case KEY_RIGHT:
      printw("You pressed RIGHT arrow key");
      break;
    default:
      printw("Press an arrow key (ESC to exit): ");
      break;
    }
    refresh();
  }
}

void Universe::print() {
  system("clear");
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      std::cout << " ■ ";
    }
    std::cout << std::endl;
  }
}

int main() {
  Snake *snake;
  Universe *uni;
  Manager game(uni, snake);
  game.run();
  return 0;
}
