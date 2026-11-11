#ifndef SEVIDOR_CLIENTE_H
#define SEVIDOR_CLIENTE_H

#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include <vector>

class ServidorCliente{
    private:
    std::string ip_servidor;
    int puerto;
    SOCKET sock_fd;

    public:
    ServidorCliente(std::string,int);
    void enviarTrama(std::string);
   

};

#endif
