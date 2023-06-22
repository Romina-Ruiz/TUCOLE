#include "Cuota.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"


using namespace std;

void Cuota::setDNIalumno(int dni){

_DNIalumno=dni;    /// tal vez hay que validar que este el dni en el archivo de alumno?
}

void Cuota::settipoDeCuota(int cuota){

    _tipoDeCuota=cuota;

}

void Cuota::setNroFact(int numero){

_nroFact=numero;  ///aca se necesita funcion para que traiga el numero automatico
 }

void Cuota::setMonto(float monto)
{
    _monto = monto;
}

void Cuota::setFechaDeFact(Fecha fact)
{
    _fechaDeFact = fact;
}

void Cuota::setDebe(bool debe){

_debe=true;

}

int Cuota::getDNIalumno (){

    return _DNIalumno;
}

int Cuota::gettipoDeCuota(){


    if (_tipoDeCuota>=1 && _tipoDeCuota <=3){
      return _tipoDeCuota;
                }
}

int Cuota::getNroFact(){

    return _nroFact;
}

float Cuota::getMonto(){

    return _monto;
}
Fecha Cuota::getFechaDeFact(){

    return _fechaDeFact;
}

bool Cuota::getDebe(){

    return _debe;
}

