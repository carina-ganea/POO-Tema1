#include <iostream>
#include "Clasa-Polinom.h"

using namespace std;
using namespace clsPolinom;

int main()
{
    Polinom A, B, T;
    cin >> A >> B;
    while(!B)
    {
        T = A % B;
        A = B;
        B = T;
    }
    cout << A ;
    return 0;
}