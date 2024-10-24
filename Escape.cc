#include "Escape.h"

Escape::Escape()
{
    srand( (unsigned)time( NULL ) );
    numSnorc = 0;
    Timmy = new Hero('T',MAX_ROW-1,random(MAX_COL),"Timmy");
    Harold = new Hero('H',MAX_ROW-1,random(MAX_COL),"Harold");
    list+=Timmy;
    list+=Harold;

}
Escape::~Escape()
{
}

void Escape::runEscape()
{
    while(!isOver())
    {
        spawnSnorc();
        spawnNinja();
        moveParticipants();
        printPit();
    }
    printOutcome(Timmy);
    cout << endl;
    printOutcome(Harold);
}

bool Escape::withinBounds(int r,int c)
{
    if(r < MAX_ROW && c < MAX_COL && r > 0 && c > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Escape::isOver()
{
    if(Timmy->isDead() || Timmy->isSafe())
    {
        if(Harold->isDead() || Harold->isSafe())
        {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void Escape::spawnSnorc()
{
    if(numSnorc >= MAX_SNORCS)
    {
        return;
    }else
    {
        int rand = random(11);
        if(rand <= 9)
        {
            int temp_row = MAX_ROW -6;
            int temp_col = random(MAX_COL);
            if(withinBounds(temp_row,temp_col)){
                Snorc* temp = new Snorc(temp_row,temp_col,random(3)+2);
                list += temp;
                numSnorc++;                
            }
        }
    }
}

void Escape::spawnNinja()
{
    int rand = random(3);
    int col = random(MAX_COL);
    if(rand == 0)
    {   
        if(withinBounds(1,col)){
            Ninja* temp = new Ninja(1,col);
            list += temp;               
        }
    }
}

Participants* Escape::checkCollision(Participants* p)
{
    Participants* temp[MAX_ARR];
    int size = 0;
    list.convertToArray(temp,size);
    for(int i = 0; i < size; i ++)
    {
        if(p->getCol() == temp[i]->getCol() && p->getRow() == temp[i]->getRow())
        {
            return temp[i];
        }
    }
    return nullptr;
}

void Escape::moveParticipants()
{
    Participants* temp[MAX_ARR];
    int size = 0;
    list.convertToArray(temp,size);
    for(int i = 0; i < size; i++)
    {
        temp[i]->Move();
        if(checkCollision(temp[i])){
            Participants* temp1 = checkCollision(temp[i]);
            temp1->incurDamage(temp[i]);
            temp[i]->incurDamage(temp1);
        }
    }
}

void Escape::printPit(){
    char map[MAX_ROW][MAX_COL];
    for(int i = 0; i < MAX_ROW; i++){
        for(int a = 0; a < MAX_COL; a++)
        {
            if(i == 0 || i == MAX_ROW-1)
            {
                map[i][a] = '-';
            }
            else if(a == 0 || a == MAX_COL-1)
            {
                map[i][a] = '|';
            }
            else{
                map[i][a] = ' ';
            }
        }
    }
    Participants* arr[MAX_ARR];
    int size = 0;
    list.convertToArray(arr,size);
    for(int i = 0; i < size; i++)
    {
        int row = arr[i]->getRow();
        int col = arr[i]->getCol();
        map[row][col] = arr[i]->getAvatar();
    }
    for(int i = 0; i < MAX_ROW;i++){
        cout << endl;
        for(int a = 0; a < MAX_COL;a++){
            cout << map[i][a];
        }
        if(i == MAX_ROW-3)
        {
            if(Timmy->rescuedFlag())
            {
                cout <<"  "<<Timmy->getName() << " : "<<Timmy->getHealth()<< " RESCUED!";
            }else
            {
                cout <<"  "<<Timmy->getName() << " : "<<Timmy->getHealth();
            }
        }
        else if(i == MAX_ROW-2)
        {
            if(Harold->rescuedFlag())
            {
                cout <<"  "<<Harold->getName() << " : "<<Harold->getHealth()<< " RESCUED!";    
            }
            else
            {
                cout <<"  "<<Harold->getName() << " : "<<Harold->getHealth();
            }
        }
    }
}

void Escape::printOutcome(Hero* h)
{
    if(h->isSafe())
    {
        if(h->rescuedFlag()){
            cout << endl<<h->getName() << " safely rescued ! "<<endl;
        }
        else{
            cout <<endl<< h->getName() << " escaped on his own"<<endl;
        }
    }else if(h->isDead())
    {
        cout <<endl<< h->getName() << " is dead."<<endl;
    }
}