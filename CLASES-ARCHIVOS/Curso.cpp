#include "Curso.h"
void Curso::setDniAlumno(int dni)
{

    _dniAlumno = dni;
}
void Curso::setIdMateria(int idmateria)
{

_id_materia = idmateria;
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
int Curso::getIdMateria()
{
return _id_materia;

}
int Curso::getIdProfesor()
{
return _id_profesor;

}
int Curso::getCurso()
{

return _curso;

}

