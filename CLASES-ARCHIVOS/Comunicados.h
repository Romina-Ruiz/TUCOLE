#ifndef COMUNICADOS_H
#define COMUNICADOS_H
#include "../MENUS/Fecha.h"
#include <string>

class Comunicados
{
private:
    char _comunicado[300];
    int _id_comunicado;
    int _DNIalumno;
    int _id_materia;
    int _anio_curso;
    Fecha _fechaComunicado;
    bool _eliminado; //true activo false eliminado


public:

    void setComunicado(std::string comunicado);
    void setIdComunicado(int idcomunicado);
    void setDNIalumno(int dni);
    void setIdMateria(int id);
    void setAnioCurso(int curso);
    void setFechaComunicado(Fecha fecha);
    void setEliminado(bool eliminado);

    std::string getComunicado();
    int getIdComunicado();
    int getDni();
    int getIdMateria();
    int getAnioCurso();
    Fecha getFechaComunicado();
    bool getEliminado();

};

#endif // COMUNICADOS_H
