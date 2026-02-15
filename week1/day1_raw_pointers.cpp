#include <iostream>
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

void buggyFunction() {
    // BAD: Raw pointer - easy to forget delete!
    Sensor* encoder = new Sensor("Encoder-1");
    encoder->read();
    
    // OOPS: What if function returns early?
    if (true) {
        std::cout << "⚠ Early return - memory leak!" << std::endl;
        return;  // MEMORY LEAK - forgot delete!
    }
    
    delete encoder;  // Never reached!
}

int main() {
    std::cout << "=== PROBLEMA RAW POINTERS ===" << std::endl;
    buggyFunction();
    std::cout << "\n⚠ Sensor never destroyed - MEMORY LEAK!" << std::endl;
    
    return 0;
}