#ifndef COMUNICADOS_H
#define COMUNICADOS_H
#include "../MENUS/Fecha.h"

class Comunicados
{
private:
    char _comunicado[100];
    int _id_comunicado;
    int _DNIalumno;
    int _id_materia;
    int _anio_curso;
    Fecha _fechaComunicado;
    bool _eliminado;


public:
    Comunicados();

    void setIdComunicado(int idcomunicado);
    void setDNIalumno(int dni);
    void setIdMateria(int id);
    void setAnioCurso(int curso);
    void setFechaComunicado(Fecha fecha);
    void setEliminado(bool eliminado);

    int getIdComunicado();
    int getDni();
    int getIdMateria();
    int getAnioCurso();
    Fecha getFechaComunicado();
    bool getEliminado();

};

#endif // COMUNICADOS_H
