#include <iostream>
#include <cstring>
#include "Curso.h"

void Curso::setDniAlumno(int dni)
{

    _dniAlumno = dni;
}
void Curso::setidMateria(int idMateria)
{

_idmateria=idMateria;
}
void Curso::setIdProfesor(int idprofesor)
{

_id_profesor = idprofesor;

}
void Curso::setCurso(int curso)
{

_curso = curso;
}
void Curso::setEstado(bool e){

_estado=e;

}

int Curso::getDniAlumno()
{

return _dniAlumno;

}
int  Curso::getIdMateria()
{
return _idmateria;

}
int Curso::getIdProfesor()
{
return _id_profesor;

}
int Curso::getCurso()
{

return _curso;

}

bool Curso::getEstado(){

return _estado;

}
