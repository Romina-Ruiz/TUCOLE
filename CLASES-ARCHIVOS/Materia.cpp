#include <iostream>
#include "Materia.h"
#include <cstring>

void Materia::setNombreMateria(char* nombre)
{

    strcpy(_nombre,nombre);

}
void Materia::setId(int id)
{

    _id = id;

}


void Materia::setNombreProfesor( char* nombreprofe)
{

    strcpy(_nombre_profesor,nombreprofe);
}
void Materia::setAnioLectivo(int aniolectivo){

_anio_lectivo = aniolectivo;

}
void Materia::setEliminada(bool eliminada){

_eliminada = eliminada;
}

char* Materia:: getNombreMateria()
{

    return _nombre;
}

int Materia::getIdMateria()
{

    return _id;

}


char* Materia::getNombreProfesor()
{


    return _nombre_profesor;
}

int Materia::getAnioLectivo(){

return _anio_lectivo;

}
bool Materia::getEliminada(){

return _eliminada;
}
