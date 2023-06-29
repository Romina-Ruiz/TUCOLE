#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    char _nombre_materia[30];
    int _id_profesor;
    int _curso; ///1-PRIMER AÑO/ 2-

public:
    void setDniAlumno(int dni);
   void setNombreMateria(char * nombremateria);
    void setIdProfesor(int idprofesor);
    void setCurso(int curso);

    int getDniAlumno();
    char * getnombreMateria();
    int getIdProfesor();
    int getCurso();

};

#endif // CURSO_H
