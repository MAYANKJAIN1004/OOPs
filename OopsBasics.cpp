#include<iostream>
#include"Car.h"
using namespace std;

int main(){
    cout<<"InSide Main!\n";
    Car::ShowCount();
    Car c(4.0f);
    //c.FillFuel(6);
    // c.Accelerate();
    // c.Accelerate();    
    // c.DeshBoard();

    Car c1,c2(3.0f,4);
    c.DeshBoard();
    c1.DeshBoard();
    c2.DeshBoard();
    return 0;
}