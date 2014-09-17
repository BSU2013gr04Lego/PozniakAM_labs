/*
Boolean vectors are represented as boolean dynamic arrays

**L** - performed from left to right.
**R** - performed from right to left (leading zeros are ignored).
**B** - result is BoolVector object

class BoolVector:
	operators:
		'='  - assignment operator

		'~'  - bitwise negation (**B**)
		'&'  - bitwise AND (**BL**)
		'|'  - bitwise OR (**BL**)
		'^'  - bitwise XOR (**BL**)
		'!'  - logical negation
		'&&' - logical AND
		'||' - logical OR
		'==' - logical equality (**R**)
		'!=' - logical inequality (**R**)
		'>'  - logical greater than (**R**)
		'<'  - logical less than (**R**)
		'>=' - logical greater than or equal (**R**)
		'<=' - logical less than or equal (**R**)

	constructors:
		BoolVector();
		explicit BoolVector(int n);
		BoolVector(int n, bool arr[]);
		BoolVector(const BoolVector &obj);

	methods:
		private:
			void update(); - update n_ones field in object. It is important to use this method after every change of object.

		public:
			    BoolVector con(const BoolVector *a); - equal to bitwise AND
				BoolVector dis(const BoolVector *a); - equal to bitwise OR
				BoolVector neg();                    - equal to bitwise NOT
				int numOfOnes () const;				 - returns count of ones in object
				int numOfZeros () const;			 - returns count of zeros in object
				bool* getBody() const;				 - returns pointer on object's body-array
				int getLength() const;				 - returns length of object

*/

#include <iostream>
#include <conio.h>
#include <math.h>

#include "BoolVector.h"

#define SIZE_OF_ARRAY 3

using namespace std;

//------------------------- GLOBAL FUNCTIONS -------------------
void showVector(BoolVector a)
{
    unsigned int *body = a.getBody();
    int n = a.getBodyLength();

    cout << endl << n << " | " << a.getLength() << " | " << a.numOfOnes();

    //body show
    cout << endl << "Body: ";
    for (int i = 0; i < n; i++)
		cout << body[i] << " ";

	// Binary body show
    cout << endl << "(";
    for (int i = 0; i < n; i++)
    {
        unsigned int  temp = body[i];
        bool temp_arr[32];
        for (int i = 0; i < 32; i++)
			temp_arr[i] = 0;

        for (int j = 0; temp; j++)   // while (temp)
        {
            if (temp % 2)
                temp_arr[j] = 1;
            else
                temp_arr[j] = 0;
            temp /= 2;
        }

        for (int j = 31; j >= 0; j--)
        {
            if (temp_arr[j])
			{
				cout << "1";
			}
			else
			{
                cout << "0";
			}
			if (!(j % 8))
				cout << " ";
        }
	}
    cout << ") : " << a.getLength() << endl;
}

BoolVector userFunction(BoolVector a, BoolVector b)
{
	return BoolVector(a | (~b));
}

int main()
{
	bool init_1[4] = {1, 1, 1, 1};
	bool init_2[2] = {0, 1};
	bool init_3[3] = {1, 0, 0};

	BoolVector a(4, init_1);
	BoolVector b(2, init_2);
	BoolVector c(3, init_3);

	showVector(a);
	showVector(b);
	showVector(c);

	//  operator test
	/*  NOT
	cout << "-------- NOT --------------------" << endl;
	showVector(a);
	a = ~ a;
	showVector(a);
	*/
	/*  AND
	cout << "-------- AND --------------------" << endl;
	showVector(a);
	showVector(b);
	a = a & b;
	showVector(a);
	*/
	/*  OR
	cout << "-------- OR ---------------------" << endl;
	showVector(a);
	showVector(b);
	a = a | b;
	showVector(a);
	*/
	/*  XOR
	cout << "-------- XOR --------------------" << endl;
	showVector(a);
	showVector(b);
	a = a ^ b;
	showVector(a);
	*/

	// logical test
	/* logical test
    cout << !a << " " << !c << endl; // false true

    cout << (a && b) << " " << (a && c) << " "
		 << (c && b) << " " << (c && c) << endl; // true false false false

	cout << (a || b) << " " << (a || c) << " "
		 << (c || b) << " " << (c || c) << endl; // true true true false

	cout << (a == a) << " " << (a == b) << " " << (a == c) << " " << (c == c) << endl; // true false false true
	cout << (a != a) << " " << (a != b) << " " << (a != c) << " " << (c != c) << endl; // false true true false

	cout << (a > c) << " " << (a > a) << " " << (c > a) << endl; // true false false
	cout << (a >= c) << " " << (a >= a) << " " << (c >= a) << endl; // true true false
	cout << (a < c) << " " << (a < a) << " " << (c < a) << endl; // false false true
	cout << (a <= c) << " " << (a <= a) << " " << (c <= a) << endl; // false true true
	*/



	/*
    BoolVector arr_1[SIZE_OF_ARRAY], arr_2[SIZE_OF_ARRAY], arr_3[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arr_1[i] = BoolVector(2, init_1);
		arr_2[i] = BoolVector(2, init_2);
		arr_3[i] = userFunction(arr_1[i], arr_2[i]);
	}
	*/

	//showVector(arr_1[0]);
	//showVector(arr_2[0]);
	//showVector(~ arr_2[0]);
	//showVector(arr_3[0]);

    return 0;
}
