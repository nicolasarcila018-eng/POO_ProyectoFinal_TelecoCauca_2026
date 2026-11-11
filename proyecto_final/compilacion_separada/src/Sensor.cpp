#include "Sensor.h"

Sensor :: Sensor(int id ,double lectura,std::string ubi){
    this->id = id;
    this->lectura = lectura;
    this->ubicacion = ubi;
} 

int Sensor :: getid()const{
    return id;
}
double Sensor :: getLectura()const {
    return lectura;
}
std::string Sensor :: getUbic()const{
    return ubicacion;
}
Sensor ::~Sensor(){
    std::cout << "[DESTRUCTOR] ID:" << id << "|UBICACION|:"<< ubicacion <<"\n";
}