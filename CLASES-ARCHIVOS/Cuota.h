#ifndef CUOTA_H
#define CUOTA_H
#include "../MENUS/Fecha.h"
#include"CuotaManager.h"
#include"CuotaArchivo.h"
class Cuota
{
private:
    int _DNIalumno;
    int _tipoDeCuota;  ///1- cuota 2-matricula 3-Extraordinario
    int _nroFact;
    float _monto;
    Fecha _fechaDeFact;
    bool _debe;         ///true=debe  false=pago;

public:
    Cuota();
    void setDNIalumno(int dni);
    void settipoDeCuota(int cuota);
    void setNroFact(int numero);
    void setMonto(float monto);
    void setFechaDeFact(Fecha fact);
    void setDebe(bool debe);

    int getDNIalumno ();
    int gettipoDeCuota();
    int getNroFact();
    float getMonto();
    Fecha getFechaDeFact();
    bool getDebe();
    void Cargar(int dni);

};

#endif // CUOTA_H
