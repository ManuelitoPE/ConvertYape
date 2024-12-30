#include "header/Movimientos.h"

Movimientos::Movimientos(/* args */){
    movimientos = {};
}

Movimientos::~Movimientos(){
}

void Movimientos::cargarMovimientos(){
    ifstream arch("docs/movimientos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR en abrir movimientos"<<endl;
        exit(1);
    }
    //Datos 
    Transaccion* transaccion;
    char tipo,c;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch>>c;
        if(tipo == 'Y')transaccion = new Yapeo;
        else transaccion = new CashOut;
        transaccion->leer(arch);
        movimientos.push_back(transaccion);
    }

}
void Movimientos::imprimirInserts(){
    ofstream report("scripts/DML.sql",ios::out);
    if(not report.is_open()){
        cout<<"ERROR en abrir en el reporte"<<endl;
        exit(1);
    }
    // INSERT INTO operaciones (ID_OPERACION, FECHA_OPERACION, EMISOR, RECEPTOR, TIPO_OPERACION, MONTO)
    // VALUES (123456789012, TO_DATE('2024-12-29', 'YYYY-MM-DD'), 'Empresa A', 'Cliente B', 'Transferencia', 1000.00);
    // for(auto it = movimientos.begin(); it != movimientos.end(); it++){
    //     report<<"INSERT INTO MOVIMIENTOS (FECHA_OPERACION, EMISOR, RECEPTOR, TIPO_OPERACION, MONTO)"<<endl;
    //     *it->imprimir(report);
    // }
    for(Transaccion* tr : movimientos){
        report<<"INSERT INTO MOVIMIENTOS (FECHA_OPERACION, EMISOR, RECEPTOR, TIPO_OPERACION, MONTO)"<<endl;
        tr->imprimir(report);
    }
}   