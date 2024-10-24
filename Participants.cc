#include "Participants.h"

Participants::Participants(char av,int r, int c, MoveBehaviour* m) : move(m)
{
    avatar = av;
    row = r;
    col = c;
    if(avatar != '+')
    {
        dead = false;
    }else{
        dead = true;
    }
    
}

Participants::~Participants()
{//?
    delete move;
}

char Participants::getAvatar()
{
    return avatar;
}

int Participants::getRow()
{
    return row;
}

int Participants::getCol()
{
    return col;
}

bool Participants::isDead()
{
    if(dead){
        avatar = '+';
    }
    return dead;
}

void Participants::Move()
{//??
    int nrow = 0;
    int ncol = 0;
    if(dead)
    {
        return;
    }
    move->move(getRow(),getCol(),nrow,ncol);
    if(nrow < MAX_ROW-1 && nrow > 0){
        row = nrow;
    }else{
        row = getRow();
    }
    if(ncol < MAX_COL-1 && ncol > 0){
        col = ncol;
    }else{
        col = getCol();
    }
}

void Participants::setBehaviour(MoveBehaviour* m)
{
    
    if(move != nullptr)
    {
        delete move;
    }
    move = m;
}
