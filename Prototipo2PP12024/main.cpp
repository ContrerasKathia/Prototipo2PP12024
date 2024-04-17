#include <iostream> //Librerias y Encabezados
#include <conio.h>
#include "Usuario.h"
#include "MenuGeneral.h"
using namespace std;

main()
{

//Login Usuario


    Usuario usuarioRegistrado;
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
