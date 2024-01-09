#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int mileage;
    double price;

public:
    Vehicle(int mil, double p) : mileage(mil), price(p) {}

    ~Vehicle() {
        cout << "Destructor of Vehicle Class" << endl;
    }

    void displayVehicle() {
        cout << "Mileage: " << mileage << endl;
        cout << "Price: " << price << endl;
    }
};

class Car : public Vehicle {
protected:
    double ownership_cost;
    int warranty, capacity;
    string fuel_type;

public:
    Car(int mil, double p, double own_cost, int w, int cap, string fuel) : Vehicle(mil, p),
                                                                           ownership_cost(own_cost),
                                                                           warranty(w),
                                                                           capacity(cap),
                                                                           fuel_type(fuel) {}

    ~Car() {
        cout << "Destructor of car class" << endl;
    }

    void displayCar() {
        displayVehicle(); // Using the base class display function
        cout << "Ownership cost of the car: " << ownership_cost << endl;
        cout << "Warranty of the car: " << warranty << endl;
        cout << "Seating capacity of the car: " << capacity << endl;
        cout << "Fuel Type of the car: " << fuel_type << endl;
    }
};

class Bike : public Vehicle {
protected:
    int num_cylinders, num_gears;
    string cooling_type, wheel_type;
    float tank_size;

public:
    Bike(int mil, double p, int cylinders, int gears, string cool_type, string w_type, float tankS) : Vehicle(mil, p),
                                                                                                      num_cylinders(cylinders),
                                                                                                      num_gears(gears),
                                                                                                      cooling_type(cool_type),
                                                                                                      wheel_type(w_type),
                                                                                                      tank_size(tankS) {}

    ~Bike() {
        cout << "Bike destructor" << endl;
    }

    void displayBike() {
        displayVehicle(); // Using the base class display function
        cout << "Number of Cylinders of the bike: " << num_cylinders << endl;
        cout << "Number of gears of the bike: " << num_gears << endl;
        cout << "Wheel Type: " << wheel_type << endl;
        cout << "Tank Size: " << tank_size << endl;
    }
};

class Audi : public Car {
protected:
    string model_type;

public:
    Audi(int mil, double p, double own_cost, int w, int cap, string fuel, string model)
        : Car(mil, p, own_cost, w, cap, fuel), model_type(model) {}

    ~Audi() {
        cout << "Destructor of Audi" << endl;
    }

    void displayAudi() {
        displayCar(); // Using the base class display function
        cout << "Model type of Audi: " << model_type << endl;
    }
};

class Ford : public Car {
protected:
    string modelType;

public:
    Ford(int mil, double p, double own_cost, int w, int cap, string fuel, string m)
        : Car(mil, p, own_cost, w, cap, fuel), modelType(m) {}

    ~Ford() {
        cout << "Destructor of Ford" << endl;
    }

    void displayFord() {
        displayCar(); // Using the base class display function
        cout << "Model of Ford: " << modelType << endl;
    }
};

class Bajaj : public Bike {
protected:
    string model_type;

public:
    Bajaj(int mil, double p, int cylinders, int gears, string cool_type, string w_type, float tankS, string mType)
        : Bike(mil, p, cylinders, gears, cool_type, w_type, tankS), model_type(mType) {}

    ~Bajaj() {
        cout << "Bajaj Destructor" << endl;
    }

    void displayBajaj() {
        displayBike(); // Using the base class display function
        cout << "Model Type of Bajaj: " << model_type << endl;
    }
};

class TVS : public Bike {
protected:
    string model_Type;

public:
    TVS(int mil, double p, int cylinders, int gears, string cool_type, string w_type, float tankS, string type_m)
        : Bike(mil, p, cylinders, gears, cool_type, w_type, tankS), model_Type(type_m) {}

    ~TVS() {
        cout << "TVS Destructor" << endl;
    }

    void displayTVS() {
        displayBike(); // Using the base class display function
        cout << "Model Type of TVS: " << model_Type << endl;
    }
};

int main() {
    Ford f(2, 2000.000, 5, 3,56, "diesel", "fghj");
    f.displayFord();

    Audi a(3, 3000.000,8.7, 3, 4, "petrol", "cbjk");
    a.displayAudi();

    Bajaj b(2, 500.00, 1, 1, "air", "spooky", 2.0, "pijn");
    b.displayBajaj();

    TVS t(2, 45.555, 1, 1, "air", "plain", 2.9, "djfjs");
    t.displayTVS();

    return 0;
}
