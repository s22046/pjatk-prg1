
#include "Project.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <vector>

int main() {

  // NCURSES START
  initscr();
  noecho();
  curs_set(0);

  // initial menu
  WINDOW *win = newwin(10, 20, 5, 5);
  box(win, 0, 0);
  refresh();

  keypad(win, true);
  std::string menuchoices[2]{"Start Game", "Quit"};
  int choice;
  int highlight = 0;

  while (1) {
    for (int i = 0; i < 2; i++) {
      if (i == highlight)
        wattron(win, A_BOLD);
      mvwprintw(win, i + 1, 1, menuchoices[i].c_str());
      wattroff(win, A_BOLD);
    }
    choice = wgetch(win);

    switch (choice) {
    case KEY_UP:
      highlight--;
      if (highlight == -1) {
        highlight = 0;
      }
      break;
    case KEY_DOWN:
      highlight++;
      if (highlight == 2) {
        highlight = 1;
      }
      break;
    default:
      break;
    }
    if (choice == 10) {
      break;
    }
  }
  clear();

  // get screen size
  int yMax, xMax;
  int yfield = 20;
  int xfield = 50;
  int difficultylvl = 3;
  getmaxyx(stdscr, yMax, xMax);
  yMax = yMax;
  // Window for input
  WINDOW *playwin = newwin(yfield, xfield, 20, 10);
  box(playwin, 0, 0);
  WINDOW *msgbox = newwin(5, xfield, 14, 10);
  box(msgbox, 0, 0);
  mvwprintw(msgbox, 2, 2, "Cross the street and get the T!");
  refresh();
  wrefresh(playwin);
  wrefresh(msgbox);

  printw(
      "#================================================================#\n");
  printw(
      "           ### ### ### ### ### ###                                \n");
  printw(
      "           #    #  # # #   #    #                                 \n");
  printw(
      "           ###  #  ### ### ###  #                                 \n");
  printw(
      "             #  #  ##  #   #    #                                 \n");
  printw(
      "           ###  #  # # ### ###  #                                 \n");
  printw(
      "                         ### ### ### ### ### # #  # ####          \n");
  printw(
      "                         #   # # # # #   #   # ## # #             \n");
  printw(
      "                         #   ### # # ### ### # # ## # ##          \n");
  printw(
      "                         #   ##  # #   #   # # #  # #  #          \n");
  printw(
      "                         ### # # ### ### ### # #  # ####          \n");
  printw(
      "#================================================================#\n");

  getch();
  getch();
  halfdelay(difficultylvl);

  MrChar *p = new MrChar(playwin, yfield / 2, 3, 'P', 0);
  MrChar *target = new MrChar(playwin, 10, 43, 'T', 1);
  MrChar *car = new MrChar(playwin, 1, 10, 'O', 2);

  std::vector<MrChar *> cars;
  cars.push_back(car);
  for (int i = 0; i < 25; i++) {
    car = new MrChar(playwin, rand() % 20, i + 10, '0', 2);
    cars.push_back(car);
  }

  // p->display();
  target->display();
  wrefresh(playwin);

  while (p->getmv() != 'x') {
    p->display();
    for (auto car : cars) {
      car->iscolliding(p);
      car->mvdown();
      car->display();
    }
    wrefresh(playwin);
    if (car->iscolliding(p)) {
      wclear(msgbox);
      box(msgbox, 0, 0);
      mvwprintw(msgbox, 2, 2, "Collision! Game over!");
      wrefresh(msgbox);
      mvwprintw(playwin, 10, 40, "Oh NO!");
    }
    if (target->iscolliding(p)) {
      wclear(msgbox);
      box(msgbox, 0, 0);
      mvwprintw(msgbox, 2, 2, "Winner! You got to the other side!");
      wrefresh(msgbox);
      mvwprintw(playwin, 10, 40, "YEAH!");
    }
  }

  // waiting before exit
  getch();
  endwin();
}