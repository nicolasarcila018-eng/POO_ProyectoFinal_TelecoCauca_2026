#include"ServidorSockets.h"

ServidorTCPEco :: ServidorTCPEco(int p):puerto(p),server_fd(INVALID_SOCKET){}

void ServidorTCPEco::iniciar(){
    //crear socket AF_NET
    server_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(server_fd == INVALID_SOCKET){
        throw std::runtime_error("Error Critico: No se pudo crear el socket del servido.");
    } 
    //Permitir reutilizar la direccion IP/Puerto de inmediato
    int opt = 1;
    if(setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR, reinterpret_cast<const char*>(&opt),sizeof(opt)) == SOCKET_ERROR){
        throw std::runtime_error("Error en setsockopt"+ std::to_string(WSAGetLastError()));
    }
    //2.Configuracion la estrucutra de dirrecion sockaddr_in
    sockaddr_in direccion{};
    direccion.sin_family = AF_INET;
    direccion.sin_addr.s_addr = INADDR_ANY; // escucha cualquier interfaz de red
    
    direccion.sin_port = htonl(INADDR_ANY);
    direccion.sin_port = htons(static_cast<unsigned short>(puerto));
    
    //3.vincular el socket con bind()
    if(bind(server_fd ,reinterpret_cast<sockaddr*>(&direccion), sizeof(direccion) ) == SOCKET_ERROR){
        throw std::runtime_error("Error critico: Fallo el bind en el puerto" + std::to_string(puerto));
    }
    //4.Habilitar modo de escucha pasiva con listen()
    if(listen(server_fd, 5) == SOCKET_ERROR){
        throw std::runtime_error("Error critico: Fallo la operacion listen." + std::to_string(WSAGetLastError()));
    }
    std::cout <<"[SEVIDOR SMTI] servido TCP listo y escuchando en el puerto" << puerto << "..."; 

    //5.Aceptar cliente entrante con accept()
    sockaddr_in cliente_addr{};
    int addr_len = sizeof(cliente_addr);
    SOCKET client_fd = accept(server_fd,reinterpret_cast<sockaddr*>(&cliente_addr),&addr_len);
    if(client_fd == INVALID_SOCKET){

        throw std::runtime_error("Error critico: No se pudo aceptar la conexion del cliente");
    }
    std::cout<<"[SERVIDO SMTI]Cliente conectado con exito."; 
    //6.lee mensaje del cliente
    char buffer[1024]{ };
    int byte_leidos = recv(client_fd,buffer,sizeof(buffer),0);
    if(byte_leidos == SOCKET_ERROR){
        int error = WSAGetLastError();
        closesocket(client_fd);
        throw std::runtime_error("Error en recv" + std::to_string(error));
    }
    if(byte_leidos == 0){
      std::cout << "[SMTI] El cliente cerro la conexion" << std::endl;
      closesocket(client_fd);
      return;
    }
        std::string mensaje(buffer,static_cast<size_t>(byte_leidos));
        std::cout<<"[MENSAJE RECIBIDO]"<< mensaje << std::endl;
        std::string respuesta = "ACK SMTI: Datos recibidos correctamente en el servidor.";
        size_t enviados = 0;
        
        while(enviados < respuesta.size()){
            int resultado = send(client_fd,respuesta.c_str() + enviados, static_cast<int>(respuesta.size() - enviados),0);
            if(resultado == SOCKET_ERROR || resultado == 0){
                int error = WSAGetLastError();
                closesocket(client_fd);
                throw std::runtime_error("Error en send"+std::to_string(error));
            }
            std::cout << "[SMTI] respuesta enviada correctamente" <<std::endl;
            closesocket(client_fd);
            std::cout<<"[SMTI] Conexion finalizada."<<std::endl;
        }
    }
    //7.Cierre limpio de sockets
  
    
