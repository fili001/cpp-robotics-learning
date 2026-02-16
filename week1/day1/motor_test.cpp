#include <iostream>
#include <memory>
#include <string>

class Motor {
private:
    std::string name;
    int id;
public:
    Motor(std::string n, int l) : name(n), id(l) {
        std::cout << "✓ Sensor '" << name <<"id:"<<id<< "created" << std::endl;
    }
    
    ~Motor() {
        std::cout << "✓ Sensor " << name <<"id:"<<id<< "stopped" << std::endl;    }
    
    void start() {
        std::cout << "motor " << name<<"starting" << std::endl;
    }
};



int main() {
    auto motor1 = std::make_unique<Motor>("LeftWheel",1);
    auto motor2 = std::make_unique<Motor>("RightWheel",2);
    motor1->start();
    motor2->start();

    auto motor3 = std::move(motor1);
    if(!motor1)
    {
        std::cout <<"motor1 null" << std::endl;
    }

    return 0;
}