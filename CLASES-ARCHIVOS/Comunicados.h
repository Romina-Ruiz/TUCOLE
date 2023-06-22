#ifndef COMUNICADOS_H
#define COMUNICADOS_H
#include "../MENUS/Fecha.h"

class Comunicados
{
private:
    int _id_comunicado;
    int _DNIalumno;
    int _id_materia;
    int _anio_curso;
    Fecha _fechaComunicado;


public:
    Comunicados();
    void setIdComunicado(int idcomunicado);
    void setDNIalumno(int dni);
    void setIdMateria(int id);
    void setAnioCurso(int curso);
    void setFechaComunicado(Fecha fecha);

    int getIdComunicado();
    int getDni();
    int getIdMateria();
    int getAnioCurso();
    Fecha getFechaComunicado();

};

#endif // COMUNICADOS_H