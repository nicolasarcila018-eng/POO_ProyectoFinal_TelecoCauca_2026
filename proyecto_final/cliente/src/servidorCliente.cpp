#include "servidorCliente.h"

ServidorCliente :: ServidorCliente(std::string ip ,int p): 
ip_servidor(ip),puerto(p),sock_fd(INVALID_SOCKET){ }

 void ServidorCliente:: enviarTrama(std::string mensaje){
    sock_fd = socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd == 0){
         throw std::runtime_error("error cliente: No pudo crear el socket");
     }
     sockaddr_in serv_addr{};
     std::memset(&serv_addr,0,sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_port = htons(puerto);
     //convertir direccion IP de forma texto a binario
     serv_addr.sin_addr.s_addr = inet_addr(ip_servidor.c_str());
     if(serv_addr.sin_addr.s_addr == INADDR_NONE && ip_servidor != "255.255.255.255"){
     closesocket(sock_fd);
     throw std::runtime_error("Error cliente: Direccion IP invalidad o no soportada");
     }
     //conectarse al servidor
     if(connect(sock_fd,reinterpret_cast<sockaddr*>(&serv_addr),sizeof(serv_addr))<0){
         closesocket(sock_fd);
         throw std:: runtime_error("Error Cliente:Fallo la conexion con el servidor en " + ip_servidor);
     }
     std::cout<<"[CLINTE SMTI] Conectado al servidor. Enviando Muestra..." << std::endl;
     //-----------//

     send(sock_fd, mensaje.c_str(),mensaje.length(),0); 

     char buffer[1024] = { 0 };
     ssize_t bytes = recv(sock_fd,buffer,sizeof(buffer ) -1,0);
     if(bytes > 0){
         std::cout << "[Respuesta Servidor]" << buffer << "\n";
     }
    close(sock_fd);




}