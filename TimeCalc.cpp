#include <iostream>
using namespace std;

class Time
{
    int hr;
    int min;
    int sec;

    public:
        Time()
        {
            hr = 0;
            min = 0;
            sec = 0;
        }

        void setTime(int h, int m, int s)
        {
            hr = h;
            min = m;
            sec = s;
        }

        void displayTime()
        {
            //normalizeTime();
            cout<<hr<<":"<<min<<":"<<sec<<endl;
        }
        
        void normalizeTime()
        {
            if(sec>=60)
            {
                min = min + sec/60;
                sec = sec%60;
            }
            if(min>=60)
            {
                hr = hr + min/60;
                min = min%60;
            }
        }

        Time addTime(Time);
        Time operator+(Time);
};

Time Time::addTime(Time t)
{
    Time tmp;
    tmp.sec = sec + t.sec;
    tmp.min = min + t.min;
    tmp.hr = hr + t.hr;
    tmp.normalizeTime();
    return tmp;
}

Time Time::operator+(Time t)
{
    Time tmp;
    tmp.sec = sec + t.sec;
    tmp.min = min + t.min;
    tmp.hr = hr + t.hr;
    tmp.normalizeTime();
    return tmp;
}

int main ()
{

    Time t1,t2,t3,t4,t5;
    cout<<"Print T1 : ";
    t1.setTime(07,75,20);
    t1.displayTime();
    cout<<"Print T2 : ";
    t2.setTime(05,30,85);
    t2.displayTime();  
    cout<<"Print T3 : ";
    t3 = t1.addTime(t2);
    t3.displayTime();
    cout<<"Print T4 : ";
    t4 = t3 + t2;
    t4.displayTime();
    cout<<"Print T5 : ";
    t5 = t3.operator+(t4);
    t5.displayTime();
    return 0;
}