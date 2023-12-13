#include<iostream>
using namespace std;

// Encapsulating public class

class Rectangle{
    public:
      
      int length;
      int breadth;

      // Constructor to initilize variables

      Rectangle(int len,int bre) : length(len) , breadth(bre){}

      int GetArea(){
        return length*breadth;
      }
     
};

// Encapsulating Private class
class PrivateClass{
    private:
     int age;
    
    public:
     void Setter(int age){
        this->age = age;
     }

    int Getter(){
        return age;
    }
};

class P_Rectangle{
  /*
     Data Hiding Using the Private Specifier
  */

 private:
  int length;
  int breadth;

  public:
   
   // Setter function
   void SetLength(int length){
    this->length = length;
   }

   void SetBreadth(int breadth){
    this->breadth = breadth;
   }

   // Getter function 
   int GetLength(){
    return length;
   }

   int GetBreadth(){
    return breadth;
   }

   // Area found function 
   int GetArea(){
    return length * breadth;
   }

};



int main(){
    Rectangle rect(8,6);

    cout << "Area = "<< rect.GetArea() << endl;

    // Making object of PrivateClass

    PrivateClass p;
    p.Setter(10);

    int result = p.Getter();

    cout << "Age is : " << result << endl;

    // Object for P_Rectangle class

    P_Rectangle pr;

    pr.SetLength(10);
    pr.SetBreadth(5);

    cout << "\nLength = " << pr.GetLength() << endl;
    cout << "Breadth = " << pr.GetBreadth() << endl;

    cout << "Area = " << pr.GetArea() << endl;
}