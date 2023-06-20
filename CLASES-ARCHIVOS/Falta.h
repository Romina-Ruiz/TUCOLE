#ifndef FALTA_H
#define FALTA_H
#include "../MENUS/Fecha.h"

class Falta
{
private:
    /// UTILIZAR DNI ALUMNO
    int _DNIalumno;
    Fecha _fechaAusencia;
    int _cantFaltasAnuales;
    int _cantFaltasPermitidas;


public:

    void setDNIAlumno(int dni);
    void setFechaAusencia(Fecha fecha);
    void setCantFaltasAnuales( int anuales);
    void setCantFaltasPermitidas(int permitidas);

    int getDNIAlumno();
    Fecha getFechaAusencia();
    int getCantFaltasAnuales();
    int getCantFaltasPermitidas();

    void Cargar(int dni);

    };

#endif // FALTA_H
