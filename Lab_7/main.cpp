#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class isEven
{
private:
public:
    isEven() = default;
    isEven(const isEven& obj) = default;
    isEven(isEven&& obj) = default;
    isEven& operator=(const isEven& rv) = default;
    isEven& operator=(isEven&& rv) = default;
    ~isEven() = default;

    bool operator()(int num) {
    	return !(num % 2);
    }
};

int main()
{
	vector<int> v;
	int n = 0;
	cout << "Enter count of elements in array: ";
	cin >> n;
	cout << endl;
	cout << "Enter the number: ";
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	cout << endl << count_if(v.begin(), v.end(), isEven()) << " Even numbers" << endl;

	if (all_of(v.begin(), v.end(), [](int num){return num > 0;}))
		cout << "All elements greater than zero" << endl;
	else
		cout << "There are one element which less or equal zero" << endl;
    return 0;
}
