#include <iostream>
#include <cstring>

#include "Profesor.h"

void Profesor::setId(int id)
{
    _id = id;
}

void Profesor::setMateriaAcargo(char *materia)
{
    strcpy(_materia_a_cargo,materia);
}


void Profesor::setEstado(bool estado)
{
    _estado = estado;
}


int Profesor::getId()
{
    return _id;
}


char* Profesor::getMateriaAcargo()
{
    return _materia_a_cargo;
}

bool Profesor::getEstado()
{
    return _estado;
}

