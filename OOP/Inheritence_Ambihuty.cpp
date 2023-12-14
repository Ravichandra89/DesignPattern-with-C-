#include<iostream>
using namespace std;

class A{
    public :
     void Display(){
        cout << "Class A " << endl;
     }
};

class B{
    public:
      void Display(){
        cout << "Class B" << endl;
      }
};

class Derived : public A,public B{
    public:
     void show(){
        cout << "Inheritence Ambugity has removed!!" << endl;
     }
};

int main(){
    Derived d1;

    d1.A::Display();
    d1.B::Display();

    return 0;
}