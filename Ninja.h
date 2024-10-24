#ifndef NINJA_H
#define NINJA_H
#include "Participants.h"
/*
    Name : Ninja
    Purpose : making ninja object, it has rescuerbehaviour, and cause damage(to check hero is or not, and then snow, poison), give
    damage and ect. 
*/

class Ninja : public Participants
{
    public :
        Ninja(int=0,int=0);
        //~Ninja();
        virtual void incurDamage(Participants*);
        virtual int causeDamage();
        virtual bool isSafe();
    
    private:
        int strength;
        bool poisoned;

};
#endif