#include<iostream>
using namespace std;

#include "ToyFactory.cpp"

int main(){
    int type;
    while(1){
        cout << endl << "Enter type or Zero for Exit"<< endl;
        cin >> type;
        if(!type)
            break;
        Toy *v = ToyFactory::createToy(type);
        if(v){
            v->showProduct();
            delete v;
        }
    }
    cout << "Exit.." << endl;
    return 0;
}

