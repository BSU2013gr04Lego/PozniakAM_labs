#include "ConsoleAVL.h"
#include <utility>

using namespace std;

//---------------- THE GREAT 6 ----------------------------

ConsoleAVL::ConsoleAVL() : AVLTree()
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
    ConsoleAVL temp;
    this->clear();
    while (!other.isEmpty())
    {
        this->insert(other.root->key, other.root->value);
        temp.insert(other.root->key, other.root->value);
        other.remove(other.root->key);
    }
    swap(other.root, temp.root);
    return *this;
}

ConsoleAVL& ConsoleAVL::operator=(ConsoleAVL &&other)
{
    if (&other != this)
        swap (this->root, other.root);
    return *this;
}

ConsoleAVL::~ConsoleAVL()
{
}

//----------------/THE GREAT 6 ----------------------------
//---------------  PROTECTED METHODS ----------------------

int ConsoleAVL::find_phase(int key) const
{
    AVLNode *current = this->root;
    while (current->key != key)
    {
        if (key < current->key)
        {
            current = current->left;
        }
        if (key > current->key)
        {
            current = current->right;
        }
        if (key == current->key)
        {
            return current->value;
        }
    }
    throw exception();
}

//---------------  PROTECTED METHODS ----------------------
//---------------  PUBLIC METHODS -------------------------

void ConsoleAVL::drawTree() const
{
    //draw(root, "");
    pimpl->draw(root, "");
}

//--------------- /PUBLIC METHODS -------------------------
