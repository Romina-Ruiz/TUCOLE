#include <iostream>
#include <cstring>

#include "Profesor.h"

void Profesor::setidprofesor(int id)
{
    _id_profesor = id;
}
void Profesor::setIdMateria(int id)
{
    _id_materia = id;
}

void Profesor::setActivo(bool activo)
{
    _activo = activo;
}

int Profesor::getidProfesor()
{
    return _id_profesor;
}
int Profesor::getIdMateria()
{
    return _id_materia;
}

bool Profesor::getActivo()
{
    return _activo;
}

