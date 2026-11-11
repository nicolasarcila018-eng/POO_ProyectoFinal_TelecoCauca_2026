#ifndef SENSOR_CAULDAL_H
#define SENSOR_CAUDAL_H

#include "Sensor.h"
class SensorCaudal : public Sensor
{
private:
    double umbral;
public:
    SensorCaudal(int,double,std::string,double);
    ~SensorCaudal()override;
    double getUmbral();
    void procesarLectura()override;
};

#endif