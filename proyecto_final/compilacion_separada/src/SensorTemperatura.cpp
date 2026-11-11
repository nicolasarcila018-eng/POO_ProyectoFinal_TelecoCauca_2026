#include"SensorTemperatura.h"

SensorTemperatura :: SensorTemperatura(int id,double lectura, std::string ubicacion,double umbral_t): Sensor(id,lectura,ubicacion)
{
this->umbral = umbral_t;
}
double SensorTemperatura ::getUmbral(){
    return umbral;
}
void SensorTemperatura :: procesarLectura(){
    std::cout <<"[SENSOR TEMPERATURA]:" << *this << "\n";
    if(lectura> umbral){
        std::cout<<"-> !ALERTA: SOBRETEMPERATURA CRITICA¡ \n";
    }
}
SensorTemperatura :: ~SensorTemperatura(){
    std::cout << "Sensor temperatura eliminado" << std::endl;
}