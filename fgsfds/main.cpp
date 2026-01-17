#include <iostream>
using namespace std;

class Transport {
protected:
    const char* fuelType;
    int speed;

public:
    Transport(const char* fuel, int sp)
        : fuelType(fuel), speed(sp) {
    }

    void setFuel(const char* fuel) {
        fuelType = fuel;
    }

    const char* getFuel() const {
        return fuelType;
    }

    virtual void info() const {
        cout << "Fuel: " << fuelType
            << ", Speed: " << speed << endl;
    }

    virtual ~Transport() {}
};

class Car : public Transport {
public:
    Car(const char* fuel, int sp)
        : Transport(fuel, sp) {
    }

    void info() const override {
        cout << "Car | ";
        Transport::info();
    }
};

class Ship : public Transport {
public:
    Ship(const char* fuel, int sp)
        : Transport(fuel, sp) {
    }

    void info() const override {
        cout << "Ship | ";
        Transport::info();
    }
};

class Plane : public Transport {
public:
    Plane(const char* fuel, int sp)
        : Transport(fuel, sp) {
    }

    void info() const override {
        cout << "Plane | ";
        Transport::info();
    }
};

class Motorcycle : public Transport {
public:
    Motorcycle(const char* fuel, int sp)
        : Transport(fuel, sp) {
    }

    void info() const override {
        cout << "Motorcycle | ";
        Transport::info();
    }
};

int main() {
    int choice;
    Transport* t = nullptr;

    cout << "Choose transport:\n";
    cout << "1 - Car\n";
    cout << "2 - Ship\n";
    cout << "3 - Plane\n";
    cout << "4 - Motorcycle\n";
    cin >> choice;

    int fuelChoice;
    cout << "Choose fuel:\n";
    cout << "1 - Petrol\n";
    cout << "2 - Diesel\n";
    cout << "3 - Electric\n";
    cin >> fuelChoice;

    const char* fuel;
    if (fuelChoice == 1) fuel = "Petrol";
    else if (fuelChoice == 2) fuel = "Diesel";
    else fuel = "Electric";

    int speed;
    cout << "Enter speed: ";
    cin >> speed;

    switch (choice) {
    case 1:
        t = new Car(fuel, speed);
        break;
    case 2:
        t = new Ship(fuel, speed);
        break;
    case 3:
        t = new Plane(fuel, speed);
        break;
    case 4:
        t = new Motorcycle(fuel, speed);
        break;
    default:
        cout << "Wrong choice\n";
        return 0;
    }

    cout << "\nTransport info:\n";
    t->info();

    delete t;
    return 0;
}
