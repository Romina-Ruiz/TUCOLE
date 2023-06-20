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
    _cantFaltasAnuales = anuales;

}
void Falta::setCantFaltasPermitidas(int permitidas)
{
    _cantFaltasPermitidas = permitidas;

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

int Falta::getCantFaltasPermitidas()
{

    return _cantFaltasPermitidas;
}

void Falta::Cargar(int dni)
{
     rlutil::locate(20,8);
    cout<<"DNI: "<<endl;
    rlutil::locate(26,8);
    _DNIalumno=dni;
    rlutil::locate(20,9);
    cout <<"FECHA DE LA FACTURA: "<<endl;
    rlutil::locate(33,9);
    // cin >> _fechaAusencia;
    rlutil::locate(20,10);
    cout <<"CANTIDAD DE FALTAS ANUALES "<<endl;
    rlutil::locate(48,10);
    cout <<_cantFaltasAnuales <<endl;
    rlutil::locate(20,11);
    cout <<"CANTIDAD DE FALTAS PERMITIDAS: "<<endl;
    rlutil::locate(54,11);
    cin >>_cantFaltasPermitidas;

}

