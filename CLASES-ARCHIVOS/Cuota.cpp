#include "Cuota.h"

void Cuota::setMonto(float monto)
{
    _monto = monto;
}

void Cuota::setFechaDePago(Fecha fechaDePago)
{
    _fecha_de_pago = fechaDePago;
}


float Cuota::getMonto()
{
    return _monto;
}

Fecha Cuota::getFechaDePago()
{
    return _fecha_de_pago;
}
