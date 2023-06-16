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
void Materia::setAnioCurso(int anio)
{

    _anio_de_curso = anio;

}
void Materia::setNombreAlumno( char* nombrealu)
{

    strcpy(_nombre_alumno,nombrealu);
}
void Materia::setNombreProfesor( char* nombreprofe)
{

    strcpy(_nombre_profesor,nombreprofe);
}
void Materia::setidProfesor(int idprofe)
{

    _id_profesor = idprofe;

}


char* Materia:: getNombreMateria()
{

    return _nombre;
}

int Materia::getIdMateria()
{

    return _id;

}
int Materia::getAnioCurso()
{

    return _anio_de_curso;

}
char* Materia::getNombreAlumno()
{

    return _nombre_alumno;
}
char* Materia::getNombreProfesor()
{


    return _nombre_profesor;
}
int Materia:: getIdProfesor()
{


    return _id_profesor;
}

