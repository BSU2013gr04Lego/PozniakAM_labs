#include <utility>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() : top(nullptr)
{
}

AVLTree::AVLTree(const AVLTree &other) : top(nullptr)
{
    // TODO
}

AVLTree::AVLTree(AVLTree &&other) : top(move(other.top))
{
}

AVLTree& AVLTree::operator=(const AVLTree &other)
{
    // TODO
}

AVLTree& AVLTree::operator=(AVLTree &&other)
{
    swap(this->top, other.top);
}
