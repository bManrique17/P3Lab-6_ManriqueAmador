#include <string>
#include "Escenario.h"
#ifndef TREN_H
#define TREN_H

using namespace std;

class Tren : public Escenario{
    private:
        int vagonX;    
        int vagonY;
    public:
        Tren();

        Tren(string);
            
        int getVagonX();    

        int getVagonY();

        void setVagonX(int);

        void setVagonY(int);
};

#endif
