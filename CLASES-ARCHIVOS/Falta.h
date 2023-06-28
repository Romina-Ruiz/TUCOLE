#ifndef FALTA_H
#define FALTA_H
#include "../MENUS/Fecha.h"

class Falta
{
private:

    int _DNIalumno;
    Fecha _fechaAusencia;
    int _cantFaltasAnuales;
    int _Falta;
    bool _eliminada;


public:

    void setDNIAlumno(int dni);
    void setFechaAusencia(Fecha fecha);
    void setCantFaltasAnuales( int anuales);
    void setFalta(int falta);
    void setEliminada(bool eliminada);

    int getDNIAlumno();
    Fecha getFechaAusencia();
    int getCantFaltasAnuales();
    int getFalta();
    bool getEliminada();


    };

#endif // FALTA_H
