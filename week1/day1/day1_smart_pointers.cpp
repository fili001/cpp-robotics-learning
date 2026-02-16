#include <iostream>
#include <memory>
#include <string>

class Sensor {
private:
    std::string name;
public:
    Sensor(std::string n) : name(n) {
        std::cout << "✓ Sensor '" << name << "' created" << std::endl;
    }
    
    ~Sensor() {
        std::cout << "✗ Sensor '" << name << "' destroyed" << std::endl;
    }
    
    void read() {
        std::cout << "→ Reading from " << name << std::endl;
    }
};

void goodFunction() {
    // GOOD: Smart pointer - automatic cleanup!
    auto encoder = std::make_unique<Sensor>("Encoder-1");
    encoder->read();
    
    // Even with early return, memory is cleaned up!
    if (true) {
        std::cout << "✓ Early return - but smart pointer cleans up!" << std::endl;
        return;  // NO LEAK - unique_ptr destructor runs automatically!
    }
    
    // No delete needed!
}

void ownershipTransfer() {
    std::cout << "\n=== OWNERSHIP TRANSFER ===" << std::endl;
    
    auto sensor1 = std::make_unique<Sensor>("Sensor-A");
    sensor1->read();
    
    // Transfer ownership with std::move
    auto sensor2 = std::move(sensor1);
    
    // sensor1 is now nullptr!
    if (!sensor1) {
        std::cout << "✓ sensor1 is now nullptr after move" << std::endl;
    }
    
    sensor2->read();
    std::cout << "✓ sensor2 owns the Sensor now" << std::endl;
    
    // sensor2 will be destroyed automatically at end of function
}

int main() {
    std::cout << "=== SMART POINTERS (unique_ptr) ===" << std::endl;
    goodFunction();
    
    std::cout << "\n✓ Memory cleaned up automatically!\n" << std::endl;
    
    ownershipTransfer();
    
    std::cout << "\n=== END OF PROGRAM ===" << std::endl;
    
    return 0;
}