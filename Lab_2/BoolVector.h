#ifndef BOOLVECTOR_H
#define BOOLVECTOR_H


class BoolVector
{
    int n;      // Vector's length
    bool *body; // Vector's body
    int n_ones; // Number of ones

    void update();

public:
    BoolVector();
    explicit BoolVector(int n);
    BoolVector(int n, bool arr[]);
    BoolVector(const BoolVector &obj);
    BoolVector(BoolVector &&obj);
    BoolVector& operator=(const BoolVector &a);
    BoolVector& operator=(BoolVector &&a);
    ~BoolVector();

    bool operator[](const int i) const;

	BoolVector operator~ () const;
    BoolVector operator& (const BoolVector a) const;
    BoolVector operator| (const BoolVector a) const;
    BoolVector operator^ (const BoolVector a) const;

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
};

#endif // BOOLVECTOR_H
