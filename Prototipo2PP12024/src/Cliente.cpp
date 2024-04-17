#include "Cliente.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;

void Cliente::menu()
{
    system("cls");
    int choice;
    bool repetir = true;
    char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA SUCURSALES CLIENTES |"<<endl;
	cout<<"\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t 1. Alta de CLIENTES (Ingreso) "<<endl;
	cout<<"\t\t\t 2. Baja de CLIENTES  (Borrado) "<<endl;
	cout<<"\t\t\t 3. Modificaciones CLIENTES "<<endl;
	cout<<"\t\t\t 4. Consulta de CLIENTES "<<endl;
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
    		cout<<"\n\t\t\t Agregar Otro CLIENTE (Y,N): ";
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
void Cliente::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Alta (Ingreso) de CLIENTES ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id del CLIENTE       : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del CLIENTE     : ";
	cin>>name;
	cout<<"\t\t\tIngresa apellido del CLIENTE     : ";
	cin>>apellido;
	cout<<"\t\t\tIngresa tipo de CLIENTE     : ";
	cin>>tipo;
	cout<<"\t\t\tIngresa Nit del CLIENTE     : ";
	cin>>nit;
	cout<<"\t\t\tIngresa Estado del CLIENTE  (1,0) : ";
	cin>>estado;
	cout<<"\t\t\tIngresa direccion del CLIENTE : ";
	cin>>direccion;
	cout<<"\t\t\tIngresa correo del CLIENTE : ";
	cin>>correo;
	cout<<"\t\t\tIngresa telefono del CLIENTE : ";
	cin>>telefono;
	file.open("Cliente.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< contrasenas << "\n";
	file.close();
}
void Cliente::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Informe de CLIENTES  -------------------------"<<endl;
	file.open("Cliente.txt",ios::in);
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
			cout<<"\n\n\t\t\t Id CLIENTE        : "<<id<<endl;
			cout<<"\t\t\t Nombre CLIENTE       : "<<name<<endl;
			cout<<"\t\t\t Estado CLIENTE 0,1  : "<<estado<<endl;
			cout<<"\t\t\t Contraseña CLIENTE    : "<<contrasenas<<endl;
			file >> id >> name >> estado >> contrasenas;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void Cliente::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion CLIENTES -------------------------"<<endl;
	file.open("Cliente.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del CLIENTES que quiere modificar: ";
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
				cout<<"\t\t\tIngresa Id del CLIENTES       : ";
                cin>>id;
                cout<<"\t\t\tIngresa Nombre del CLIENTE    : ";
                cin>>name;
                cout<<"\t\t\tIngresa Estado del CLIENTE  : ";
                cin>>estado;
                cout<<"\t\t\tIngresa Contraseña del CLIENTE   : ";
                cin>>contrasenas;
				file1 <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< contrasenas << "\n";
				found++;
			}
			file >> id >> name >> estado >> contrasenas;

		}
		file1.close();
		file.close();
		remove("Cliente.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
void Cliente::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Cliente.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del CLIENTE Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos delCLIENTE Buscado------------------------"<<endl;
		cout<<"\nIngrese Id del CLIENTE que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> estado >> contrasenas;
		while(!file.eof())
		{
			if(participant_id==id)
			{

			    cout<<"\n\n\t\t\t Id CLIENTE        : "<<id<<endl;
                cout<<"\t\t\t Nombre CLIENTE       : "<<name<<endl;
                cout<<"\t\t\t Estado CLIENTES 0,1  : "<<estado<<endl;
                cout<<"\t\t\t Contraseña CLIENTE    : "<<contrasenas<<endl;
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
void Cliente::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Baja (Borrado) del CLIENTE-------------------------"<<endl;
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
