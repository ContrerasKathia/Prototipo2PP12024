#include "Usuario.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;

void Usuario::menu()
{
    system("cls");
    int choice;
    bool repetir = true;
    char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA SUCURSALES EMPLEADOS  |"<<endl;
	cout<<"\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t 1. Alta de Empleados (Ingreso) "<<endl;
	cout<<"\t\t\t 2. Baja de Empleados (Borrado) "<<endl;
	cout<<"\t\t\t 3. Modificaciones Empleados"<<endl;
	cout<<"\t\t\t 4. Consulta de Empleados"<<endl;
	cout<<"\t\t\t 5. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agregar Otro Empleado (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		borrar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		repetir = false;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(repetir);
}
void Usuario::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Alta (Ingreso) de Empleados ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id del Usuario        : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del Usuario     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Estado del Usuario  (1,0) : ";
	cin>>estado;
	cout<<"\t\t\tIngresa Contraseña del Usuario : ";
	cin>>contrasenas;
	file.open("Usuarios.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< contrasenas << "\n";
	file.close();
}
void Usuario::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Informe de Empleados -------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> estado >> contrasenas;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Usuario        : "<<id<<endl;
			cout<<"\t\t\t Nombre Usuario       : "<<name<<endl;
			cout<<"\t\t\t Estado Usuario 0,1  : "<<estado<<endl;
			cout<<"\t\t\t Contraseña Usuario    : "<<contrasenas<<endl;
			file >> id >> name >> estado >> contrasenas;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void Usuario::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Usuarios-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del usuario que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> estado >> contrasenas;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1 <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< contrasenas << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Id del Usuario        : ";
                cin>>id;
                cout<<"\t\t\tIngresa Nombre del Usuario     : ";
                cin>>name;
                cout<<"\t\t\tIngresa Estado del Usuario   : ";
                cin>>estado;
                cout<<"\t\t\tIngresa Contraseña del Usuario   : ";
                cin>>contrasenas;
				file1 <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< contrasenas << "\n";
				found++;
			}
			file >> id >> name >> estado >> contrasenas;

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
void Usuario::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Usuario Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Usuario Buscado------------------------"<<endl;
		cout<<"\nIngrese Id del Usuario que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> estado >> contrasenas;
		while(!file.eof())
		{
			if(participant_id==id)
			{

			    cout<<"\n\n\t\t\t Id Usuario        : "<<id<<endl;
                cout<<"\t\t\t Nombre Usuario       : "<<name<<endl;
                cout<<"\t\t\t Estado Usuario 0,1  : "<<estado<<endl;
                cout<<"\t\t\t Contraseña Usuario    : "<<contrasenas<<endl;
				found++;
			}
			file >> id >> name >> estado >> contrasenas;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrada...";
		}
		file.close();
	}
}
void Usuario::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Baja (Borrado) del Usuario-------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> estado >> contrasenas;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1 <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< contrasenas << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> estado >> contrasenas;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Empleado.txt");
	}
}

bool Usuario::loginPersona() //Login de Inicio de sesión para jugadores Registrados
{
    string usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"--------------------------"<<endl;
        cout<<"AUTENTICACION DE USUARIOS "<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Nombre de usuario: ";

        getline(cin, usuario);
        cout<<"\ncontrasena: ";
        char caracter;
        caracter= getch();
        contra="";
        while (caracter !=13)
        {
            if(caracter !=8)
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b";
                    contra = contra.substr(0, contra.length()-1);
                }
            }
            caracter = getch();
        }

        if (buscarLoginPersona(usuario, contra)){   //Pide los parametro de la funcion BuscarLoginJugador para iniciar sesión
            ingresa=true;
        } else {
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;
        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, sus contrasenas son invalidas o agoto intentos"<<endl;
        cin.get();
    } else {
        cout<<"\n=== Bienvenidos al Sistema ==="<<endl;
        cin.get();
    }
    return ingresa;
}

bool Usuario::buscarLoginPersona(string user, string passw) //Funcion que busca al jugador dentro de los archivos secuenciales. Enviale los parametro a LoginJugador
{
    system ("cls");
    fstream file;
    int found=0;
    file.open("Usuarios.txt", ios::in);
    if (!file)
    {
        cout<<"\n---------------------------Datos de la Persona buscado----------------------"<<endl;
        cout<<"\n\t\t\tNo hay informacion...";
    }
    else
    {
        file >> id >> name >> estado >> contrasenas;
        while(!file.eof())
        {
            if(user==name || user == USUARIOADM)
            {
                if (passw == contrasenas || passw == PASSWORD1)
                {
                    found++;
                }
            }
            file >> id >> name >> estado >> contrasenas;
        }
        if(found==0)
        {
            return false;
        }
        else
            return true;

        file.close();}
}
