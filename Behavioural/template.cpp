//Template - introduces a template in a superclass that defines the steps of an algorithm
//These steps may include both common tasks shared among subclasses and specific tasks that need customization
//Subclasses then implement or override these steps to modify the algorithm according to their specific needs
#include<iostream>
using namespace std;
class VehicleTemplate {
    public:
    void buildVehicle() {
        assembleBody();
        installEngine();
        addWheels();
        cout << "Vehicle is Ready !!!" << endl;
    }
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;
};
class MotorCycle : public VehicleTemplate {
    public:
    void assembleBody() override {
        cout << "Assembling the MotorCycle Body ..." << endl;
    }
    void installEngine() override {
        cout << "Installing the MotorCycle Engine ..." << endl;
    }
    void addWheels() override {
        cout << "Adding the MotorCycle Wheels ..." << endl;
    }
};
class Car : public VehicleTemplate {
    public:
    void assembleBody() override {
        cout << "Assembling the Car Body ..." << endl;
    }
    void installEngine() override {
        cout << "Installing the Car Engine ..." << endl;
    }
    void addWheels() override {
        cout << "Adding the Car Wheels ..." << endl;
    }
};
int main() {
    Car car;
    cout << "Building the Car -" << endl;
    car.buildVehicle();
    MotorCycle motorCycle;
    cout << "Building the MotorCycle -" << endl;
    motorCycle.buildVehicle();
    return 0;
}