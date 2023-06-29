#include <iostream>
#include <cstring>
#include "Curso.h"

void Curso::setDniAlumno(int dni)
{

    _dniAlumno = dni;
}
void Curso::setNombreMateria(char *nombre_materia)
{

strcpy(_nombre_materia,nombre_materia);
}
void Curso::setIdProfesor(int idprofesor)
{

_id_profesor = idprofesor;

}
void Curso::setCurso(int curso)
{

_curso = curso;
}

int Curso::getDniAlumno()
{

return _dniAlumno;

}
char* Curso::getnombreMateria()
{
return _nombre_materia;

}
int Curso::getIdProfesor()
{
return _id_profesor;

}
int Curso::getCurso()
{

return _curso;

}

