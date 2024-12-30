#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


class Transaccion{
private:
    string fecha;
    string hora;
    string tipo;
public:
    
    Transaccion();
    Transaccion(const Transaccion& orig);
    ~Transaccion();

    Transaccion& operator=(const Transaccion& orig);
    
    string getFecha();
    string getHora();
    string getTipo();
    void setFecha(const string fecha);
    void setHora(const string hora);
    void setTipo(const string tipo);

    virtual void leer(ifstream& arch);
    virtual void imprimir(ofstream& report); 
};


#endif