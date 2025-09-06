//Memento Pattern - Provides a mechanism for capturing an object's internal state and restoring it to that state at a later time
//Useful when we need to implement features like undo/redo functionality or when we want to save and restore an object's state for various reasons.
#include <iostream>
#include <vector>
using namespace std;
class Originator {
    private:
    string state;
    public:
    void setState(const string newState){
        state = newState;
    }
    string getState() const {
        return state;
    }

    class Memento {
        private:
        string state;
        public:
        Memento(const string str) : state(str) {}
        string getSavedState() const {
            return state;
        }
    };

    Memento createMemento() const {
        return Memento(state);
    }
    void restoreState(const Memento &memento) {
        state = memento.getSavedState();
    }
};
class CareTaker {
    private:
    vector<Originator::Memento> mementoList;
    public:
    void addmemento(const Originator::Memento &memento) {
        mementoList.push_back(memento);
    }
    Originator::Memento getMementoAtIndex(const int index) {
        if(index >= 0 && index < mementoList.size()) {
            return mementoList[index];
        }
        throw out_of_range("Invalid Memento Index");
    }
};
int main() {
    Originator originator;
    CareTaker careTaker;

    originator.setState("State 1");
    originator.setState("State 2");
    careTaker.addmemento(originator.createMemento());
    originator.setState("State 3");
    originator.setState("State 4");
    careTaker.addmemento(originator.createMemento());

    originator.restoreState(careTaker.getMementoAtIndex(0));
    cout << "Current State : " << originator.getState() << endl;
    originator.restoreState(careTaker.getMementoAtIndex(1));
    cout << "Current State : " << originator.getState() << endl;
    return 0;
}