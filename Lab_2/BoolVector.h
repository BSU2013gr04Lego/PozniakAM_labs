class BoolVector
{
    int length;      		// Vector's length
    int n;      			// Body-array length
    unsigned int *body; 	// Vector's body
    int n_ones; 			// Number of ones

    void update();
    int nBinaryOnes(const int x);
    void clearBody();

public:
    BoolVector();
    explicit BoolVector(int n);
    BoolVector(int n, unsigned int arr[]);
    BoolVector(const BoolVector &obj);
    BoolVector& operator=(const BoolVector a);
    ~BoolVector();

	BoolVector operator~ ();
    BoolVector operator& (const BoolVector a);
    BoolVector operator| (const BoolVector a);
    BoolVector operator^ (const BoolVector a);

	bool operator! ();
    bool operator&&(const BoolVector a);
    bool operator||(const BoolVector a);

    bool operator==(const BoolVector a);
    bool operator!=(const BoolVector a);
    bool operator> (const BoolVector a);
    bool operator>=(const BoolVector a);
    bool operator< (const BoolVector a);
    bool operator<=(const BoolVector a);

    BoolVector con(const BoolVector a); // Conjunction
    BoolVector dis(const BoolVector a); // Disjunction
    BoolVector neg();               // Negation
    int numOfOnes () const;
    int numOfZeros () const;

    unsigned int* getBody() const;
    int getLength() const;
    int getBodyLength() const;
};
