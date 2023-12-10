#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif

class Toy
{
protected:
    string name;
    float price;

public:
    // Virtual functions

    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;

};

// Class car inheriting class TOY
class Car : public Toy
{
public:
    void prepareParts()
    {
        cout << "Preparing Car Parts" << endl;
    }

    void combineParts()
    {
        cout << "Combining Car Parts" << endl;
    }

    void assembleParts()
    {
        cout << "Assembling Car Parts" << endl;
    }

    void applyLabel(){
        cout << "Applying Car Label " << endl;
        name = "Car";
        price = 15;
    }

    void showProduct()
    {
        cout << "Name: " << name << endl << "Price:" << price << endl;
    }
};

// Bike class
class Bike : public Toy{
     void prepareParts()
    {
        cout << " Preparing Bike Parts" << endl;
    }

    void combineParts()
    {
        cout << "Combining Bike Parts" << endl;
    }

    void assembleParts()
    {
        cout << "Assembling Bike Parts" << endl;
    }

    void applyLabel(){
        cout << "Applying Bike Label " << endl;
        name = "Bike";
        price = 20;
    }

    void showProduct()
    {
        cout << "Name: " << name << endl << "Price:" << price << endl;
    }
};

class Plane : public Toy{
    void prepareParts()
    {
        cout << " Preparing Plane Parts" << endl;
    }

    void combineParts()
    {
        cout << "Combining Plane Parts" << endl;
    }

    void assembleParts()
    {
        cout << "Assembling Plane Parts" << endl;
    }

    void applyLabel(){
        cout << "Applying Plane Label " << endl;
        name = "Plane";
        price = 50;
    }

    void showProduct()
    {
        cout << "Name: " << name << endl << "Price:" << price << endl;
    }
};