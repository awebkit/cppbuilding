#include "vehicle.h"

#include <iostream>

using namespace std;

class RoadVehicle : public Vehicle {
public:
    RoadVehicle(){}
    RoadVehicle(const RoadVehicle& rv){}
    virtual void start() {cout << "road vehicle start " <<endl;}
    virtual Vehicle* copy() const {return new RoadVehicle(*this);}
};

class AutoVehicle : public Vehicle {
public:
    AutoVehicle() {}
    AutoVehicle(const AutoVehicle& av) {}
    virtual void start() {cout << "auto vehicle start " <<endl;}
    virtual Vehicle* copy() const {return new AutoVehicle(*this);}
};

class AircraftVehicle : public Vehicle {
public:
    AircraftVehicle() {}
    AircraftVehicle(const AircraftVehicle& av) {}
    virtual void start() {cout << "air craft start " << endl;}
    virtual Vehicle* copy() const {return new AircraftVehicle(*this);}
};

class VehicleProxy {
public:
    VehicleProxy():vp(0){}
    VehicleProxy(const Vehicle& v):vp(v.copy()){}
    ~VehicleProxy(){delete vp;}

    VehicleProxy(const VehicleProxy& v):vp(v.vp?v.vp->copy(): 0){}

    VehicleProxy& operator=(const VehicleProxy& v){
        if (this != &v){
            delete vp;
            vp = (v.vp ? v.vp->copy() : 0);
        }
        return *this;
    }
    void start() {vp->start();}
private:
    Vehicle* vp;
};

int main()
{
    //error
    //Vehicle container[10];

    //ok
    //Vehicle* container[10];

    VehicleProxy container[10];
    AutoVehicle x;
    RoadVehicle y;
    AircraftVehicle z;
    container[0] = x;
    container[1] = y;
    container[2] = z;

    for (int i = 0; i < 3; ++i){
        container[i].start();
    }
    
    

    return 0;
}
