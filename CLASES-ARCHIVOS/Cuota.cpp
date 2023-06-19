#include "Cuota.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"
#include"CuotaArchivo.h"
#include"CuotaManager.h"
using namespace std;
void Cuota::setDNIalumno(int dni){

_DNIalumno=dni;    /// tal vez hay que validar que este el dni en el archivo de alumno?
}

void Cuota::settipoDeCuota(int cuota){

    if (cuota >0 && cuota <4){
       _tipoDeCuota=cuota;
            }
}

void Cuota::setNroFact(int numero){

_nroFact=numero;  ///aca se necesita funcion para que traiga el numero automatico
 }

void Cuota::setMonto(float monto)
{
    _monto = monto;
}

void Cuota::setFechaDeFact(Fecha fact)
{
    _fechaDeFact = fact;
}

void Cuota::setDebe(bool debe){

_debe=true;

if (_debe==true){

    cout <<"NO" <<endl;
}

             cout <<"SI" <<endl;


}

int Cuota::getDNIalumno (){

    return _DNIalumno;
}

int Cuota::gettipoDeCuota(){

        return _tipoDeCuota;
}

int Cuota::getNroFact(){

    return _nroFact;
}

float Cuota::getMonto(){

    return _monto;
}
Fecha Cuota::getFechaDeFact(){

    return _fechaDeFact;
}

bool Cuota::getDebe(){

    return _debe;
}
void Cuota::Cargar(int dni){

    rlutil::locate(20,8);
    cout<<"DNI: "<<endl;
    rlutil::locate(26,8);
    _DNIalumno=dni;
    rlutil::locate(20,9);
    cout <<"CUOTA (1-mesual/ 2- matricula/ 3- extraordinaria): "<<endl;
    rlutil::locate(70,9);
   cout <<_tipoDeCuota <<endl;
    rlutil::locate(20,10);
    cout <<"FACTURA N#: "<<endl;
    rlutil::locate(34,10);
    cin >>_nroFact;
    rlutil::locate(20,11);
    cout <<"MONTO DE LA FACTURA: "<<endl;
    rlutil::locate(33,11);
    cin >> _monto;
  rlutil::locate(20,12);
    cout <<"FECHA DE LA FACTURA: "<<endl;
    rlutil::locate(33,12);
   // cin >> _fechaDeFact;
  rlutil::locate(20,13);
    cout <<"ABONADA: "<<endl;
    rlutil::locate(33,13);
    cout <<_debe <<endl;


}
