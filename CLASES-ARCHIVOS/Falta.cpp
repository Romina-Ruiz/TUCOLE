#include <iostream>
#include "Falta.h"
#include <cstring>
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"

using namespace std;



void Falta::setDNIAlumno(int dni)
{
    _DNIalumno = dni;

}

void Falta::setFechaAusencia(Fecha fecha)
{
    _fechaAusencia= fecha;

}
void Falta::setCantFaltasAnuales( int anuales)
{
    _cantFaltasAnuales= anuales;

}
void Falta::setFalta(int falta)
{

    _Falta = falta;

}
void Falta::setEliminada(bool eliminada){

_eliminada = eliminada;

}
int Falta::getDNIAlumno()
{

    return _DNIalumno;
}

Fecha Falta::getFechaAusencia()
{

    return _fechaAusencia;
}

int Falta::getCantFaltasAnuales()
{

    return _cantFaltasAnuales;

}

int Falta::getFalta()
{

    return _Falta;
}

bool Falta::getEliminada(){

return _eliminada;
}
