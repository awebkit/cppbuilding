#ifndef vehicle_h
#define vehicle_h

class Vehicle {
public:
    virtual void start() = 0;
    virtual Vehicle* copy() const = 0;
};

#endif
