class BoolVector
{
    int length;      		// Vector's length
    int n;      			// Body-array length
    unsigned int *body; 	// Vector's body
    int n_ones; 			// Number of ones

    void update();
    int nBinaryOnes(const unsigned int x) const;
    void clearBody();

public:
    BoolVector();
    explicit BoolVector(int length);
    BoolVector(int length, bool arr[]);
    BoolVector(const BoolVector &obj);
    BoolVector(BoolVector &&obj);
    BoolVector& operator=(const BoolVector &a);
    BoolVector& operator=(BoolVector &&a);
    ~BoolVector();

    BoolVector operator~ () const;
    BoolVector operator& (const BoolVector a) const;
    BoolVector operator| (const BoolVector a) const;
    BoolVector operator^ (const BoolVector a) const;

    bool operator[](int index) const;

    bool operator! () const;
    bool operator&&(const BoolVector a) const;
    bool operator||(const BoolVector a) const;

    bool operator==(const BoolVector a) const;
    bool operator!=(const BoolVector a) const;
    bool operator> (const BoolVector a) const;
    bool operator>=(const BoolVector a) const;
    bool operator< (const BoolVector a) const;
    bool operator<=(const BoolVector a) const;

    BoolVector con(const BoolVector a) const; // Conjunction
    BoolVector dis(const BoolVector a) const; // Disjunction
    BoolVector neg() const;               // Negation
    int numOfOnes () const;
    int numOfZeros () const;

    int getLength() const;
    int getBodyLength() const;
};
