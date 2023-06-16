#include "Alumno.h"

void Alumno::setId(int id)
{
    _id = id;
}

void Alumno::setCurso(int curso)
{
    _curso = curso;
}

void Alumno::setActivo(bool activo)
{
    _activo = activo;
}


int Alumno::getId()
{
    return _id;
}

int Alumno::getCurso()
{
    return _curso;
}

bool Alumno::getActivo()
{
    return _activo;
}

