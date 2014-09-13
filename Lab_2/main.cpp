/*
Ѕулевые векторы представл€ютс€ в виде булевых динамических массивов

!!! ¬се побитовые операции выполн€ютс€ слева на право.
!!! –езультатом бинарных побитовых операций €вл€етс€ булевый вектор длинны наименьшего из операндов
*/
#include <iostream>
#include <conio.h>
#include <math.h>

#define DEFAULT_SIZE 5

using namespace std;

class BoolVector
{
    int n;      // Vector's length
    bool *body; // Vector's body
public:
    BoolVector();
    BoolVector(int n);
    BoolVector(int n, bool arr[]);
    BoolVector(const BoolVector &obj);

    BoolVector con(BoolVector a, BoolVector b); // Conjuction
    BoolVector dis(BoolVector a, BoolVector b); // Disjunction
    BoolVector neg(BoolVector a);               // Negation
    int numOfOnes ();
    int numOfZeros ();
    bool* getBody();
    int getLength();

    ~BoolVector();
};

//---------------------- CONSTRUCTORS ------------------------------
BoolVector::BoolVector()
//	:	body(nullptr)
{
	n = DEFAULT_SIZE;
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = 0;
		}
	}
}

BoolVector::BoolVector(int n)
	:	n(n)
//		,body(nullptr)
{
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = 0;
		}
	}
}

BoolVector::BoolVector(int n, bool arr[])
	:	n(n)
//		,body(nullptr)
{
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = arr[i];
		}
	}
}

BoolVector::BoolVector(const BoolVector &obj)
//	:body(nullptr)
{
	n = obj.n;
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = obj.body[i];
		}
	}
}

//------------------------- METHODS ----------------------------
BoolVector BoolVector::con(BoolVector a, BoolVector b)
{
	BoolVector ans(max(a.n, b.n));
	for (int i = 1; i < min(a.n, b.n); i++) {
		ans.body[i] = a.body[i] & b.body[i];
	}
	return ans;
}

BoolVector BoolVector::dis(BoolVector a, BoolVector b)
{
	BoolVector ans(max(a.n, b.n));
	for (int i = 1; i < min(a.n, b.n); i++) {
		ans.body[i] = a.body[i] | b.body[i];
	}
	return ans;
}

BoolVector BoolVector::neg(BoolVector a)
{
	BoolVector ans(a.n);
	for (int i = 1; i < a.n; i++) {
		ans.body[i] = ~a.body[i];
	}
	return ans;
}

int BoolVector::numOfOnes()
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += body[i];
	}
	return ans;
}

int BoolVector::numOfZeros()
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += body[i];
	}
	return n - ans;
}

//------------------------- SET/GET METHODS --------------------
bool* BoolVector::getBody()
{
	return body;
}

int BoolVector::getLength()
{
	return n;
}

//------------------------- DESTRUCTOR -------------------------
BoolVector::~BoolVector()
{
	delete[] body;
}

//------------------------- GLOBAL FUNCTIONS -------------------
void showVector(BoolVector a)
{
	bool *body = a.getBody();
	int n = a.getLength();

	cout << endl << "Ѕулевый вектор длинны: " << n << endl << "(";
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			if (body[i])
			{
				cout << "1, ";
			} else
			{
				cout << "0, ";
			}
		} else
		{
			if (body[i])
			{
				cout << "1)" << endl;
			} else
			{
				cout << "0)" << endl;
			}
		}
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	BoolVector f(3);
	showVector(f);
    return 0;
}
