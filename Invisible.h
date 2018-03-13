#ifndef INVISIBLE_H
#define INVISIBLE_H

#include <string>
#include "Escenario.h"

using namespace std;

class Invisible : public Escenario{
    private:
        int numeroVidas;
        int tipoBomba;
    public:
        Invisible();
        Invisible (string, int , int);
        void setNumeroVidas(int);
        void setTipoBomba(int);
        int getNumeroVidas();
        int getTipoBomba();    
};

#endif

