#include<iostream>
using namespace std;

class A{
   

public:
  int x;
    A() {
        x = 0;
    }

    A(int a){
        cout << "Constructor A(int a) is invoked" << endl;
        x = a;
    }
};

class B{
    int data;
    A objA;

public:
      B(int a) : objA(a){
        data = a;
    }

    void display(){
        cout <<"Data in object of class B = " << data << endl;
        cout <<"Data in member object of class A in classB = " << objA.x;
    }
};

int main(){
    B objB(23);

    objB.display();
    return 0;
}