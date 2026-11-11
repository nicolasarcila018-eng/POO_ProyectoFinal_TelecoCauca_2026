#ifndef SENSOR_PRESION_H
#define SENSOR_PRESION_H

#include "Sensor.h"
class SensorPresion: public Sensor
{
private:
double umbral;
public:
    SensorPresion(int,double,std::string,double);
    ~SensorPresion()override;
    double getUmbral();
    void procesarLectura()override;
};


#endif
