#include<iostream>
using namespace std;
int main()
{
    int i ;
    i = 5;
    int &a = i;
    cout << "value of i:" << i <<endl;
    cout << "value of a:" << a <<endl;
    cout << "address of i:" << &i <<endl;
    cout << "address of a:" << &a <<endl;
    return 0;
}
