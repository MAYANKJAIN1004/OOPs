#include<iostream>
using namespace std;

class Integer{
    int m_value{10};
public:
    Integer() = default;
    Integer(int num){
        m_value = num;
    }
    void Show(){
        cout<<m_value<<endl;
    }
    Integer(const Integer&) = delete;
    Integer* operator&() = delete;
    // Integer* operator &() {
    //     cout<<"InSide operator &()\n";
    //     return this;
    // }
};

int main(){
    Integer i;
    i.Show();
    Integer ii(20);
    ii.Show();
    //Integer iii(ii);// Integer(const Integer&) = delete;
    //iii.Show();

    // Integer I1;
    // Integer *Iptr = &I1;

    // cout<<Iptr<<"\n";
    // cout<<&I1<<endl;
    return 0;
}