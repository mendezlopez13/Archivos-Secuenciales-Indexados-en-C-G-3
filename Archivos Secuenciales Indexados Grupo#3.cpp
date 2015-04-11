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
do{				

system("cls");		
	
ofstream dat("datos.txt", ios::binary | ios::app);	
ofstream ind("index.txt", ios::binary | ios::app);	
ifstream indic("index.txt", ios::binary);			
		
remove("datos.txt");
		
cout<<"*** BIENVENIDOS ***"<<endl<<endl;
cout<<"Base de Datos Estudiantes UMG:"<<endl<<endl;

cout<<"1. Ingresar datos de estudiante"<<endl;
cout<<"2. Buscar datos de un estudiante"<<endl;
cout<<"3. Borrar registros"<<endl;		
cout<<"4. Salir del programa"<<endl;

cout<<endl<<"Seleccione una opcion: ";
cin>>opcion;					
cout<<endl;

if(opcion>0 && opcion<4){	
	switch(opcion){			
		
case 1: 				
		
	if(!dat && !ind){		
	cout<<"Error al abrir archivo"<<endl;
	}else{
	
	cout<<"Ingrese carnet: ";
	cin>>alumno.carnet;			
	cout<<endl;
	
	while(!indic.eof()){
	
indic.read((char*) &aux, sizeof(struct index));

if (alumno.carnet==aux.carnet){
	
	cout<<"El archivo ya existe, Posicion: "<<aux.posicion;
	cout<<endl;
	
	bus=10;
}
	}

indic.close();
	
	if(bus!=10){
	
	cout<<"Ingrese nombre: ";
	cin>>alumno.nombre;
	cout<<endl;

	cout<<"Ingrese edad: ";
	cin>>alumno.edad;
	cout<<endl;
	
	cout<<"Ingrese carrera: ";
	cin>>alumno.carrera;
	cout<<endl;

	dat.write((char*) &alumno, sizeof(struct estudiante)); 
	dat.seekp(0, ios::end);	
	indice.carnet=alumno.carnet;			
	indice.posicion=dat.tellp()/sizeof(struct estudiante);  
	ind.write((char*) &indice, sizeof(struct index));

	cout<<"Guardado en posicion: "<<"["<<indice.posicion<<"]"<<endl;
	dat.close();
	ind.close();	}	
	
	system("PAUSE"); break;	

	}
		
