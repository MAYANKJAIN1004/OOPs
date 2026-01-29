#include<iostream>
using namespace std;

class Mul{
    int val;
public:
    Mul():val{0}{}
    Mul(int i):val{i}{cout<<"InSide Mul(int i)\n";}
    int operator()(int i){
        cout<<"InSide operator()\n";
        return val*i;
    }
};
int main(){
    Mul M1(10);
    cout<<M1(2)<<endl;
    return 0;
}