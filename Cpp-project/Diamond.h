#ifndef DIAMOND_H
#define DIAMOND_H
#include <vector>
#include <cstring>
#include <string>
#include "pawn.h"

class Diamond : public Pawn
{
   
    public:
    Diamond();
    ~Diamond();
    void initloc (std::vector<std::string> &); //μέθοδος που αρχικοποιήει την θέση του διαμαντιού
    void changeLoc (std::vector<std::string> &); //μέθοδος ποθ αλλάζει την θέση του διαμαντιού 

};

#endif