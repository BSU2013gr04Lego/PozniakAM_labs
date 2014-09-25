#include <utility>
#include <exception>
#include "AVLTree.h"

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLTree::AVLTree() : top(nullptr)
{
}

AVLTree::AVLTree(const AVLTree &other) : top(nullptr)
{
    // TODO
    // Copy every node
}

AVLTree::AVLTree(AVLTree &&other) : top(nullptr)
{
    // TODO
    // Move every node
}

AVLTree& AVLTree::operator=(const AVLTree &other)
{
    // TODO
    // Copy every node
}

AVLTree& AVLTree::operator=(AVLTree &&other)
{
    // TODO
    // Swap every node
}

AVLTree::~AVLTree()
{
   while (!isEmpty())
   {
        remove(top->key);
   }
}

//--------------- /THE GREAT 6 ----------------------------
//---------------  PRIVATE METHODS ------------------------

unsigned char height(AVLNode *node)
{
    return node->height;
}

unsigned char heightDiff(AVLNode *node)
{
    return height(node->right) - height(node->left);
}

void updateHeight(AVLNode *node)
{
    unsigned char leftHeight = height(node->left);
    unsigned char rightHeight = height(node->right);
    if (leftHeight > rightHeight)
        node->height = leftHeight + 1;
    else
        node->height = rightHeight + 1;
}

//--------------- /PRIVATE METHODS ------------------------
//---------------  PUBLIC METHODS -------------------------

bool AVLTree::isEmpty() const
{
    if (top)
        return false;
    return true;
}

void AVLTree::insert(int key, int val)
{
    AVLNode *current = top;

    while (current)
    {
        if (key < current->key)
            current = current->left;
        if (key > current->key)
            current = current->right;
    }

    current = new AVLNode(key, val);
}

void AVLTree::remove(int key)
{
    // TODO
}

int AVLTree::find(int key) const
{
    AVLNode *current = top;
    while (current->key != key)
    {
        if (!current)
        {
            throw exception();
        }
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
}

//--------------- /PUBLIC METHODS -------------------------
