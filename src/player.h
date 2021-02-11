#ifndef _Player_H_
#define _Player_H_
#include <ncurses.h>
#include <string>



class MrChar
{
  

public:
    MrChar(WINDOW * win, int y, int x, char c, int whoami);

    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();
    void printLocyx();
    char charakter;
    int xLoc, yLoc, xMax, yMax;
    WINDOW * curwin;
    int personality = -1;
    bool iscolliding(MrChar*);

};

MrChar::MrChar(WINDOW * Win, int y, int x, char c, int whoami)
{
    curwin = Win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin,true);
    charakter = c;
    personality = whoami;

}

bool MrChar::iscolliding(MrChar *other)
{
  
return other->xLoc == xLoc && other->yLoc == yLoc;
}


void MrChar::mvup()
{
    mvwaddch(curwin,yLoc,xLoc,' ');
    yLoc--;
    if (yLoc < 1)
    { 
        yLoc = 1;
    }
}
void MrChar::mvdown()
{
    mvwaddch(curwin,yLoc,xLoc,' ');
    yLoc++;
    if (yLoc > yMax-2)
    {   
        if (personality == 2)
        {
            yLoc = 0;
        } else
        {
            yLoc = yMax-2;
        }
        
    } 


}
void MrChar::mvleft()
{   
    mvwaddch(curwin,yLoc,xLoc,' ');
    xLoc--;
    if (xLoc < 1)
   {    xLoc = 1;}
}
void MrChar::mvright()
{
    mvwaddch(curwin,yLoc,xLoc,' ');
    xLoc++;
    if(xLoc > xMax-2)
   { xLoc = xMax-2;}
}
int MrChar::getmv()
{
    if (personality != 0) return 0;

    int choice = wgetch(curwin);
    switch (choice)
    {
    case KEY_UP:
        mvup();
        break;
    case KEY_DOWN:
        mvdown();
        break;
    case KEY_RIGHT:
        mvright();
        break;
    case KEY_LEFT:
        mvleft();
        break;
        default:
        break;
    }
    return choice;
}

void MrChar::display()
{
    mvwaddch(curwin,yLoc, xLoc,charakter);
}

//void MrChar::printLocyx()
//{
//    if (KEY_ENTER)
 //   {
 //   mvwprintw()
 //   mvwprintw(
  //  wrefresh(curwin);
 //   }
//}


#endif

