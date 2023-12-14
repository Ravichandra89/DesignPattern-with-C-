#include<iostream>
using namespace std;

// Operator Overloading Compile Time polymorphism
class B{
    public:
      int a,b;
    
    public:
      void operator+ (B obj){
        // Making a current object
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Output is : "<<value1 - value2<<endl;

     cout << "Hy there! I am Ravi Chandra" << endl;
      }
};

// Function Overloading 
class C{
    
    public:

      void add(int a,int b=1){
        cout << "\nFUNCTION OVERLOADING EXAMPLE" << endl;
        cout <<"Output is : " << a+b << endl;
      }
      void add(double a,double b){
        cout << "Output is : " << a+b << endl;
      }
      void add(string str1,string str2){
        cout << "output is: " << str1+str2 << endl;
      }
};

int main(){
    B obj1,obj2;

    obj1.a = 10;
    obj2.a = 1;

    obj1 + obj2;

    // Making object of Function Overloading class 

    C c1;
    c1.add(10);
    c1.add(10.23,10.23);
    c1.add("Ravi","Chandra");

}