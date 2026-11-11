#include"SensorCaudal.h"
SensorCaudal :: SensorCaudal(int id,double lectura,std::string ubicacion,double umbral_c): Sensor(id,lectura,ubicacion)
{
    this->umbral = umbral_c ;
}
double SensorCaudal :: getUmbral(){
    return umbral;
} 
void SensorCaudal ::procesarLectura(){
    std::cout <<"[SENSOR CAUDAL]:" << *this <<"\n";
    if(lectura > umbral){
         std::cout<<"-> !ALERTA: CAUDAL CRITICO¡ \n";
    }
}
SensorCaudal :: ~SensorCaudal(){
    std::cout << "Sensor caudal eliminado" << std::endl;
}
