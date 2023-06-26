#include "Curso.h"
void Curso::setDniAlumno(int dni)
{

    _dniAlumno = dni;
}
void Curso::setNombreMateria(int nombre_materia)
{

_nombre_materia = nombre_materia;
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
int Curso::getnombreMateria()
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

