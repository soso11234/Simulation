#include "MoveBehaviour.h"
//how to return row and col ????
//MoveBehaviour::~MoveBehaviour(){}
void EscapeeBehaviour::move(int row,int col,int& nrow, int&ncol)
{
    //current row one or two up or one or two down stay same
    //current col one left or right or stay same
    int rand = random(5);
    if(rand == 0)
    {
        nrow = row-1;
    }else if(rand == 1)
    {
        nrow = row-2;
    }else if(rand == 2)
    {
        nrow = row +1;
    }else if(rand == 3)
    {
        nrow = row +2;
    }else
    {
        nrow = row;
    }
    rand = random(3);
    if(rand == 0)
    {
        ncol = col +1;
    }else if(rand == 1)
    {
        ncol = col -1;
    }else
    {
        ncol = col;
    }
}

void VillainBehaviour::move(int row, int col,int& nrow, int&ncol)
{
    //row one up or down
    //one left or right or stay
    int rand  = random(2);
    if(rand == 0)
    {
        nrow = row +1;
    }else{
        nrow = row -1;
    }
    rand = random(3);
    if(rand == 0)
    {
        ncol = col -1;
    }else if(rand ==1)
    {
        ncol = col +1;
    }else{
        ncol = col;
    }
    if(nrow <= MAX_ROW-8)
    {
        nrow = row;
    }
}

void RescuerBehaviour::move(int row, int col,int& nrow, int&ncol)
{
    //ninja, one down, same col
    nrow = row+1;
}

void RescuedBehaviour::move(int row, int col,int& nrow, int&ncol)
{
    nrow = row-1;
}