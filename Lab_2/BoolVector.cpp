#include "BoolVector.h"

#define DEFAULT_SIZE 0
#define max(a, b)((a > b) ? (a) : (b))
#define min(a, b)((a < b) ? (a) : (b))
//---------------------- GREAT 4 ------------------------------

// Ctors

BoolVector::BoolVector()
	:	body(nullptr)
{
	n = DEFAULT_SIZE;
	n_ones = 0;
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = 0;
		}
	}
}

BoolVector::BoolVector(int n)
	:	n(n)
		,body(nullptr)
{
	n_ones = 0;
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = 0;
		}
	}
}

BoolVector::BoolVector(int n, bool arr[])
	:	n(n)
		,body(nullptr)
{
	n_ones = 0;
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = arr[i];
			n_ones  += arr[i];
		}
	}
}

// Copy ctor

BoolVector::BoolVector(const BoolVector &obj)
	:body(nullptr)
{
	n = obj.n;
	body = new bool[n];
	if (body) {
		for (int i = 0; i < n; i++) {
			body[i] = obj.body[i];
		}
	}
}

//dtor

BoolVector::~BoolVector()
{
	delete[] body;
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

int BoolVector::numOfOnes() const
{
	return n_ones;
}

int BoolVector::numOfZeros() const
{
	return n - n_ones;
}

//------------------------- SET/GET METHODS --------------------
bool* BoolVector::getBody() const
{
	return body;
}

int BoolVector::getLength() const
{
	return n;
}
