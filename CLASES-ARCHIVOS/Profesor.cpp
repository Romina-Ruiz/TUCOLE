#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Profesor.h"

using namespace std;
void Profesor::setEstado(bool estado)
{
    _Estado = estado;
}

void Profesor::setLegajo(int legajo)
{
    _Legajo = legajo;
}

Fecha Profesor::setIngreso(Fecha ingreso)
{
    _Ingreso=ingreso;
}

bool Profesor::getEstado(){

return _Estado;
}

int Profesor::getLegajo()
{
    return _Legajo;
}
Fecha Profesor::getIngreso()
{
    return _Ingreso;
}

void Profesor::cargar(int dni)
{
    _Estado=true;
    Persona::cargar(dni);
    cout <<"LEGAJO: "<<endl;
    cin >>_Legajo;
    cout <<"FECHA INGRESO: "<<endl;
   // cin >>_Ingreso;

}

