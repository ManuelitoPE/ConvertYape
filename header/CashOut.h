#ifndef CASH_OUT
#define CASH_OUT
#include "Transaccion.h"
class CashOut : public Transaccion{
private:
    string emisor = "SERGIO MANUEL SUTTA PINEDO";
    double cantidad;
public:
    CashOut(/* args */);
    CashOut(const CashOut& orig);
    ~CashOut();

    CashOut& operator=(const CashOut& orig);

    string getEmisor();
    double getCantidad();
    void setCantiad(const double cantidad);
    void leer(ifstream& arch);
    void imprimir(ofstream& report);
};


#endif