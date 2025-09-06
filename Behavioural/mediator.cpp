//Mediator - Defines an object, the mediator, to centralize communication between various components or objects
//Promotes loose coupling by preventing direct interactions between components, instead of having them communicate through the mediator
#include <iostream>
using namespace std;
class Airplane {
    public:
    virtual void requestTakeOff() = 0;
    virtual void requestLanding() = 0;
    virtual void notifyAirTraffiControl(const string& msg) = 0;
};
class AirTrafficControl {
    public:
    virtual void requestTakeOff(Airplane* airplane) = 0;
    virtual void requestLanding(Airplane* airplane) = 0;
};
class CommercialAirplane : public Airplane {
    private:
    AirTrafficControl* airTrafficControl_;
    public:
    CommercialAirplane(AirTrafficControl* airTrafficControl) : airTrafficControl_(airTrafficControl) {}
    void requestTakeOff() override {
        airTrafficControl_->requestTakeOff(this);
    }
    void requestLanding() override {
        airTrafficControl_->requestLanding(this);
    }
    void notifyAirTraffiControl(const string& msg) override {
        cout << "Commercial Airplane : " << msg << endl;
    }
};
class AirportTrafficControl : public AirTrafficControl {
    public:
    void requestTakeOff(Airplane* airplane) override {
        airplane->notifyAirTraffiControl("Requesting for Clearence");
    }
    void requestLanding(Airplane* airplane) override {
        airplane->notifyAirTraffiControl("Requesting for Landing");
    }
};
int main() {
    AirTrafficControl* airTrafficControl = new AirportTrafficControl();
    CommercialAirplane A(airTrafficControl);
    CommercialAirplane B(airTrafficControl);

    A.requestLanding();
    B.requestTakeOff();
    delete airTrafficControl;
    return 0;
}