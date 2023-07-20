#include <iostream>
#include <cstring>
#include "Curso.h"

void Curso::setDniAlumno(int dni)
{

    _dniAlumno = dni;
}
void Curso::setidCurso(int idcur)
{

_idCurso=idcur;
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
int  Curso::getIdCurso()
{
return _idCurso;

}

int Curso::getCurso()
{

return _curso;

}

bool Curso::getEstado(){

return _estado;

}
