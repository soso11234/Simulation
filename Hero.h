#ifndef HERO_H
#define HERO_H
#include <string>
#include "Participants.h"
#include "defs.h"
/*
    Name : Hero
    Purpose : Making Hero object for Timmy and Harold, having escapee move but when they colides with Ninja, the moveBehaviour changes to Rescuee 
    
*/


class Hero : public Participants
{
    public:
        Hero(char='X',int=0,int=0,string="NAME");
        //~Hero();
        virtual void incurDamage(Participants*);
        virtual int causeDamage();
        virtual bool isSafe();
        string getName();
        int getHealth();
        bool rescuedFlag();

    private:
        string name;
        int health;
        bool rescued;
};
#endif