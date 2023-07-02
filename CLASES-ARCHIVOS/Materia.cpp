#include <iostream>
#include "Materia.h"
#include <cstring>



void Materia::setAnioLectivo(int aniolectivo){

_anio_lectivo = aniolectivo;

}

void Materia::setNombreMateria(char* nombre)
{

    strcpy(_nombre,nombre);

}

void Materia::setId(int id)
{

    _id = id;

}


void Materia::setidProfesor(int idprofe)
{
        _idprofesor=idprofe;

}

void Materia::setDia1(char* d1)
{

    strcpy(_dia1,d1);

}
void Materia::setHorario1(char* h1)
{

    strcpy(_horario1,h1);

}
void Materia::setDia2(char* d2)
{

    strcpy(_dia2,d2);

}
void Materia::setHorario2(char* h2)
{

    strcpy(_horario2,h2);

}

void Materia::setEliminada(bool eliminada){

_eliminada = eliminada;
}


int Materia::getAnioLectivo(){

return _anio_lectivo;

}

char* Materia:: getNombreMateria()
{

    return _nombre;
}

int Materia::getIdMateria()
{

    return _id;

}

int Materia::getidProfesor()
{

    return _idprofesor;

}

char* Materia::getDia1()
{

    return _dia1;
}

char* Materia::getDia2()
{

    return _dia2;
}

char* Materia::getHorario1()
{

    return _horario1;
}

char* Materia::getHorario2()
{
    return _horario2;
}

bool Materia::getEliminada(){

return _eliminada;
}
