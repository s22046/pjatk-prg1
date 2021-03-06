
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
  while(1){
  WINDOW *menu = newwin(10, 20, 20, 20);
  box(menu, 0, 0);
  refresh();
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
  refresh();


  keypad(menu, true);
  std::string menuchoices[2]{"Start Game", "Quit"};
  int choice;
  int highlight = 0;

  while (1) {
    for (int i = 0; i < 2; i++) {
      if (i == highlight)
        wattron(menu, A_BOLD);
      mvwprintw(menu, i + 1, 1, menuchoices[i].c_str());
      wattroff(menu, A_BOLD);
    }
    choice = wgetch(menu);

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
  //if (highlight == 1)
  //  {
  //  exit();
  //  } 
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
      nocbreak();
      cbreak();
      getch();
      clear();
      break;
    }
    if (target->iscolliding(p)) {
      wclear(msgbox);
      box(msgbox, 0, 0);
      mvwprintw(msgbox, 2, 2, "Winner! You got to the other side!");
      wrefresh(msgbox);
      mvwprintw(playwin, 10, 40, "YEAH!");
      nocbreak();
      cbreak();
      getch();
      clear();
      break;
    }
  }
  }
  // waiting before exit
  getch();
  endwin();
}