#include"Car.h"
#include<iostream>
using namespace std;

int Car::m_itotalcar = 0;//By default 0
Car::Car():Car(0){
    cout<<"InSide Car::Car()\n";
}
Car::Car(float fuel):Car(fuel,0){
    cout<<"InSide Car::Car(float fuel)"<<endl;
}
Car::Car(float fuel,int pass){
    cout<<"InSide Car::Car(float fuel,int pass)\n";
    m_ffuel=fuel;
    m_fspeed = 0.0;
    m_ipassenger = pass;
    m_itotalcar++;
}
Car::~Car(){
    cout<<"InSide Car::~Car()\n";
    m_itotalcar--;
}

void Car::FillFuel(float amount){
    m_ffuel = amount;
}
void Car::Accelerate(){
    m_fspeed++;
    m_ffuel -= 0.5f;
}
void Car::Break(){
    m_fspeed=0;
}
void Car::AddPassengers(int count){
    m_ipassenger=count;
}
void Car::DeshBoard() const{
    cout<<"Fuel : "<<m_ffuel<<endl;
    cout<<"Speed : "<<m_fspeed<<endl;
    cout<<"Passengers : "<<m_ipassenger<<endl;
}
void Car::ShowCount(){    
    cout<<"Total Cars : "<<m_itotalcar<<endl;
}