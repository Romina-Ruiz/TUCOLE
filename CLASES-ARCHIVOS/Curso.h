#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    char _nombre_materia;
    int _id_profesor;
    int _curso; ///1-PRIMER AÑO/ 2-

public:
    void setDniAlumno(int dni);
    void setNombreMateria(int nombremateria);
    void setIdProfesor(int idprofesor);
    void setCurso(int curso);

    int getDniAlumno();
    int getnombreMateria();
    int getIdProfesor();
    int getCurso();

};

#endif // CURSO_H
