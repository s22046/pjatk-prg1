
#include "player.h"
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <string>
#include <vector>

int main() {

  // NCURSES START
  initscr();
  noecho();


  // get screen size
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  yMax = yMax -1;
  // Window for input
  WINDOW *playwin = newwin(20, 50, 10, 10);
  box(playwin, 0, 0);
  refresh();
  wrefresh(playwin);

  move(1,10);
  printw("#===============================================#\n");
    printw("####### ####### ####### ######     ###     #####\n");
    printw("   #    #          #    #     #     #      #     \n");
    printw("   #    #          #    #     #     #      #     \n");
    printw("   #    #######    #    #####       #      ##### \n");
    printw("   #    #          #    #  #        #          # \n");
    printw("   #    #          #    #   #       #          # \n");
    printw("   #    #######    #    #    #     ###     ##### \n");
    printw("#===============================================#\n");

  getch();
  getch();
  halfdelay(3);

  MrChar *p = new MrChar(playwin, 1, 10,'P',0);
  MrChar *target = new MrChar(playwin,10,10,'T',1);
  MrChar *car = new MrChar(playwin,1,5,'C',2);
 
  std::vector<MrChar*> cars;
  cars.push_back(car);
  for(int i=0;i<10;i++)
  {
    car = new MrChar(playwin,i%4,i+8,'C',2);
    cars.push_back(car);
  }

  p->display();
  target->display();
  wrefresh(playwin);


  while (p->getmv() != 'x') {
    p->display();
    for(auto car:cars)
    {
      car->iscolliding(p);
      car->mvdown();
      car->display();
    }
    wrefresh(playwin);
    if (target->iscolliding(p))
    {
      p->charakter = '!';
    }
    if (car->iscolliding(p))
    {
      p->charakter = '?';

    }


    

  }




  // waiting before exit
  getch();
  endwin();
}