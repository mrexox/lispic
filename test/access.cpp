#include <iostream>
using namespace std;


class A {
     int x;
public:

     A(int a) : x(a) {}
     int& get_x() { return x;}
};
int main() {
     
     A a(5);
     int& b = a.get_x();

     b = 16;
     cout << a.get_x();
     return 0;
}