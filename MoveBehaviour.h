#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H
#include "defs.h"
/*
    Name : MoveBehaviour
    purpose : Making MoveBehaviour object, it define each character's behaviour
    the behaviours are escapee, villain, rescuer, rescued
*/

class MoveBehaviour
{
    public:
        virtual ~MoveBehaviour(){};
        virtual void move(int,int,int&,int&) = 0;

};

class EscapeeBehaviour : public MoveBehaviour
{
    public:
        virtual void move(int,int,int&,int&);
};

class VillainBehaviour : public MoveBehaviour
{
    public:
        virtual void move(int,int,int&,int&);
};

class RescuerBehaviour : public MoveBehaviour
{
    public:
        virtual void move(int,int,int&,int&);
};

class RescuedBehaviour : public MoveBehaviour
{
    public:
        virtual void move(int,int,int&,int&);
};
#endif