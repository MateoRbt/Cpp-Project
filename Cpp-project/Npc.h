#ifndef NPC_H
#define NPC_H
#include <vector>
#include <cstring>
#include <string>
#include "pawn.h"

class Npc : public Pawn
{
private:
    int mflag;

public:
    Npc();
    ~Npc();
    void gmeleMoves(int, int, std::vector<std::string> &); //Κίνηση Λουκά
    void initloc(std::vector<std::string> &);              //αρχικοποιήση Λουκά
};

#endif
