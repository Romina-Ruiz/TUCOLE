#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    int _id_materia;
    int _id_profesor;
    int _curso;

public:
    void setDniAlumno(int dni);
    void setIdMateria(int idmateria);
    void setIdProfesor(int idprofesor);
    void setCurso(int curso);

    int getDniAlumno();
    int getIdMateria();
    int getIdProfesor();
    int getCurso();

};

#endif // CURSO_H
