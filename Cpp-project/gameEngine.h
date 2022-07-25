#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "pawn.h"
#include "Npc.h"
#include "Diamond.h"

class gameEngine
{
    private:
        Pawn potter;
        Npc malfoi;
        Diamond diamond;
        std::vector<std::string>map;
        std::ifstream file;
        std::string str;

    public :
        gameEngine(int argc,char **argv);
        int condition( Pawn  & , Npc &,  Diamond  &);

};
#endif