#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"



void SalirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By ARIADNA & ROMINA", 68, 20);
}

