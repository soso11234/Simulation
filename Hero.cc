#include "Hero.h"

Hero::Hero(char av, int row, int col, string n) : Participants(av,row,col,new EscapeeBehaviour)
{
    name = n;
    health = MAX_HEALTH;
    rescued = false;
}

void Hero::incurDamage(Participants* p)
{
    int damage = p->causeDamage();
    if(damage == RESCUE)
    {
        if(!isDead()){
            rescued = true;
            setBehaviour(new RescuedBehaviour);
        }
    }else{
        health = health - damage;
    }
    if(health <= 0)
    {
        health = 0;
        avatar = '+';
        dead = true;
    }
}

int Hero::causeDamage()
{
    return 0;
}

bool Hero::isSafe()
{
    if(getRow() == 1)
    {
        avatar = ' ';
        return true;
    }else{
        return false;
    }
}

string Hero::getName()
{
    return name;
}

bool Hero::rescuedFlag()
{
    return rescued;
}

int Hero::getHealth()
{
    return health;
}
