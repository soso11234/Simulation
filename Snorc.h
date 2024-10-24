#ifndef SNROC_H
#define SNROC_H
#include "MoveBehaviour.h"
#include "Participants.h"
/*
    Name : Snorc
    Purpose : Making snow objects, having incur damage, cause damage, and is safe
    becuase of inherent to Participants

*/

class Snorc : public Participants
{
    public:
        Snorc(int=0, int=0,int=0);
        //~Snorc();
        virtual void incurDamage(Participants*);
        virtual int causeDamage();
        virtual bool isSafe();
    
    private:
        int strength;

};
#endif