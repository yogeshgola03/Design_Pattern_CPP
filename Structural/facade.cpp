//Facade Pattern - simplified set of subsystems within a larger system
//Make easier to use and reducing the complexity of the system for clients
#include <iostream>
using namespace std;

//subsystem 1
class Engine {
    public:
    void start() {
        cout << "Engine Started\n";
    }
    void stop() {
        cout << "Engine Stopped\n";
    }
};

//subsystem 2
class Lights {
    public:
    void start() {
        cout << "Lights turned ON\n";
    }
    void stop() {
        cout << "Lights turned OFF\n";
    }
};

//facade
class Car {
    private:
    Engine engine_;
    Lights lights_;
    public:
    void start() {
        engine_.start();
        lights_.start();
        cout << "Car ready to Drive !!!\n";
    }
    void stop() {
        engine_.stop();
        lights_.stop();
        cout << "Car Stopped !!!\n";
    }
};

int main() {
    Car car;
    car.start();
    car.stop();
    return 0;
}