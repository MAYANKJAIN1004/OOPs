#include<iostream>
using namespace std;

class Car{
    private:
        float m_ffuel;
        float m_fspeed;
        int m_ipassenger;
        static int m_itotalcar;
    public:
        Car();
        Car(float fule);
        Car(float fuel,int pass);
        ~Car();
        void FillFuel(float amount);
        void Accelerate();
        void Break();
        void AddPassengers(int count);
        void DeshBoard() const;
        static void ShowCount();
};