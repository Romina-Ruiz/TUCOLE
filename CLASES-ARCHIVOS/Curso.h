#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    int _idmateria;
    int _id_profesor;
    int _curso; ///1-PRIMER AÑO/ 2-SEGUNDO AÑO/ 3 TERCER AÑO
    int _estado;

public:
    void setDniAlumno(int dni);
    void setidMateria(int idMat);
    void setIdProfesor(int idprofesor);
    void setCurso(int curso);
    void setEstado(bool e);

    int getDniAlumno();
    int getIdMateria();
    int getIdProfesor();
    int getCurso();
    bool getEstado();

};

#endif // CURSO_H
