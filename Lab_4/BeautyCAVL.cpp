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
	makeVisit([](const AVLNode *node)
				{
                    for (int i = 0; i < node->height - 1; ++i)
						cout << "----";
					cout << "(" << node->key << ", " << node->value << "):["
						 << node->height << "]" << endl;
				});
}

//--------------- /PROTECTED METHODS ----------------------
//---------------  PUBLIC METHODS -------------------------

void BeautyCAVL::draw() const
{
	draw_phase();
}

//--------------- /PUBLIC METHODS -------------------------

