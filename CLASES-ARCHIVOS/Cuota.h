#ifndef CUOTA_H
#define CUOTA_H
#include "../MENUS/Fecha.h"


class Cuota
{
private:
    float _monto;
    Fecha _fecha_de_pago;

public:
    Cuota();
    void setMonto(float monto);
    void setFechaDePago(Fecha fechaDePago);

    float getMonto();
    Fecha getFechaDePago();

};

#endif // CUOTA_H
