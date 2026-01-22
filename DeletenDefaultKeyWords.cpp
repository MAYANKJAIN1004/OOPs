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
};

int main(){
    Integer i;
    i.Show();
    Integer ii(20);
    ii.Show();
    //Integer iii(ii);// Integer(const Integer&) = delete;
    //iii.Show();
    return 0;
}