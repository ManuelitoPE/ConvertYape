#include "header/Yapeo.h"
//Constructores y destructores
Yapeo::Yapeo(){
    emisor   = {};
    receptor = {};
    cantidad = {};
}

Yapeo::Yapeo(const Yapeo& orig):Transaccion(orig){
    *this = orig;
}

Yapeo::~Yapeo(){
}

//Sobrecargar =
Yapeo& Yapeo::operator=(const Yapeo& orig){
    Transaccion::operator=(orig);
    emisor   = orig.emisor;
    receptor = orig.receptor;
    cantidad = orig.cantidad;
    return *this;
}

//Setters y getters
string Yapeo::getEmisor(){
    return emisor;
}

string Yapeo::getReceptor(){
    return receptor;
}

double Yapeo::getCantidad(){
    return cantidad;
}

void Yapeo::setEmisor(const string emisor){
    this->emisor = emisor;
}

void Yapeo::setReceptor(const string receptor){
    this->receptor = receptor;
}

void Yapeo::setCantidad(const double cantidad){
    this->cantidad = cantidad;
}

void Yapeo::leer(ifstream& arch){
    string tipo;
    Transaccion::leer(arch);
    getline(arch,emisor,';');
    getline(arch,receptor,';');
    getline(arch,tipo,';');
    this->setTipo(tipo);
    while(arch.get()!=' ');
    arch>>cantidad;
    arch.ignore();
}

void Yapeo::imprimir(ofstream& report){
    Transaccion::imprimir(report);
    report<<"'"<<emisor<<"','"<<receptor<<"','"<<this->getTipo()
          <<"',"<<cantidad<<");"<<endl;
}