#include "ConsoleAVL.h"

using namespace std;

ConsoleAVL::ConsoleAVL() : AVLTree(new ConsoleImpl)
{
}

ConsoleAVL::ConsoleAVL(ConsoleImpl *p) : AVLTree(p)
{
}

ConsoleAVL::ConsoleAVL(ConsoleAVL &other) : AVLTree(other)
{
}

ConsoleAVL::ConsoleAVL(ConsoleAVL &&other) : AVLTree(other)
{
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &other)
{
    return *(new ConsoleAVL(other));
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &&other)
{
    return *(new ConsoleAVL(other));
}

ConsoleAVL::~ConsoleAVL()
{
}

void ConsoleAVL::drawTree() const
{
    //draw(root, "");
    pimpl->draw(root, "");
}
