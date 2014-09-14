/*
Boolean vectors are represented as boolean dynamic arrays

!!! All bitwise operations are performed from left to right.
!!! The result of the binary operators is a boolean vector of length of the smaller of the operands
*/
#include <iostream>
#include <conio.h>
#include <math.h>

#include "BoolVector.h"

using namespace std;

//------------------------- GLOBAL FUNCTIONS -------------------
void showVector(BoolVector a)
{
    bool *body = a.getBody();
    int n = a.getLength();

    cout << endl << "Boolean Vector of length: " << n << endl << "(";
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            if (body[i])
            {
                cout << "1, ";
            }
            else
            {
                cout << "0, ";
            }
        }
        else
        {
            if (body[i])
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
    }
    cout << ")" << endl;
}

int main()
{
    BoolVector f(5);
    BoolVector g(3);
    bool c = f > g;
	cout << c << endl;
    g = g.neg();
    f = f.neg();
    c = g > f;
	cout << c << endl;
    //g = g.con(&f);
    g = g + f;
    showVector(f);
    cout << endl << f.numOfOnes() << " " << f.numOfZeros() << endl;
    showVector(g);
    cout << endl << f.numOfOnes() << " " << f.numOfZeros() << endl;
    return 0;
}
