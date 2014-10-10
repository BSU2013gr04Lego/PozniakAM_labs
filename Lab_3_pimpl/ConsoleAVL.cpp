#include "ConsoleAVL.h"
#include <utility>

using namespace std;

//---------------- THE GREAT 6 ----------------------------

ConsoleAVL::ConsoleAVL() : AVLTree(new ConsoleImpl)
{
}

ConsoleAVL::ConsoleAVL(ConsoleImpl *p) : AVLTree(p)
{
}

ConsoleAVL::ConsoleAVL(ConsoleAVL &other) : AVLTree(other)
{
    this->pimpl = new ConsoleImpl;
}

ConsoleAVL::ConsoleAVL(ConsoleAVL &&other) : AVLTree(other)
{
    this->pimpl = new ConsoleImpl;
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &other)
{
    ConsoleAVL temp;
    this->clear();
    while (!other.isEmpty())
    {
        this->insert(other.root->key, other.root->value);
        temp.insert(other.root->key, other.root->value);
        other.remove(other.root->key);
    }
    swap(other.root, temp.root);
    this->pimpl = new ConsoleImpl;
    return *this;
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &&other)
{
    if (&other != this)
        swap (this->root, other.root);
    this->pimpl = nullptr;
    return *this;
}

ConsoleAVL::~ConsoleAVL()
{
}

//----------------/THE GREAT 6 ----------------------------
//---------------  PUBLIC METHODS -------------------------

void ConsoleAVL::drawTree() const
{
    //draw(root, "");
    pimpl->draw(root, "");
}

//--------------- /PUBLIC METHODS -------------------------
