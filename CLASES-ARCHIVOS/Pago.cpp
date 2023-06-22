#include "Pago.h"
#include"../MENUS/Fecha.h"



using namespace std;

void Pago::setDNIalumno(int dni){

_DNIalumno=dni;
}


void Pago::setNroPago(int numero){

_nroPago=numero;
 }

void Pago::setMonto(float monto)
{
    _monto = monto;
}

void Pago::setFechaDePago(Fecha f)
{
    _fechaDePago = f;
}

void Pago::setAbonado(bool pagado){

_abonado=true;

}

int Pago::getDNIalumno (){

    return _DNIalumno;
}


int Pago::getNroPago(){

    return _nroPago;
}

float Pago::getMonto(){

    return _monto;
}
Fecha Pago::getFechaDePago(){

    return _fechaDePago;
}

bool Pago::getAbonado(){

    return _abonado;
}

