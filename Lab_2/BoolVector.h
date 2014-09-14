class BoolVector
{
    int n;      // Vector's length
    bool *body; // Vector's body
    int n_ones; // Number of ones
public:
    BoolVector();
    explicit BoolVector(int n);
    BoolVector(int n, bool arr[]);
    BoolVector(const BoolVector &obj);
	BoolVector& operator=(const BoolVector a)
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
	~BoolVector();

    BoolVector con(BoolVector a, BoolVector b); // Conjuction
    BoolVector dis(BoolVector a, BoolVector b); // Disjunction
    BoolVector neg(BoolVector a);               // Negation
    int numOfOnes () const;
    int numOfZeros () const;
    bool* getBody() const;
    int getLength() const;
};
