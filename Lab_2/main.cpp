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

    cout << endl << n << " | " << a.getLength() << " | " << a.numOfOnes() << endl;

    //body show
    cout << endl << "Body: ";
    for (int i = 0; i < n; i++)
		cout << body[i] << " ";
	cout << endl;

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
			if (!(j % 8) && j)
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
	unsigned int init_1[1] = {3405677};
	unsigned int init_2[1] = {3450611};

    BoolVector arr_1[SIZE_OF_ARRAY], arr_2[SIZE_OF_ARRAY], arr_3[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arr_1[i] = BoolVector(1, init_1);
		arr_2[i] = BoolVector(1, init_2);
		arr_3[i] = userFunction(arr_1[i], arr_2[i]);
	}

	showVector(arr_1[0]);
	showVector(arr_2[0]);
	showVector(~ arr_2[0]);
	showVector(arr_3[0]);

    return 0;
}
