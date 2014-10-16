#include "ConsoleAVL.h"
#include <utility>
#include <iostream>

using namespace std;

//---------------- THE GREAT 6 ----------------------------

ConsoleAVL::ConsoleAVL() :
	AVLTree()
{
}

ConsoleAVL::ConsoleAVL(ConsoleAVL &other) :
	AVLTree(other)
{
}

ConsoleAVL::ConsoleAVL(ConsoleAVL &&other) :
	AVLTree(other)
{
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &other)
{
	other.copy(this);
    return *this;
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &&other)
{
	other.copy(this);
    return *this;
}

ConsoleAVL::~ConsoleAVL()
{
}

//----------------/THE GREAT 6 ----------------------------
//---------------  PROTECTED METHODS ----------------------

void ConsoleAVL::draw_phase() const
{
	cout << "==============================================" << endl;
	makeVisit([](int key, int val, std::string s)
				{
					cout << "(" << key << ", " << val << ")" << endl;
				});
	cout << "==============================================" << endl;
}

//--------------- /PROTECTED METHODS ----------------------
//---------------  PUBLIC METHODS -------------------------

void ConsoleAVL::draw() const
{
	draw_phase();
}

//--------------- /PUBLIC METHODS -------------------------
