#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
     map<char, string> m;
     m['a'] = "hi";
     m['b'] = "world";
     cout << m['a'] << " " << m['b'] << endl;
     if (m.find('c') != m.end()) cout << "m['c']" << endl;
     return 0;
}
