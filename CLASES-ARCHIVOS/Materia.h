#ifndef MATERIA_H
#define MATERIA_H


class Materia
{
private:
/// AGREGAR HORARIO + DIA DE CURSADA
    char _nombre[30];
    int _id;
    int _anio_de_curso;
    char _nombre_alumno[30];
    char _nombre_profesor[30];
    int _id_profesor;

public:

    void setNombreMateria( char* nombre);
    void setId(int id);
    void setAnioCurso(int anio);
    void setNombreAlumno(char* nombrealu);
    void setNombreProfesor(char* nombreprofe);
    void setidProfesor(int idprofe);

    char* getNombreMateria();
    int getIdMateria();
    int getAnioCurso();
    char* getNombreAlumno();
    char* getNombreProfesor();
    int getIdProfesor();


};

#endif // MATERIA_H
