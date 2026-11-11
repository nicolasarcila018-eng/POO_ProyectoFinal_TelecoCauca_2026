#ifndef SENSOR_H
#define SENSOR_H 
//--------------------------//
#include<string>
#include <iostream>
//--------------------------//
class Sensor
{
protected:
   int id;
   double lectura;
   std::string ubicacion;
public:
    Sensor(int,double,std::string);
    int getid()const;
    double getLectura()const;
    std::string getUbic() const;
    virtual void procesarLectura() = 0;
    virtual~Sensor();
    friend std::ostream& operator<<(std::ostream& os, const Sensor& s){
        os <<"[ID|:" << s.id << "|lectura|:"<< s.lectura <<"|ubicacion|:" << s.ubicacion <<"]\n" ;
        return os;
    }
};


#endif