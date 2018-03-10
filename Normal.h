
#include <string>
#include "Bomba.h"
#include "Item.h"

#ifndef NORMAL_H
#define NORMAL_H


class Normal : public Bomba{
    public:
        Normal (int,int);
        int getAlcance();
    private:
        int alcance;
};

#endif
