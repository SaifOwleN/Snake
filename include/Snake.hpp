#ifndef _Snake_H
#define _Snake_H

#include <ncurses.h>
#include <utility>
#include <vector>

class Snake {
public:
  void eat();
  void move(char);
  void moveLine();
  void lose();
  void spawn();
  void point();
  void print(WINDOW *&);
  std::pair<int, int> getPosition(int);
  std::vector<std::vector<int>> blocks;

private:
  std::vector<std::pair<int, int>> position;
  std::pair<int, int> scorePosition;
};
class Manager {
public:
  void initialize();
  void run();
  Manager(Snake);

private:
  Snake snakePtr;
};

#endif
