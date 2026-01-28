#include <bits/stdc++.h>
using namespace std;


class calculator {
public:
    int add (int a, int b) {
        return a+b;        
    }
    
    float add(float a, float b) {
        return a+b;
    }
    
    int add(int a, int b, int c) {
        return a+b+c;
    }
};

int main() {
    calculator calc;   

    cout << "Add 2 ints: " << calc.add(5, 6) << endl;
    cout << "Add 2 floats: " << calc.add(2.5f, 3.7f) << endl;
    cout << "Add 3 ints: " << calc.add(1, 2, 3) << endl;

    return 0;
}
