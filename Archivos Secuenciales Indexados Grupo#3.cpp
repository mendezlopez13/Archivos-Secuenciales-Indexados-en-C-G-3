//Archivos secuenciales indexados C++, Grupo#3 Programacion I
//Ingenieria en Sistemas de Informacion y Ciencias de la Computacion
//Jalapa, Jalapa.

#include <iostream>
#include <fstream> 
#include <cstdio>

using namespace std;
	struct estudiante {
		
	int carnet;
 	char nombre[15];	
	int edad;
	char carrera[20]; };
		
	struct index{
		
	int carnet;
 	int posicion;	};
int main(){		

int opcion, bus;			
estudiante alumno, auxi;	
index indice, aux;

do{					//se abre un do while para repetir menu

system("cls");		//limpia la pantalla
	
ofstream dat("datos.txt", ios::binary | ios::app);	//declaracion de archivo para almacenar datos
ofstream ind("index.txt", ios::binary | ios::app);	//declaracion de archivo para almacenar indice
ifstream indic("index.txt", ios::binary);			//declaracion de archivo para buscar datos leendolos
		
cout<<"*** BIENVENIDOS ***"<<endl<<endl;
cout<<"Base de Datos Estudiantes UMG:"<<endl<<endl;

cout<<"1. Ingresar datos de estudiante"<<endl;
cout<<"2. Buscar datos de un estudiante"<<endl;
cout<<"3. Borrar registros"<<endl;		//opciones para el switch
cout<<"4. Salir del programa"<<endl;

cout<<endl<<"Seleccione una opcion: ";
cin>>opcion;					//se almacena la opcion qu escribamos
cout<<endl;

if(opcion>0 && opcion<4){	//este if es para que entre al switch solo si va a ser usado con la condicion
							//que el numero de opcion este entre 1 y 3
	switch(opcion){			//inicio del switch
		

default: break;	//esto no hace nada por el momento
	
	}//cierra switch
		}//cierra if para entrar a switch
		
	} while(opcion>0 && opcion!=4); 
