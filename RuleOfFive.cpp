#include<iostream>
using namespace std;

class Integer{
    int *m_pInt;
public:
    Integer(){
        cout<<"InSide Integer()\n";
        m_pInt = new int(0);        
    }
    Integer(int value){
        cout<<"InSide Integer(int i)\n";
        m_pInt = new int(value);        
    }
    Integer(const Integer &ref){
        cout<<"InSide Integer(Integer &ref)\n";
        m_pInt = new int (*ref.m_pInt);
    }
    Integer(Integer &&obj){
        cout<<"InSide Integer(Integer &&obj)\n";
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
    }
    ~Integer(){
        cout<<"InSide ~Integer()\n";
        delete m_pInt;
    }
    int GetValue()const{
        cout<<"InSide GetValue()\n";
        return *m_pInt;
    }
    void SetValue(int value){
        cout<<"InSide SetValue(int value)\n";
        *m_pInt=value;
    }
    Integer Add(const Integer &i1,const Integer &i2){
        cout<<"InSide Add(Integer &i1,Integer &i2)\n";
        Integer temp;
        temp.SetValue(i1.GetValue() + i2.GetValue());
        return temp;
    }
    Integer& operator=(Integer &i){
        cout<<"InSide operator=(Integer i)\n";
        *m_pInt = *i.m_pInt;
        return *this;
    }
};

int main(){
    cout<<"InSide Main!\n";

    Integer a(1),b(3);
    a.SetValue(a.Add(a,b).GetValue());
    cout<<"a : "<<a.GetValue()<<endl;

    // Integer i1;
    // cout<<"i1 : "<<i1.GetValue()<<endl<<endl;
    // i1.SetValue(100);
    // cout<<"i1 : "<<i1.GetValue()<<endl<<endl;

    // Integer i2(50);
    // cout<<"i2 : "<<i2.GetValue()<<endl;
    // i2.SetValue(200);
    // cout<<"i2 : "<<i2.GetValue()<<endl<<endl;

    // Integer i3 = i2;
    // cout<<"i3 : "<<i3.GetValue()<<endl<<endl;

    // Integer i4(i1);
    // cout<<"i4 : "<<i4.GetValue()<<endl<<endl;

    // // Integer i5;
    // // cout<<"i5 : "<<i5.GetValue()<<endl;
    // // i5=(i4.Add(i3,i4));
    // // cout<<"i5 : "<<i5.GetValue()<<endl<<endl;

    // Integer i6;
    // i6=i4;
    // cout<<"i6 : "<<i6.GetValue()<<endl<<endl;
    // i4.SetValue(30);
    // cout<<"i6 : "<<i6.GetValue()<<endl<<endl;
    return 0;
}