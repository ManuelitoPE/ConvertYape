#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include <vector>
#include "Transaccion.h"
#include "Yapeo.h"
#include "CashOut.h"
class Movimientos{
private:
    vector<Transaccion*> movimientos;
public:
    Movimientos(/* args */);
    ~Movimientos();
    
    void cargarMovimientos();
    void imprimirInserts();
};



#endif