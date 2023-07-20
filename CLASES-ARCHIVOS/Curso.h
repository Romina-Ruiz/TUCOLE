#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    int _idCurso; ///202301-202302-202303 a fin de a�o se pone el false los 3 a�os
    int _curso; ///1-PRIMER A�O/ 2-SEGUNDO A�O/ 3 TERCER A�O
    int _estado; /// SE PONE EN FALSE LOS A�OS ANTERIORES

public:
    void setDniAlumno(int dni);
    void setidCurso(int idcur);
    void setCurso(int curso);
    void setEstado(bool e); ///true activo

    int getDniAlumno();
    int getIdCurso();
    int getCurso();
    bool getEstado();

};

#endif // CURSO_H
