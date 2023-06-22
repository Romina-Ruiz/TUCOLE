#ifndef PAGO_H
#define PAGO_H
#include "../MENUS/Fecha.h"

class Pago
{
    private:
    int _DNIalumno;
    int _nroPago;
    float _monto;
    Fecha _fechaDePago;
    bool _abonado;         ///SE NECESITA???

public:

    void setDNIalumno(int dni);
    void setNroPago(int numero);
    void setMonto(float monto);
    void setFechaDePago(Fecha f);
    void setAbonado(bool pagado);

    int getDNIalumno ();
    int getNroPago();
    float getMonto();
    Fecha getFechaDePago();
    bool getAbonado();

};

#endif // PAGO_H
