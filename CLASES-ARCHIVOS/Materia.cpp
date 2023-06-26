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


