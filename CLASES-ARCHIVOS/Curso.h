#ifndef CURSO_H
#define CURSO_H


class Curso
{
private:
    int _dniAlumno;
    int _idCurso; ///202301-202302-202303 a fin de año se pone el false los 3 años
    int _curso; ///1-PRIMER AÑO/ 2-SEGUNDO AÑO/ 3 TERCER AÑO
    int _estado; /// SE PONE EN FALSE LOS AÑOS ANTERIORES

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
