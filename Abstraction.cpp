#include <bits/stdc++.h>
using namespace std;

// Abstract base class
class vehicle {
protected:
    string brand;

public:
    // Constructor
    vehicle(string brand) : brand(brand) {}

    // Abstract (pure virtual) method
    virtual void start() = 0;

    // Concrete method
    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }

    // Virtual destructor
    virtual ~vehicle() {}
};

// Derived class
class car : public vehicle {
public:
    // Constructor
    car(string brand) : vehicle(brand) {}

    // Overriding abstract method
    void start() override {
        cout << "Car is starting..." << endl;
    }
};

class bike : public vehicle {
public: 
    bike (string brand) : vehicle(brand) {}
    
    void start() override {
        cout << "Bike is starting..." << endl;
    }
};


int main() {
    // Pointer of base class pointing to derived class object
    vehicle* v1 = new car("Toyota");
    vehicle* v2 = new bike("Apache");

    v1->displayBrand();
    v1->start();
    
    v2->displayBrand();
    v2->start();

    delete v1, v2;
    return 0;
}
