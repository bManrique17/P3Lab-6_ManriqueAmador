
#include <string>
#include "Bomba.h"

#ifndef ESPINA_H
#define ESPINA_H

class Espina : public Bomba{
    public:
        Espina (int,int);
        Espina (int,int,int);
        void setBombasPuestas(int);
        int getBombasPuestas();
    private:
        int bombasPuestas;
};

#endif
