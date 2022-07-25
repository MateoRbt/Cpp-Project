#include <iostream>
#include "Diamond.h"
#include <ncurses.h>
#include <vector>
#include <cstring>
#include <string>



void Diamond::initloc(std::vector<std::string> &m)
{
    int strsize = m[0].length() - 1;   //μέγεθος χάρτη 
    int vecsize = m.size();
    srand(time(0));
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    while (true)
    {
        int y = std::rand() % vecsize; //τυχαίες τιμές γαι την τοποθέτηση του αντικειμένου πάνω στον χάρτη
        int x = std::rand() % strsize;
        if (m[y].at(x) != '*' && m[y].at(x) != 'M' && m[y].at(x) != 'L') //αν δεν υπάρχει κάποιο απο τα 3 αντικείμενα στην θέση που διάλεξες βάλε το αντικείμενο 
        {
            setPositionX(x);
            setPositionY(y);
            setName(getName());
            m[y].at(x) = getName();
            move(y, x);

            attron(COLOR_PAIR(3));
            addch(name);
            attroff(COLOR_PAIR(3));

            break;
        }
    }
}


//Η λογική εδώ είναι ίδια με την αρχικοποιήση θέσης αλλα με την διαφορά οτι αφαίρει απο την προηγούμενη θέση το διαμάντι
void Diamond::changeLoc(std::vector<std::string> &m)
{
    int strsize = m[0].length() - 1;
    int vecsize = m.size();
    srand(time(0));
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    int y= getPositionY();
    int x= getPositionX();
    move(y,x);
    addch('.');
    while (true)
    {
        y = std::rand() % vecsize;
        x = std::rand() % strsize;
        if (m[y].at(x) != '*' && m[y].at(x) != 'M' && m[y].at(x) != 'L')
        {
            setPositionX(x);
            setPositionY(y);
            setName(getName());
            m[y].at(x) = getName();
            move(y, x);

            attron(COLOR_PAIR(3));
            addch(name);
            attroff(COLOR_PAIR(3));

            break;
        }
    }
}



Diamond::Diamond()
{
}

Diamond::~Diamond()
{
}
