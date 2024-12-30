#include "header/Transaccion.h"
//Constructores y Destructores
Transaccion::Transaccion(){
    fecha = {};
    hora  = {};
    tipo  = {};
}
Transaccion::Transaccion(const Transaccion& orig){
    *this = orig;
}

Transaccion::~Transaccion(){
}

//Sobrecarga operator =
Transaccion& Transaccion::operator=(const Transaccion& orig){
    fecha = orig.fecha;
    hora  = orig.hora;
    tipo  = orig.tipo;
    return *this;
}

//Setters y getters
string Transaccion::getFecha(){
    return fecha;
}

string Transaccion::getHora(){
    return hora;
}

string Transaccion::getTipo(){
    return tipo;
}

void Transaccion::setFecha(const string fecha){
    this->fecha = fecha;
}

void Transaccion::setHora(const string hora){
    this->hora = hora;
}

void Transaccion::setTipo(const string tipo){
    this->tipo = tipo;
}

void Transaccion::leer(ifstream& arch){
    getline(arch,fecha,';');
    getline(arch,hora,';');
}

void Transaccion::imprimir(ofstream& report){
    report<<"VALUES(TO_DATE('"<<fecha<<" "<<hora<<"','DD/MM/YYYY HH24:MI:SS'),";
}