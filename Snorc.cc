#include "Snorc.h"

Snorc::Snorc(int r, int c, int str): Participants('s',r,c,new VillainBehaviour)
{
    strength = str;
}


void Snorc::incurDamage(Participants* p)
{

}

int Snorc::causeDamage()
{
    return strength;
}

bool Snorc::isSafe()
{
    return false;
}