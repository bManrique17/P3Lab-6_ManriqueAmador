#include <string>
#include "Escenario.h"
#ifndef TREN_H
#define TREN_H

using namespace std;

class Tren : public Escenario{
    private:
        string posicionActualVagon;        
    public:
        Tren();
        Tren(string);        
        string getPosicionActualVagon();
        void setPosicionActualVagon(string);        
};

#endif
