#include <iostream>
#include <string>
#include <cstring>
#include "Alumno.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"
#include"AlumnoArchivo.h"
#include "Persona.h"


using namespace std;



void Alumno::setEstado(bool estado)
{

    if(estado==1){
        _Estado = true;
            }
            else{
                _Estado = false;
            }

}

void Alumno::setLegajo(int legajo)
{
       _Legajo=legajo;
}

Fecha Alumno::setIngreso(Fecha ingreso)
{
    _Ingreso= ingreso;
}


int Alumno::getLegajo()
{
    return _Legajo;
}

Fecha Alumno::getIngreso()
{
    return _Ingreso;
}
bool Alumno::getEstado()
{
    return _Estado;
}
