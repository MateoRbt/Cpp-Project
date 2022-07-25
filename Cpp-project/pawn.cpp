#include <iostream>
#include "pawn.h"
#include <ncurses.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <string.h>

//Setters Getters που επιτρέπουν την αλληλεπίδραση με τα attributes του πιονιού 
int Pawn::getPositionX()
{
    return positionX;
}

int Pawn::getPositionY()
{
    return positionY;
}

char Pawn::getName()
{
    return name;
}

void Pawn::setPositionX(int x)
{
    positionX = x;
}

void Pawn::setPositionY(int y)
{
    positionY = y;
}

void Pawn::setName(char n)
{
    name = n;
}

void Pawn::DoMove(int num, std::vector<std::string> &m)  //Μέθοδος κίνησης 
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    int y = positionY;
    int x = positionX;
    move(y, x);
    switch (num)
    {
    case KEY_UP:
        positionY--;
        break;
    case KEY_DOWN:
        positionY++;
        break;
    case KEY_LEFT:
        positionX--;
        break;
    case KEY_RIGHT:
        positionX++;
        break;
    case ' ':
        break;
    }
    if (m[getPositionY()].at(getPositionX()) == '*') // αν εκεί που θές να πας υπάρχει τοίχος πήγαινε στην προηγούμενη θέση που ήσουν 
    {
        setPositionY(y);
        setPositionX(x);
    }
    else
    {
        addch('.');
        move(getPositionY(), getPositionX());
        attron(COLOR_PAIR(1));
        addch(name);
        attroff(COLOR_PAIR(1));
    }
    
}

//αρχικοποιήση θέσης 
void Pawn::initloc(std::vector<std::string> &m)
{
    int strsize = m[0].length() - 1;
    int vecsize = m.size();
    srand(time(0));
    init_pair(1, COLOR_RED, COLOR_BLACK);

    while (true)
    {
        int y = std::rand() % vecsize;
        int x = std::rand() % strsize;
        if (m[y].at(x) != '*' && m[y].at(x) != 'M' && m[y].at(x) != 'L')
        {
            setPositionX(x);
            setPositionY(y);
            setName(getName());
            m[y].at(x) = getName();
            move(y, x);
            attron(COLOR_PAIR(1));
            addch(name);
            attroff(COLOR_PAIR(1));

            break;
        }
    }
}

Pawn::Pawn()
{

}

Pawn::~Pawn()
{
}
