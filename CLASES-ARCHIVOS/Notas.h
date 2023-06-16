#ifndef NOTAS_H
#define NOTAS_H


class Notas
{

private:

    char _nombreMateria[30];
    int _id_materia;
    int _anio_curso;
    char _nombre_alumno[30];
    int _id_alumno;
    int _nota;
    char _nombre_Profesor[30];
    int _id_profesor;


public:
    void setNombreMateria(char* nombremateria);
    void setIdMateria(int idmateria);
    void setAnioCurso(int aniocurso);
    void setNombreAlumno(char * nombrealumno);
    void setidAlumno(int idalumno);
    void setNota(int nota);
    void setNombreProfesor(char* nombreprofe);
    void setidProfesor(int idprofe);

    char *getNombreMateria();
    int getIdMateria();
    int getAnioCurso();
    char *getNombreAlumno();
    int getIdAlumno() ;
    int getNota();
    char *getNombreProfesor();
    int getIdProfesor();

};

#endif // NOTAS_H
