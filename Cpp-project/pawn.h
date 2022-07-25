#ifndef PAWN_H
#define PAWN_H
#include <vector>
#include <cstring>
#include <string>

class Pawn
{
    protected :  
    char name ;
    int positionX;
    int positionY;

    public:
    int getPositionX();
    int getPositionY();
    char getName();

    void setPositionX(int );
    void setPositionY(int );
    void setName(char );

    Pawn();
    virtual ~Pawn();

   void DoMove(int,std::vector<std::string> & );
   virtual void initloc (std::vector<std::string> &);

};

#endif