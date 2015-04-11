//Archivos secuenciales indexados C++, Grupo#3 Programacion I
//Ingenieria en Sistemas de Informacion y Ciencias de la Computacion
//Jalapa, Jalapa.

#include <iostream>
#include <fstream> 
#include <cstdio>

using namespace std;

//DECLARACION DE ESTRUCTURAS

	struct estudiante {
		
	int carnet;
 	char nombre[15];	
	int edad;
	char carrera[20]; };
		
	struct index{
		
	int carnet;
 	int posicion;	};
	 
int main(){		//inicio main

int opcion, bus;			//variable para el switch
estudiante alumno, auxi;	//variable para almacenar datos de la estructura 
index indice, aux;	//variable para almacenar index(indice) y almacenar temporalmente(aux), durante busqueda
	
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
		
case 1: 				//inicia caso uno de ingresar datos
		
	if(!dat && !ind){		//esta condicion sirve para ver si los archivos a en los cuales vamos a escribir
							//se abren correctamente
	cout<<"Error al abrir archivo"<<endl;
	}else{
								//si se abren correctamente entra a lo siguiente
	cout<<"Ingrese carnet: ";
	cin>>alumno.carnet;			//en esta parte ingresamos datos y los almacenamos en la variable alumno
	cout<<endl;
	
	while(!indic.eof()){
	
indic.read((char*) &aux, sizeof(struct index));

if (alumno.carnet==aux.carnet){
	
	cout<<"El archivo ya existe, Posicion: "<<aux.posicion;
	cout<<endl;
	
	bus=10;
}//cierra if 
	}//cierra while

indic.close();//cierra archivo indc de busqueda
	
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

	dat.write((char*) &alumno, sizeof(struct estudiante)); //persistimos la estructura en el archivo creado
															//para datos
	dat.seekp(0, ios::end);		//colocamos el cursor al final del archivo para ver la ubicacion

	indice.carnet=alumno.carnet;			//aqui le asigno a la variable del indice el valor del campo clave
	indice.posicion=dat.tellp()/sizeof(struct estudiante); //aqui determino la posicion dividiendo entre
														//el tamaño del archivo para asi nos da valores desde 1
	ind.write((char*) &indice, sizeof(struct index));//aqui persisto la estructura del indice en el archivo

	cout<<"Guardado en posicion: "<<"["<<indice.posicion<<"]"<<endl;//esta linea nos muestra la posicion en la
																	//que se guarda la estructura
	dat.close();
	ind.close();	}	//cierro ambos archivos
	
	system("PAUSE"); break;	//esto solo detiene el programa y el break finaliza el caso

	}//cierra if en case 1
		
case 2://empieza el caso 2 el de busqueda de archivo
	
	int buscar;	//variable que guarda lo que queramos buscar que en este caso la clave va a ser el carnet

	cout<<"Escriba carnet de alumno a buscar: ";
	cin>>buscar;
		
	while(!indic.eof()){	//while que va a repetir mientras no sea el final del archivo
	
	indic.read((char*) &aux, sizeof(struct index));	//se lee el archivo y guarda en variable aux

	if (buscar==aux.carnet){	//se compara si lo que se busca es igual a lo de la variable aux
	
	cout<<endl<<"POSICION: "<<aux.posicion; //si es igual se escribe esto
											//sino sigue hasta encontrarlo o que 
	cout<<endl<<endl;						//finalice el archivo
	
	ifstream dato("datos.txt", ios::binary);
	
	bus=aux.posicion-1;
	
	dato.seekg(sizeof(struct estudiante)*bus, ios::beg);
	dato.read((char*) &auxi, sizeof(struct estudiante));
	
	cout<<"Carnet:  "<<auxi.carnet<<endl;
	cout<<"Nombre:  "<<auxi.nombre<<endl;
	cout<<"Edad:    "<<auxi.edad<<endl;
	cout<<"Carrera: "<<auxi.carrera<<endl;

	dato.close();
		
	system("PAUSE"); //solo detiene el programa un momento
	
	}//cerrar if comparacion	
		}//cierra while de final del archivo

	indic.close(); //se cierra el archivo para la busqueda
	
	break;	//se cierra el casa dos
		
case 3:
		
	bus=0;
	
	if(bus==0){
		
		ifstream eliminar("datos.txt", ios::binary);
		ifstream elim_ind("index.txt", ios::binary);
		ofstream temporal("temp.txt", ios::binary | ios::out);
		ofstream temp_ind("tempi.txt", ios::binary | ios::out);
		
	if(!eliminar || !elim_ind){
		
		cout<<"Error al abrir el archivo"<<endl;
	
	}else{
		
		cout<<"Ingrese el numero de carnet del alumno que desea borrar: ";
		cin>>opcion;
		
	while(!eliminar.eof()){
	
	eliminar.read((char*) &auxi, sizeof(struct estudiante));

	if(auxi.carnet==opcion){
		
		cout<<"El archivo se ha eliminado de datos"<<endl;
	
	}else{
		
	temporal.write((char*) &auxi, sizeof(struct estudiante));
	
	}
		}
		
	while(!elim_ind.eof()){
	
	elim_ind.read((char*) &aux, sizeof(struct index));

	if(aux.carnet==opcion){
		
		cout<<"El archivo se ha eliminado de indice"<<endl;
	
	}else{
		
	temp_ind.write((char*) &aux, sizeof(struct index));
	
	}
		}
			}
			
	eliminar.close();
	temporal.close();
	elim_ind.close();
	temp_ind.close();
	 
	 }
	 
	remove("datos.txt");
	remove("index.txt");
	rename("temp.txt", "datos.txt");
	rename("tempi.txt", "index.txt");
			
system("PAUSE"); break;

default: break;	//esto no hace nada por el momento
	
	}//cierra switch
		}//cierra if para entrar a switch
		
	} while(opcion>0 && opcion!=4); 
	
//la condicion del do while es que se va a repetir el menu mientras la variable opcion se mayor a cero(0)
//y tambien sea diferente de 4, en caso sea 0 o cuatro se sale del programa	
	
system("PAUSE"); 	

//y aqui finaliza el programa
}
