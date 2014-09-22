/*
Boolean vectors are represented as boolean dynamic arrays

**L** - performed from left to right.
**R** - performed from right to left (leading zeros are ignored).
**B** - result is BoolVector object
**S** - length of the resulting object is same as length of shortest operand

class BoolVector:
	operators:
		'='  - assignment operator

		'~'  - bitwise negation (**B**)
		'&'  - bitwise AND (**BSL**)
		'|'  - bitwise OR (**BSL**)
		'^'  - bitwise XOR (**BSL**)
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
#include <math.h>

#include "BoolVector.h"

#define SIZE_OF_ARRAY 3

using namespace std;

//------------------------- GLOBAL FUNCTIONS -------------------
void showVector(BoolVector a)
{
    int n = a.getLength();

    cout << endl << "(";
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << ") : " << a.getLength() << endl;
}

BoolVector userFunction(BoolVector a, BoolVector b)
{
	return BoolVector(a | (~b));
}

int main()
{
    BoolVector arr_1[SIZE_OF_ARRAY], arr_2[SIZE_OF_ARRAY], arr_3[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arr_1[i] = BoolVector(5);
		arr_2[i] = BoolVector(4);
		arr_3[i] = userFunction(arr_1[i], arr_2[i]);
		showVector(arr_3[i]);
	}
    return 0;
}
