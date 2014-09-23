#include <utility>
#include <exception>

#include "BoolVector.h"

#define DEFAULT_SIZE 0

#define max(a, b)((a > b) ? (a) : (b))
#define min(a, b)((a < b) ? (a) : (b))
//---------------------- GREAT 4 ------------------------------

// Constructors

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

// Copy constructor

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

//move constructor

BoolVector::BoolVector(BoolVector &&obj)
	:n(std::move(obj.n)),
	 body(std::move(obj.body)),
	 n_ones(std::move(obj.n_ones))
{
}

//assign op

BoolVector& BoolVector::operator=(const BoolVector &a)
{
    if (&a == this)
        return *this;
    if (body)
        delete[] body;
    n = a.n;
    n_ones = a.n_ones;
    body = new bool[n];
    for (int i = 0; i < n; i++)
    {
        body[i] = a.body[i];
    }
};

//move assignment

BoolVector& BoolVector::operator=(BoolVector &&a)
{
	if (this != &a)
	{
		n = std::move(a.n);
		body = std::move(a.body);
		n_ones = std::move(a.n_ones);
	}
	return *this;
}

//destructor

BoolVector::~BoolVector()
{
    delete[] body;
}

//------------------------- PRIVATE METHODS --------------------

void BoolVector::update()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (body[i])
			ans++;
	n_ones = ans;
}

//------------------------- OPERATORS --------------------------

bool BoolVector::operator[](const int index) const
{
    if (index >=0 && index < n)
        return body[index];
    throw std::exception();
}

// Bitwise operators

BoolVector BoolVector::operator~() const
{
	BoolVector ans(this->n);
	for (int i = 0; i < this->n; i++)
	{
		ans.body[i] = ! this->body[i];
	}
	ans.update();
	return ans;
}

BoolVector BoolVector::operator&(const BoolVector a) const
{
	BoolVector ans(min(this->n, a.n));
    for (int i = 0; i < min(this->n, a.n); i++)
    {
        ans.body[i] = this->body[i] && a.body[i];
    }
    ans.update();
    return ans;
}

BoolVector BoolVector::operator|(const BoolVector a) const
{
	BoolVector ans(min(this->n, a.n));
    for (int i = 0; i < min(this->n, a.n); i++)
    {
        ans.body[i] = this->body[i] || a.body[i];
    }
    ans.update();
    return ans;
}

BoolVector BoolVector::operator^(const BoolVector a) const
{
	BoolVector ans(min(this->n, a.n));
    for (int i = 0; i < min(this->n, a.n); i++)
    {
        ans.body[i] = this->body[i] ^ a.body[i];
    }
    ans.update();
    return ans;
}

// Logical operators

bool BoolVector::operator!() const
{
	for (int i = 0; i < this->n; i++)
	{
		if (this->body[i])
			return false;
	}
	return true;
}

bool BoolVector::operator&&(const BoolVector a) const
{
	int x = 0,
		y = 0;
    for (int i = 0; i < max(this->n, a.n); i++)
    {
		x += this->n >= i ? this->body[i] : 0;
		y += a.n >= i ? a.body[i] : 0;
    }
    if (!x || !y)
		return false;
	return true;
}

bool BoolVector::operator||(const BoolVector a) const
{
	int x = 0,
		y = 0;
    for (int i = 0; i < max(this->n, a.n); i++)
    {
		x += this->n >= i ? this->body[i] : 0;
		y += a.n >= i ? a.body[i] : 0;
    }
    if (!x && !y)
		return false;
	return true;
}
// Comparison operators

bool BoolVector::operator==(const BoolVector a) const
{
	for (int i = max(this->n, a.n); i > 0; i--)
	{
		int x = this->n >= i ? this->body[i] : 0;
		int y = a.n >= i ? a.body[i] : 0;
		if (x != y)
			return false;
	}
	return true;
}

bool BoolVector::operator!=(const BoolVector a) const
{
	if (*this == a)
		return false;
	return true;
}

bool BoolVector::operator>(const BoolVector a) const
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

bool BoolVector::operator>=(const BoolVector a) const
{
	if ((*this > a) || (*this == a))
		return true;
	return false;
}

bool BoolVector::operator<(const BoolVector a) const
{
	if ((*this > a) || (*this == a))
		return false;
	return true;
}

bool BoolVector::operator<=(const BoolVector a) const
{
	if (*this > a)
		return false;
	return true;
}

//------------------------- METHODS ----------------------------
BoolVector BoolVector::con(const BoolVector a) const
{
    BoolVector ans(min(a.n, this->n));
    for (int i = 0; i < min(a.n, this->n); i++)
    {
        ans.body[i] = a.body[i] && this->body[i];
    }
    ans.update();
    return ans;
}

BoolVector BoolVector::dis(const BoolVector a) const
{
    BoolVector ans(min(a.n, this->n));
    for (int i = 0; i < min(a.n, this->n); i++)
    {
        ans.body[i] = a.body[i] || this->body[i];
    }
    ans.update();
    return ans;
}

BoolVector BoolVector::neg() const
{
    BoolVector ans(this->n);
    for (int i = 0; i < this->n; i++)
    {
        ans.body[i] = ~this->body[i];
    }
    ans.update();
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

int BoolVector::getLength() const
{
    return n;
}
