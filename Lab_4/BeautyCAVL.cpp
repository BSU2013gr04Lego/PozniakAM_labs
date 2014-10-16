#include "BeautyCAVL.h"
#include <utility>
#include <iostream>

using namespace std;

//---------------- THE GREAT 6 ----------------------------

BeautyCAVL::BeautyCAVL() :
	ConsoleAVL()
{
}

BeautyCAVL::BeautyCAVL(BeautyCAVL &other) :
	ConsoleAVL(other)
{
}

BeautyCAVL::BeautyCAVL(BeautyCAVL &&other) :
	ConsoleAVL(other)
{
}

BeautyCAVL& BeautyCAVL::operator=(BeautyCAVL &other)
{
	other.copy(this);
    return *this;
}

BeautyCAVL& BeautyCAVL::operator=(BeautyCAVL &&other)
{
	other.copy(this);
    return *this;
}

BeautyCAVL::~BeautyCAVL()
{
}

//----------------/THE GREAT 6 ----------------------------
//---------------  PROTECTED METHODS ----------------------

void BeautyCAVL::draw_phase() const
{
    cout << "==============================================" << endl;
    makeVisit([](int key, int val, std::string s)
    {
        cout << (s.length() ? (s.substr(0, s.length() - 4) + "|---") : "") << "(" << key
             << ", " << val << ")" << endl;
    });
    cout << "==============================================" << endl;
}

//--------------- /PROTECTED METHODS ----------------------
//---------------  PUBLIC METHODS -------------------------

void BeautyCAVL::draw() const
{
	draw_phase();
}

//--------------- /PUBLIC METHODS -------------------------

