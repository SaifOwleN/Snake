#include "../include/Snake.hpp"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <random>
#include <utility>
#include <vector>
const short rows = 20;
const short cols = 20;

int getRandomNumber() {
  std::mt19937 gen(std::random_device{}());

  std::uniform_int_distribution<int> distribution(0, 19);

  return distribution(gen);
}

std::pair<int, int> Snake::getPosition(int i) { return position[i]; }

void Snake::print(WINDOW *&window) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (blocks[i][j] == 1) {
        mvwprintw(window, i + 1, j + 1, "A");
      } else if (blocks[i][j] == 2) {
        mvwprintw(window, i + 1, j + 1, "O");

      } else {
        mvwprintw(window, i + 1, j + 1, " ");
      }
    }
  }
  mvwprintw(window, 21, 1, "\n");
}

void Snake::point() {
  scorePosition.first = getRandomNumber();
  scorePosition.second = getRandomNumber();
  blocks[scorePosition.first][scorePosition.second] = 2;
}

void Snake::spawn() {
  blocks.resize(20, std::vector<int>(20, 0));
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      blocks[i][j] = 0;
    }
  }
  std::cout << (int)(rand() / (RAND_MAX + 1.0));
  int row = getRandomNumber();
  int col = getRandomNumber();
  blocks[row][col] = 1;
  position.push_back(std::make_pair(row, col));
  point();
}

void Snake::moveLine() {
  if (position.size() > 1) {

    std::pair<int, int> temp = position[position.size() - 1];
    for (int i = position.size() - 1; i > 0; i--) {
      position[i] = position[i - 1];
      blocks[position[i].first][position[i].second] = 1;
    }
    blocks[temp.first][temp.second] = 0;
  }
}

void Snake::move(char dir) {
  if (dir == 't') {
    if (position[0].first - 1 >= 0) {
      blocks[position[0].first - 1][position[0].second] = 1;
      if (position[0] == scorePosition) {
        position.push_back(scorePosition);
        point();
      } else {
        blocks[position[0].first][position[0].second] = 0;
      }
      position[0].first--;
    } else {
    }
  } else if (dir == 'b') {
    if (position[0].first + 1 < 20) {
      blocks[position[0].first + 1][position[0].second] = 1;
      if (position[0] == scorePosition) {
        position.push_back(scorePosition);
        point();
      } else {
        blocks[position[0].first][position[0].second] = 0;
      }
      position[0].first++;

    } else {
    }
  } else if (dir == 'l') {
    if (position[0].second - 1 >= 0) {
      blocks[position[0].first][position[0].second - 1] = 1;
      if (position[0] == scorePosition) {
        position.push_back(scorePosition);
        point();
      } else {
        blocks[position[0].first][position[0].second] = 0;
      }
      position[0].second--;
    } else {
    }
  } else if (dir == 'r') {
    if (position[0].second + 1 < 20) {
      blocks[position[0].first][position[0].second + 1] = 1;
      if (position[0] == scorePosition) {
        position.push_back(scorePosition);
        point();
      } else {
        blocks[position[0].first][position[0].second] = 0;
      }
      position[0].second++;
    } else {
    }
  }
  moveLine();
}

void Manager::initialize() { snakePtr.spawn(); }

Manager::Manager(Snake xdd2) : snakePtr(xdd2){};

void Manager::run() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  WINDOW *window = newwin(23, 23, 0, 0);
  refresh();
  box(window, 0, 0);
  wrefresh(window);
  initialize();
  int ch;
  while ((ch = getch()) != 27) {
    switch (ch) {
    case KEY_UP:
      snakePtr.move('t');
      break;
    case KEY_DOWN:
      snakePtr.move('b');
      break;
    case KEY_LEFT:
      snakePtr.move('l');
      break;
    case KEY_RIGHT:
      snakePtr.move('r');
      break;
    default:
      break;
    }
    snakePtr.print(window);
    wrefresh(window);
  }
}
