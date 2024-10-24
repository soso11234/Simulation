#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H
#include "MoveBehaviour.h"
#include "defs.h"

/*
    Name : Paricipants
    Purpose : Making Participants object, it is the parents object of Snorc, Ninja, Hero classes. 
    having move, check safe, causedamage, incurdamage member function, and char, bool, row,col data member
*/

class Participants
{
    public : 
        Participants(char='X',int=0,int=0,MoveBehaviour* = nullptr);// move behavior ?
        virtual ~Participants();
        virtual void incurDamage(Participants*) = 0;
        virtual int causeDamage() = 0;
        virtual bool isSafe() = 0;
        void Move();
        char getAvatar();
        int getRow();
        int getCol();
        bool isDead();
        void setBehaviour(MoveBehaviour*);
    
    protected:
        char avatar;
        bool dead;
        int row;
        int col;
        MoveBehaviour* move;
};
#endif