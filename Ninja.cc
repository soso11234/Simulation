#include "Ninja.h"

Ninja::Ninja(int r, int c) : Participants('N',r,c, new RescuerBehaviour)
{
    strength = 0;
    poisoned = false;
}


void Ninja::incurDamage(Participants* p)
{
    if(poisoned)
    {
        return;
    }
    int damage = p->causeDamage();
    if(damage == RESCUE)
    {
        return;
    }
    else if(damage == 0)
    {
        setBehaviour(new RescuedBehaviour);
    }else
    {
        avatar = 'S';
        setBehaviour(new VillainBehaviour);
        strength = random(3)+6;
        poisoned = true;
    }
}

int Ninja::causeDamage()
{
    if(poisoned)
    {
        return strength;
    }else{
        return RESCUE;
    }
}

bool Ninja::isSafe()
{
    if(poisoned)
    {
        return false;
    }else{
        if(getRow() == 1)
        {
            avatar = ' ';
            return true;
        }else if(getRow() == MAX_ROW-2)
        {
            avatar = ' ';
            return true;
        }else{
            return false;
        }
    }
}