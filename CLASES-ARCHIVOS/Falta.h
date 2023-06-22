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


public:

    void setDNIAlumno(int dni);
    void setFechaAusencia(Fecha fecha);
    void setCantFaltasAnuales( int anuales);
    void setFalta(int falta);

    int getDNIAlumno();
    Fecha getFechaAusencia();
    int getCantFaltasAnuales();
    int getFalta();


    };

#endif // FALTA_H
