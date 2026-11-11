//nombre: Nicolas Arcila Campo

//Compilar en la terminal con ctrl + shift + b

// Para probar que el servidorTCP esta recibiendo informacion se compila este
// codigo y despues se abre una pestaña nueva de visual studio code para 
// abrir la carpeta cliente despues se compila y llegara un mesaje en termina 
// de este codigo y se finalizara el programa    

#include<iostream>


//==== encabezados ====//
#include "ListaEnlazada.h"
#include "SensorTemperatura.h"
#include "SensorPresion.h"
#include"SensorCaudal.h" 
#include "ServidorSockets.h"


using namespace std;

int main(){
   ListaGen<Sensor*> ListaPlanta;
 //insertar objetos//
   ListaPlanta.insertar( new SensorTemperatura(10,123.5,"Temperatura",128.5));
   ListaPlanta.insertar(new SensorCaudal(10,123.6,"Caudal",58.9));
   ListaPlanta.insertar(new SensorPresion(10,123.5,"flujo",48.7));
   
   ListaPlanta.procesartodo();

   ListaPlanta.~ListaGen();
   WSADATA wsaData;
   // inicializacion del servidor TCP
   if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0){
    std::cerr << "Error al iniciar Winsock";
    return 1;
   }
   try{
    ServidorTCPEco servidor(8080);
   
    servidor.iniciar(); 
   }
   catch(const std::exception& e){
    std::cerr << "ERROR" << e.what() << "\n";
   }

   WSACleanup();

   return 0;
}
