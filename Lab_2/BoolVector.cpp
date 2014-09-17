#include "BoolVector.h"

#define DEFAULT_SIZE 0

#define max(a, b)((a > b) ? (a) : (b))
#define min(a, b)((a < b) ? (a) : (b))
//---------------------- GREAT 4 ------------------------------

// Constructors

BoolVector::BoolVector()
    :	body(nullptr)
{
    length = DEFAULT_SIZE;
    n = (length / 32) + (length % 32 ? 1 : 0);
    n_ones = 0;
    body = new unsigned int[n];
    clearBody();
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
            body[i] = 0;
        }
    }
}

BoolVector::BoolVector(int n)
    :	n(n),
		body(nullptr)
{
    body = new unsigned int[n];
    clearBody();
	for (int i = 0; i < n; i++)
	{
		body[i] = 0;
	}
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
            body[i] = 0;
        }
    }
    update();
}

BoolVector::BoolVector(int n, unsigned int arr[])
    :	n(n),
		body(nullptr)
{

    body = new unsigned int[n];
    clearBody();
    if (body)
    {
        for (int i = 0; i < n; i++)
        {
            body[i] = arr[i];
            n_ones  += nBinaryOnes(arr[i]);
        }
    }
    update();
}

// Copy constructor

BoolVector::BoolVector(const BoolVector &obj)
    :body(nullptr)
{
	length = obj.length;
    n = obj.n;
    n_ones = obj.n_ones;
    body = new unsigned int[n];
    clearBody();
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
	length = a.length;
    n = a.n;
    n_ones = a.n_ones;
    body = new unsigned int[n];
    clearBody();
    for (int i = 0; i < n; i++)
    {
        body[i] = a.body[i];
    }
};

//destructor

BoolVector::~BoolVector()
{
    delete[] body;
}

//------------------------- PRIVATE METHODS --------------------

void BoolVector::update()
{
	int ans = 0; int l = 0; int len = 0;
	for (int i = 0; i < n; i++)
		if (body[i])
			ans += nBinaryOnes(body[i]);
	(*this).n_ones = ans;
	for (int i = 0; i < n; i++)
	{
		unsigned int temp = body[i];
		for (int j = 0; temp; j++)
		{
			if (temp % 2)
				l = j;
			temp /= 2;
		}
		len += l;
		l = 0;
	}
	(*this).length = len + 1;
}

int BoolVector::nBinaryOnes(const unsigned int x)
{
	int ans = 0;
	unsigned int temp = x;
	while (temp)
	{
		ans += temp % 2;
		temp /= 2;
	}
	return ans;
}

void BoolVector::clearBody()
{
	for (int i = 0; i < (*this).n; i++)
	{
		body[i] = 0;
	}
}

//------------------------- OPERATORS --------------------------

// Bitwise operators

BoolVector BoolVector::operator~()
{
	BoolVector ans(this->n);
	showVector(ans);
	for (int i = 0; i < this->n; i++)
	{
		ans.body[i] = ~ this->body[i];
	}
	ans.update();
	showVector(ans);
	return ans;
}

BoolVector BoolVector::operator&(const BoolVector a)
{
	BoolVector ans(max(this->n, a.n));
    for (int i = 0; i < max(this->n, a.n); i++)
    {
        if (this->n >= i && a.n >= i)
		{
			ans.body[i] = this->body[i] & a.body[i];
		} else
		{
			ans.body[i] = 0;         // (this->body[i] & 0) = (a.body[i] & 0) = 0
		}
    }
    ans.update();
    return ans;
}

BoolVector BoolVector::operator|(const BoolVector a)
{
	BoolVector ans(max(this->n, a.n));
    for (int i = 0; i < max(this->n, a.n); i++)
    {
		if (this->n >= i && a.n >= i)
		{
			ans.body[i] = this->body[i] | a.body[i];
		} else
		{
			if (this->n >= i)
			{
				ans.body[i] = this->body[i] | 0;
			} else
			{
				ans.body[i] = a.body[i] | 0;
			}
		}
    }
    ans.update();
    return ans;
}

BoolVector BoolVector::operator^(const BoolVector a)
{
	BoolVector ans(max(this->n, a.n));
    for (int i = 0; i < max(this->n, a.n); i++)
    {
		if (this->n >= i && a.n >= i)
		{
			ans.body[i] = this->body[i] ^ a.body[i];
		} else
		{
			if (this->n >= i)
			{
				ans.body[i] = this->body[i] ^ 0;
			} else
			{
				ans.body[i] = a.body[i] ^ 0;
			}
		}
    }
    ans.update();
    return ans;
}

// Logical operators

bool BoolVector::operator!()
{
	for (int i = 0; i < this->n; i++)
	{
		if (this->body[i])
			return false;
	}
	return true;
}

bool BoolVector::operator&&(const BoolVector a)
{
	bool x = false;
	bool y = false;

	for (int i = 0; i < this->n; i++)
	{
		if (this->body[i])
		{
			x = true;
			break;
		}
	}
	for (int i = 0; i < a.n; i++)
	{
		if (a.body[i])
		{
			y = true;
			break;
		}
	}
	if (x && y)
		return true;
	return false;
}

bool BoolVector::operator||(const BoolVector a)
{
	bool x = false;
	bool y = false;

	for (int i = 0; i < this->n; i++)
	{
		if (this->body[i])
		{
			x = true;
			break;
		}
	}
	for (int i = 0; i < a.n; i++)
	{
		if (a.body[i])
		{
			y = true;
			break;
		}
	}
	if (!x && !y)
		return false;
	return true;
}
// Comparison operators

bool BoolVector::operator==(const BoolVector a)
{
	for (int i = max(this->n, a.n); i > 0; i--)
	{
		unsigned int x = this->n >= i ? this->body[i] : 0;
		unsigned int y = a.n >= i ? a.body[i] : 0;
		if (x != y)
			return false;
	}
	return true;
}

bool BoolVector::operator!=(const BoolVector a)
{
	if (*this == a)
		return false;
	return true;
}

bool BoolVector::operator>(const BoolVector a)
{
	for (int i = max(this->n, a.n); i > 0; i--)
	{
		unsigned int x = this->n >= i ? this->body[i] : 0;
		unsigned int y = a.n >= i ? a.body[i] : 0;
		if (x > y)
			return true;
		if (y > x)
			return false;
	}
	return false;
}

bool BoolVector::operator>=(const BoolVector a)
{
	if ((*this > a) || (*this == a))
		return true;
	return false;
}

bool BoolVector::operator<(const BoolVector a)
{
	if ((*this > a) || (*this == a))
		return false;
	return true;
}

bool BoolVector::operator<=(const BoolVector a)
{
	if (*this > a)
		return false;
	return true;
}

//------------------------- METHODS ----------------------------
BoolVector BoolVector::con(const BoolVector a)
{
	BoolVector ans(max(this->n, a.n));
	ans = *this & a;
    ans.update();
    return ans;
}

BoolVector BoolVector::dis(const BoolVector a)
{
	BoolVector ans(max(this->n, a.n));
    ans = *this | a;
    ans.update();
    return ans;
}

BoolVector BoolVector::neg()
{
    BoolVector ans(this->n);
    ans = ~ (*this);
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
unsigned int* BoolVector::getBody() const
{
    return body;
}

int BoolVector::getLength() const
{
    return length;
}

int BoolVector::getBodyLength() const
{
    return n;
}
