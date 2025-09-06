//State - allowing an object to alter its behavior every time its internal state changes
//Encapsulates each state in a separate class, which makes it easier to add new states and modify existing states without altering the object's code directly
//This pattern is useful when an object transitions between different states, with each transition triggering specific actions
#include<iostream>
using namespace std;
class TrafficLightState {
    public:
    virtual void handle() = 0;
};
class RedLight : public TrafficLightState {
    public:
    void handle() override {
        cout << "Traffic Light Changed to Red" << endl;
    }
};
class YellowLight : public TrafficLightState {
    public:
    void handle() override {
        cout << "Traffic Light Changed to Yellow" << endl;
    }
};
class GreenLight : public TrafficLightState {
    public:
    void handle() override {
        cout << "Traffic Light Changed to Green" << endl;
    }
};
class TrafficLight {
    private:
    TrafficLightState* state_;
    public:
    TrafficLight() : state_(new YellowLight()) {}
    void setState(TrafficLightState* newState) {
        delete state_;
        state_ = newState;
        state_->handle();
    }
    ~TrafficLight() {
        delete state_;
    }
};
int main() {
    TrafficLight trafficLight;
    trafficLight.setState(new RedLight());
    trafficLight.setState(new YellowLight());
    trafficLight.setState(new GreenLight());
    return 0;
}