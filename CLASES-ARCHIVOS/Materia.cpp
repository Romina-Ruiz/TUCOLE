#include <iostream>
#include <string>
#include <cstring>
#include "Materia.h"
#include"../MENUS/FUNCIONES_FRONT.h"


void Materia::setAnioLectivo(int aniolectivo){

_anio_lectivo = aniolectivo;

}

void Materia::setNombreMateria(std::string  nombre)
{

    strcpy(_nombre,nombre.c_str());

}

void Materia::setId(int id)
{

    _id = id;

}


void Materia::setidProfesor(int idprofe)
{
        _idprofesor=idprofe;

}

void Materia::setDia1( std::string  d1)
{

    strcpy(_dia1,d1.c_str());

}
void Materia::setHorario1( std::string  h1)
{

    strcpy(_horario1,h1.c_str());

}
void Materia::setDia2( std::string  d2)
{

    strcpy(_dia2,d2.c_str());

}
void Materia::setHorario2( std::string  h2)
{

    strcpy(_horario2,h2.c_str());

}

void Materia::setEliminada(bool eliminada){

_eliminada = eliminada;
}


int Materia::getAnioLectivo(){

return _anio_lectivo;

}

 std::string  Materia:: getNombreMateria()
{
 std::string nombre;
 nombre=_nombre;
    return nombre;
}

int Materia::getIdMateria()
{

    return _id;

}

int Materia::getidProfesor()
{

    return _idprofesor;

}

 std::string  Materia::getDia1()
{
 std::string  dia1;
 dia1=_dia1;
   return dia1;
}

 std::string  Materia::getDia2()
{
     std::string dia2;
     dia2=_dia2;

    return dia2;
}

 std::string  Materia::getHorario1()
{
 std::string horario1;
 horario1=_horario1;
    return horario1;
}

 std::string  Materia::getHorario2()
{
    std::string horario2;
    horario2=_horario2;
    return horario2;
}

bool Materia::getEliminada(){

return _eliminada;
}
