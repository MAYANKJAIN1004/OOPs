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
    Integer operator+(const Integer &i){
        Integer temp;
        *temp.m_pInt=*m_pInt+*i.m_pInt;
        return temp;
    }
    Integer& opeartor++(){
        ++(*m_pInt);
        return *this;
    } 
};

int main(){
    cout<<"InSide Main!\n";

    Integer a(1),b(3);
    Integer c = a+b;
    ++c;
    cout<<"C : "<<c.GetValue()<<endl;
    return 0;
}