#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "I can eat!" << endl;
    }

    void sleep()
    {
        cout << "I can sleep" << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "I can  bark!" << endl;
    }
};

// Private and Protected Access modifier

class P_Animal{
    private:
        string color;
        string Which_Animal;
    
    protected:
        string type;
    
    public:
       void eat(){
        cout << "I can eat"<<endl;
       }
       void SetAnimal(string animal){
        Which_Animal = animal;
       }
       void sleep(){
        cout<<"I can sleep"<<endl;
       }
       void setColor(string color){
        this->color = color;
       }
       string getColor(){
        return color;
       }
};

// Inheriting class 

class P_Dog : public P_Animal{
    string animal;
    public:
        
        void SetType(string animal){
            this->animal = animal;
        }

        void Display(string col){
            cout << "I am a " << animal << endl;
            cout << "My color is " <<col<<endl;
        }
};

int main()
{
    // Creating object of Dog
    Dog d1;

    d1.eat();
    d1.sleep();
    d1.bark();

    // object of the Protected class

    P_Dog pd;
    pd.eat();
    pd.sleep();
    pd.setColor("Red");
    pd.SetType("Cat");
    pd.getColor();
    pd.Display("Green");
}