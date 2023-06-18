#include <iostream>
#include "Alumno.h"

using namespace std;

void Alumno::setActivo(bool activo)
{
    _activo = activo;
}
void Alumno::setId(int id)
{
    _id = id;
}

int Alumno::getId()
{
    return _id;
}


bool Alumno::getActivo()
{
    return _activo;
}

void Alumno::cargar(){

    cout <<"INGRESE DNI: "<<endl;
    cin >>_dni ;

}
