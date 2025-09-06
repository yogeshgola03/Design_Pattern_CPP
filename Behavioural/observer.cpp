//The Observer Pattern - One object (Subject) holds the main data and
//Many other objects (Observers) want to be notified whenever that data changes
//One-to-Many relationship
#include <iostream>
#include <vector>
using namespace std;
class Observer {
    public:
    virtual void update(float temperature, float humidity) = 0;
};
class Display : public Observer {
    public:
    void update(float temperature, float humidity) override {
        cout << "Temp : " << temperature << " degree, Humidity : " << humidity << "%" << endl;
    }
};
class ObserverManager {
    public: 
    virtual void addObserver(Observer* obs) = 0;
    virtual void removeObserver(Observer* obs) = 0;
    virtual void notifyObserver() = 0;
};
class WeatherStation : public ObserverManager {
    private:
    vector<Observer*> observerList;
    float temperature_, humidity_;
    public:
    void addObserver(Observer* obs) override {
        observerList.push_back(obs);
    }
    void removeObserver(Observer* obs) override {
        for(int i=0; i<observerList.size(); i++) {
            if(observerList[i] == obs) {
                observerList.erase(observerList.begin() + i);
                break;
            }
        }
    }
    void notifyObserver() override {
        for(int i=0; i<observerList.size(); i++) {
            cout << "Observer " << observerList[i] << " ";
            observerList[i]->update(temperature_, humidity_);
        }
    }
    void setData(float temperature, float humidity) {
        temperature_ = temperature;
        humidity_ = humidity;
        notifyObserver();
    }
};
int main() {
    Observer* obs1 = new Display();
    Observer* obs2 = new Display();
    Observer* obs3 = new Display();
    WeatherStation weatherStation;
    weatherStation.addObserver(obs1);
    weatherStation.addObserver(obs2);
    weatherStation.addObserver(obs3);
    weatherStation.setData(25.5, 60.0);
    weatherStation.removeObserver(obs2);
    weatherStation.setData(24.0, 70.0);
    delete obs1;
    delete obs2;
    delete obs3;
    return 0;
}