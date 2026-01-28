#include <bits/stdc++.h>
using namespace std;

class car {
protected:
    const char* model;
    const char* make;

public:
    // Constructor
    car(const char* model, const char* make) : model(model), make(make) {}

    void startEngine() {
        cout << "Engine started..." << endl;
    }

    void stopEngine() {
        cout << "Engine stopped..." << endl;
    }

    void showDetails() {
        cout << "Make: " << make << ", Model: " << model << endl;
    }

    virtual ~car() {}
};

class ElectricCar : public car {
public:
    ElectricCar(const char* model, const char* make)
        : car(model, make) {}

    void batteryCharge() {
        cout << "Battery charging..." << endl;
    }
};

class GasCar : public car {
public:
    GasCar(const char* model, const char* make)
        : car(model, make) {}

    void fillGas() {
        cout << "Gas is filling..." << endl;
    }
};

int main() {
    // Base class pointers
    car* c1 = new ElectricCar("Model S", "Tesla");
    car* c2 = new GasCar("Civic", "Honda");

    cout << "Electric Car:" << endl;
    c1->showDetails();
    c1->startEngine();
    c1->stopEngine();  
    ElectricCar* e = dynamic_cast<ElectricCar*>(c1);
    if (e) e->batteryCharge();

    cout << "\nGas Car:" << endl;
    c2->showDetails();
    c2->startEngine();
    c2->stopEngine();
    GasCar* g = dynamic_cast<GasCar*>(c2);
    if (g) g->fillGas();

    delete c1;
    delete c2;

    return 0;
}
