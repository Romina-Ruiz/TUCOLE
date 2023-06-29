#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    int _idmateria;
    int _id_profesor;
    int _curso; ///1-PRIMER A�O/ 2-SEGUNDO A�O/ 3 TERCER A�O
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
