//complilar con Crtl + shitf + b

#include<iostream>



//==== encabezados ====//

#include "servidorCliente.h"

using namespace std;

int main(){
   ListaGen<Sensor*> ListaPlanta;
   //crear objeto vector//
   
  //=================//
   
   // estructura de iniciazicion de servidor
   WSADATA wsaData;
   // inicializacion del servidor TCP
   if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0){
    std::cerr << "Error al iniciar Winsock";
    return 1;
   }
   try{
    ServidorCliente cliente("127.0.0.1",8080);
    cliente.enviarTrama("hola Servidor");

   }
   catch(const std::exception& e){
    std::cerr << "ERROR" << e.what() << "\n";
   }
   

   WSACleanup();

  
    return 0;
}