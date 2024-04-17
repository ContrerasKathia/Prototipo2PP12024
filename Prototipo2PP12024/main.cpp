#include <iostream> //Librerias y Encabezados
#include <conio.h>
#include "persona.h"
#include "MenuGeneral.h"
using namespace std;

main()
{

//Login Usuario


    persona usuarioRegistrado;
    bool accesoUsuario;
    accesoUsuario = usuarioRegistrado.loginPersona();
    if (accesoUsuario)
        {
    int opciones;
    bool repetir = true;
    do
    {
        MenuGeneral Menu;
        Menu.menuPrincipal();
    }while (repetir);}

    getch();
	return 0;
}
