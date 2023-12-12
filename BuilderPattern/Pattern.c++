#include<vector>
#include<iostream>
using namespace std;

// Making Builder class
class Builder{
    public:
// Declaring pure virtual functions

      virtual ~Builder(){}
      virtual void ProducePartA() const = 0;
      virtual void ProducePartB() const = 0;
      virtual void ProducePartC() const = 0;

};

class Product1{
    public:
     vector<string> parts;
     void ListParts() const{
        cout << "Product parts :";
        for(size_t i=0;i<parts.size();i++){
            if(parts[i] == parts.back()){
                cout << parts[i];
            }else{
                cout << parts[i] << ", ";
            }
        }
        cout << "\n\n";
    }
};

/*
This Concrete Builder class inherit the Builder class and provide specific implementations of the building steps.
*/

class ConcreteBuilder1 : public Builder{
    Product1* product;

    public:
    ConcreteBuilder1(){
        this->Reset();
    }

    ~ConcreteBuilder1(){
        delete product;
    }

    void Reset(){
        this->product = new Product1();
    }

    // Production steps work with the same product instance.

    void ProducePartA() const override{
        this->product->parts.push_back("PartA1");
    }

    void ProducePartB() const override{
        this->product->parts.push_back("PartB1");
    }

    void ProducePartC() const override{
        this->product->parts.push_back("PartC1");
    }
    

    Product1* GetProduct(){
        Product1* result = this->product;
        this->Reset();
        return result;
    }
};

// Director class which is responsible to control all the constructors 

class Director{

    Builder* builder;

    public :
     
     void set_builder(Builder* builder){
        this->builder = builder;
    }
   
   /*
      The Director can construct several product variations using the same
      building steps.
    */

   void BuildMinimalProduct(){
    this->builder->ProducePartA();
   }

   void BuildFullFeatured(){
    this->builder->ProducePartA();
    this->builder->ProducePartB();
    this->builder->ProducePartC();
   }
};

/*
Creating builder builder object, passes it to director class and then initiates the construction process.
*/

void ClientCode(Director& director){
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.set_builder(builder);
    cout << "Standard Basic product\n";
    director.BuildMinimalProduct();

    Product1* p = builder->GetProduct();
    p->ListParts();
    delete p;

    cout << "Standard full featured product \n";
    director.BuildFullFeatured();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    // Builder pattern can be used without director class
    cout << "Custom product:\n";
    builder->ProducePartA();
    builder->ProducePartC();
    p=builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;

}

int main(){
    Director* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}





