#include <iostream>
#include "Npc.h"
#include <ncurses.h>

//Εξυπνη κίνηση
void Npc::gmeleMoves(int diamondX, int diamondY, std::vector<std::string> &m)
{

    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    move(positionY, positionX);
    //επαναληπτική δομή που ελέγχη και εκτελεί την κίνηση του Λουκά
    while (true)
    {

        if (diamondX == positionX)
        {
            positionY++;
            if (m[positionY].at(positionX) != '*')
            {
                addch('.');
                move(positionY, positionX);
                attron(COLOR_PAIR(2));
                addch(name);
                attroff(COLOR_PAIR(2));
                break;
            }
            else
            {
                positionY--;
            }
        }
        else
        {
            positionX++;
            if (m[positionY].at(positionX) != '*')
            {
                addch('.');
                move(positionY, positionX);
                attron(COLOR_PAIR(2));
                addch(name);
                attroff(COLOR_PAIR(2));
                break;
            }
            else
            {
                positionX--;
            }
        }

        if (diamondY == positionY)
        {
            positionX++;
            if (m[positionY].at(positionX) != '*')
            {
                addch('.');
                move(positionY, positionX);
                attron(COLOR_PAIR(2));
                addch(name);
                attroff(COLOR_PAIR(2));
                break;
            }
            else
            {
                positionX--;
            }
        }
        else
        {
             positionY++;
            if (m[positionY].at(positionX) != '*')
            {
                addch('.');
                move(positionY, positionX);
                attron(COLOR_PAIR(2));
                addch(name);
                attroff(COLOR_PAIR(2));
                break;
            }
            else
            {
                positionY--;
            }
        }
    }
}
//αρχικοποιήση θέσης Λουκά

void Npc::initloc(std::vector<std::string> &m)
{
    //διαστάσης χάρτη
    mflag = 0;
    int strsize = m[0].length() - 1;
    int vecsize = m.size();
    srand(time(0));
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    while (true)
    {
        int y = std::rand() % vecsize;
        int x = std::rand() % strsize;
        if (m[y].at(x) != '*' && m[y].at(x) != 'M' && m[y].at(x) != 'L') // αν δεν υπάρχει κάποιο απο τα παρακάτω αντικέιμενα στην θέση που διάλεξες τοποθέτησε τον Λουκά
        {
            setPositionX(x);
            setPositionY(y);
            setName(getName());
            m[y].at(x) = getName();
            move(y, x);

            attron(COLOR_PAIR(2));
            addch(name);
            attroff(COLOR_PAIR(2));

            break;
        }
    }
}

Npc::Npc()
{
}

Npc::~Npc()
{
}
