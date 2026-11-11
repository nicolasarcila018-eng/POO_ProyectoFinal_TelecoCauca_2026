#ifndef SERVIDORES_SOCKETS_H
#define SERVICIOR_SOCKETS_H

#include<winsock2.h> 
#include<ws2tcpip.h>

#include<stdexcept>
#include<cstring>
#include<string>
#include<unistd.h>
#include<iostream>

class ServidorTCPEco{
    private:
    int puerto;
    SOCKET server_fd;

    public:
    explicit ServidorTCPEco(int );
    void iniciar();



};
#endif