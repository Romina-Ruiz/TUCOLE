#ifndef FALTA_H
#define FALTA_H
#include "../MENUS/Fecha.h"

class Falta
{
private:
    char _nombre_Alumno[30];
    int _id_alumno;
    int _anio_Curso;
    Fecha _fecha_ausencia;
    int _cantidad_faltas_anuales;
    int _cantidad_faltas_permitidas;


public:


    void setNombreAlumno(char* nombrealumno);
    void setidAlumno(int idalumno);
    void setAnioCurso(int aniocurso);
    void setFechaAusencia(Fecha fechaausencia);
    void setCantidadFaltasAnuales( int faltasanuales);
    void setCantidadFaltasPermitidas(int faltaspermitidas);

    char* getNombreAlumno();
    int getidAlumno();
    int getAnioCurso();
    Fecha getFechaAusencia();
    int getCantidadFaltasAnuales();
    int getCantidadFaltasPermitidas();

    };

#endif // FALTA_H
