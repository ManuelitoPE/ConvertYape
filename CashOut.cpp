#include "header/CashOut.h"

//Constructores y Destructores
CashOut::CashOut(){

}

CashOut::CashOut(const CashOut& orig):Transaccion(orig){
    *this = orig;
}

CashOut::~CashOut(){
}

//Sobrecargar =
CashOut& CashOut::operator=(const CashOut& orig){
    Transaccion::operator=(orig);
    cantidad = orig.cantidad;
    return *this;
}

//Setters y getters
string CashOut::getEmisor(){
    return emisor;
}

double CashOut::getCantidad(){
    return cantidad;
}

void CashOut::setCantiad(const double cantidad){
    this->cantidad = cantidad;
}

void CashOut::leer(ifstream& arch){
    string buffer;
    Transaccion::leer(arch);
    getline(arch,buffer,';');
    getline(arch,buffer,';');
    getline(arch,buffer,';');
    this->setTipo(buffer);
    while(arch.get()!=' ');
    arch>>cantidad;
    arch.ignore();
}

void CashOut::imprimir(ofstream& report){
    Transaccion::imprimir(report);
    report<<"'"<<emisor<<"','','"<<this->getTipo()
          <<"',"<<cantidad<<");"<<endl;
}
