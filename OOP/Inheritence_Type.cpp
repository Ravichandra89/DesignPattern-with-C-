#include<iostream>
using namespace std;

class Single{
    public :
     int age;
    
    void SetAge(int age){
        this->age = age;
    }

    int GetAge(){
        return age;
    }
};

// Inheriting Single class into it's Derived class

class Single_Derived : public Single{
    public:
    void Display(){
        cout << "Single Inheritence is achived!! "<< endl;
    }
};

// Multilevel inheritence

class MultiLevel{
    protected:
     string name = "Ravi";
    
    public:
      void show(){
        cout << "Name is : " << name ;
      }
};

class MultiLevel_Derived : public MultiLevel{
    public:
      protected:
        string last_name = "Chandra";
    
    public:
       void Dis(){
        cout << last_name << endl;
       }
};

class New : public MultiLevel_Derived{
    public :
      void Success(){
        cout << "Multilevel Inheritence correct" << endl;
      }
};



int main(){
    // Making Single class object

    Single_Derived sd;

    sd.SetAge(20);
    sd.GetAge();
    sd.Display();

    // Making Multilevel Object

    New nd;

    nd.show();
    nd.Dis();
    nd.Success();
}