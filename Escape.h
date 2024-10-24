#ifndef ESCAPE_H
#define ESCAPE_H
#include <string>
#include <iostream>
#include <iomanip>
//#include "Participants.h"
#include "Hero.h"
#include "Snorc.h"
#include "List.h"
#include "Ninja.h"
using namespace std;
/*
    Name : Escape
    Purpose : Making escape object, it is a kind of UI object, which communicate
    to users.

*/

class Escape
{
    public:
        Escape();
        ~Escape();
        void runEscape();
        bool withinBounds(int,int);
    
    private:
        void spawnSnorc();
        void spawnNinja();
        void moveParticipants();
        Participants* checkCollision(Participants*);
        bool isOver();
        void printPit();
        void printOutcome(Hero*);
        int numSnorc;
        Participants* participants;
        Hero* Timmy;
        Hero* Harold;
        List<Participants*> list;
};
#endif