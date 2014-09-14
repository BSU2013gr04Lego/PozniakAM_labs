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
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
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
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
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
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
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
    n_ones = obj.n_ones;
    body = new bool[n];
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
            body[i] = obj.body[i];
        }
    }
}

//assign op

BoolVector& BoolVector::operator=(const BoolVector a)
{
    if (&a == this)
        return *this;
    if (body)
        delete[] body;
    n = a.n;
    body = new bool[n];
    for (int i = 0; i < n; i++)
    {
        body[i] = a.body[i];
    }
};

//dtor

BoolVector::~BoolVector()
{
    delete[] body;
}

//------------------------- OPERATORS --------------------------

BoolVector BoolVector::operator+(const BoolVector a)
{
	BoolVector ans(min(this->n, a.n));
    for (int i = 0; i < min(this->n, a.n); i++)
    {
        ans.body[i] = this->body[i] && a.body[i];
    }
    return ans;
}

bool BoolVector::operator>(const BoolVector a)
{
	for (int i = max(this->n, a.n); i > 0; i--)
	{
		int x = this->n >= i ? this->body[i] : 0;
		int y = a.n >= i ? a.body[i] : 0;
		if (x && !y)
			return true;
		if (y && !x)
			return false;
	}
	return false;
}

//------------------------- METHODS ----------------------------
BoolVector BoolVector::con(const BoolVector *a)
{
    BoolVector ans(min(a->n, this->n));
    for (int i = 0; i < min(a->n, this->n); i++)
    {
        ans.body[i] = a->body[i] && this->body[i];
    }
    return ans;
}

BoolVector BoolVector::dis(const BoolVector *a)
{
    BoolVector ans(min(a->n, this->n));
    for (int i = 0; i < min(a->n, this->n); i++)
    {
        ans.body[i] = a->body[i] || this->body[i];
    }
    return ans;
}

BoolVector BoolVector::neg()
{
    BoolVector ans(this->n);
    for (int i = 0; i < this->n; i++)
    {
        ans.body[i] = ~this->body[i];
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
