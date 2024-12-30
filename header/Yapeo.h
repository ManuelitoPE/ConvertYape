#ifndef YAPEO_H
#define YAPEO_H
#include "Transaccion.h"

class Yapeo : public Transaccion{
private:
    string emisor;
    string receptor;
    double cantidad;
public:
    Yapeo();
    Yapeo(const Yapeo& orig);
    ~Yapeo();

    Yapeo& operator=(const Yapeo& orig);

    string getEmisor();
    string getReceptor();
    double getCantidad();
    void setEmisor(const string emisor);
    void setReceptor(const string receptor);
    void setCantidad(const double cantidad);
    void leer(ifstream& arch);
    void imprimir(ofstream& report);
};


#endif