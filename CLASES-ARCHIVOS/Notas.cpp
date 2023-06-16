#include <iostream>
#include "Notas.h"
#include <cstring>
void Notas::setNombreMateria(char* nombremateria)
{

    strcpy(_nombreMateria,nombremateria);


}
void Notas::setIdMateria(int idmateria )
{

    _id_materia = idmateria;

}
void Notas::setAnioCurso(int aniocurso)
{

    _anio_curso = aniocurso;

}
void Notas::setNombreAlumno(char * nombrealumno)
{

    strcpy(_nombre_alumno,nombrealumno);


}
void Notas::setidAlumno(int idalumno)
{

    _id_alumno = idalumno;

}
void Notas::setNota(int nota)
{

    _nota = nota;

}
void Notas::setNombreProfesor(char *nombreprofe)
{

    strcpy(_nombre_Profesor,nombreprofe);

}
void Notas::setidProfesor(int idprofe)
{

    _id_profesor = idprofe;

}

char* Notas::getNombreMateria()
{

    return _nombreMateria;
}
int Notas::getIdMateria()
{

    return _id_materia;
}
int Notas::getAnioCurso()
{

    return _anio_curso;

}
char * Notas::getNombreAlumno()
{

    return _nombre_alumno;

}
int Notas::getIdAlumno()
{

    return _id_alumno;
}
int Notas::getNota()
{

    return _nota;
}

char *Notas::getNombreProfesor()
{

    return _nombre_Profesor;

}
int Notas::getIdProfesor()
{

    return _id_profesor;

}

