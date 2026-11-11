#include"SensorPresion.h"

SensorPresion :: SensorPresion(int id,double lectura,std::string ubicacion,double umbral_p):Sensor(id,lectura,ubicacion)
{
    this->umbral = umbral_p;
}
double SensorPresion :: getUmbral(){
    return umbral;
}
void SensorPresion::procesarLectura(){
    std::cout << "[SENSOR PRESION]:" << *this << "\n";
    if(lectura > umbral){
         std::cout<<"-> !ALERTA: PRESION CRITICA¡ \n";
    }
}
SensorPresion :: ~SensorPresion(){
    std::cout << "Sensor Presion Eliminado" << std::endl;
}