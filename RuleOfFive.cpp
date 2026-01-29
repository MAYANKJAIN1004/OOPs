#include<iostream>
using namespace std;

class Integer{
    int *m_int;
public:
    Integer(){
        m_int = new int(0);
        cout<<"InSide Integer()\n";
    }
    Integer(int value){
        m_int = new int(value);
        cout<<"InSide Integer(int i)\n";
    }
    Integer(Integer &ref){
        cout<<"InSide Integer(Integer &ref)\n";
        m_int = new int (*ref.m_int);
    }
    ~Integer(){
        delete m_int;
    }
    int GetValue(){
        cout<<"InSide GetValue()\n";
        return *m_int;
    }
    void SetValue(int value){
        cout<<"InSide SetValue(int value)\n";
        *m_int=value;
    }
    // Integer Add(Integer i1,Integer i2){
    //     cout<<"InSide Add(Integer i1,Integer i2)\n";
    //     return i1.GetValue() + i2.GetValue();
    // }
    Integer& operator=(Integer &i){
        cout<<"InSide operator=(Integer i)\n";
        *m_int = *i.m_int;
        return *this;
    }
};

int main(){
    cout<<"InSide Main!\n";

    Integer i1;
    cout<<"i1 : "<<i1.GetValue()<<endl<<endl;
    i1.SetValue(100);
    cout<<"i1 : "<<i1.GetValue()<<endl<<endl;

    Integer i2(50);
    cout<<"i2 : "<<i2.GetValue()<<endl;
    i2.SetValue(200);
    cout<<"i2 : "<<i2.GetValue()<<endl<<endl;

    Integer i3 = i2;
    cout<<"i3 : "<<i3.GetValue()<<endl<<endl;

    Integer i4(i1);
    cout<<"i4 : "<<i4.GetValue()<<endl<<endl;

    // Integer i5;
    // cout<<"i5 : "<<i5.GetValue()<<endl;
    // i5=(i4.Add(i3,i4));
    // cout<<"i5 : "<<i5.GetValue()<<endl<<endl;

    Integer i6;
    i6=i4;
    cout<<"i6 : "<<i6.GetValue()<<endl<<endl;
    i4.SetValue(30);
    cout<<"i6 : "<<i6.GetValue()<<endl<<endl;
    return 0;
}