#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include"Sensor.h"
 class SensorTemperatura : public Sensor{
    private:
    double umbral;
    public:
    SensorTemperatura(int,double,std::string,double);
    double getUmbral();
    void procesarLectura()override;
    ~SensorTemperatura()override;
    

};
#endif 