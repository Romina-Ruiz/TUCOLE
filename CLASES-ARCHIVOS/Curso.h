#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    int _idCurso;
    int _id_profesor;
    int _curso; ///1-PRIMER A�O/ 2-SEGUNDO A�O/ 3 TERCER A�O
    int _estado;

public:
    void setDniAlumno(int dni);
    void setidCurso(int idcur);
    void setIdProfesor(int idprofesor);
    void setCurso(int curso);
    void setEstado(bool e); ///true activo

    int getDniAlumno();
    int getIdCurso();
    int getIdProfesor();
    int getCurso();
    bool getEstado();

};

#endif // CURSO_H
