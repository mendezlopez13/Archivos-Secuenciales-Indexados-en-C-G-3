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
