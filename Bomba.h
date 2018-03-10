#include "Item.h"

#ifndef BOMBA_H
#define BOMBA_H


class Bomba : public Item{
    private:
        int contadorExplosion;
    public:
        Bomba(int,int);
        int getContadorExplosion();
        void setContadorExplosion(int);
};

#endif