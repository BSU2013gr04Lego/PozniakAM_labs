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
    BoolVector& operator=(const BoolVector a);
    ~BoolVector();

    BoolVector operator+(const BoolVector a);
    bool operator>(const BoolVector a);

    BoolVector con(const BoolVector *a); // Conjuction
    BoolVector dis(const BoolVector *a); // Disjunction
    BoolVector neg();               // Negation
    int numOfOnes () const;
    int numOfZeros () const;

    bool* getBody() const;
    int getLength() const;
};
