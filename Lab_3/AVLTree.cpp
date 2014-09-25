#include <utility>
#include <exception>
#include <iostream>
#include "AVLTree.h"

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLTree::AVLTree() : root(nullptr)
{
}

AVLTree::AVLTree(const AVLTree &other) : root(nullptr)
{
    // TODO
    // Copy every node
}

AVLTree::AVLTree(AVLTree &&other) : root(nullptr)
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
        remove(root->key);
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

AVLNode* AVLTree::ins(AVLNode *node, int key, int val)
{
    if (!node)
        return new AVLNode(key, val);
    if (key < node->key)
        node->left = ins(node->left, key, val);
    else
        node->right = ins(node->right, key, val);
    return node;
}

AVLNode* AVLTree::rmv(AVLNode *node, int key)
{
    if (!node)
        return 0;
    if (key < node->key)
    {
        node->left = rmv(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = rmv(node->right, key);
    }
    else
    {
        AVLNode *left = node->left;
        AVLNode *right = node->right;
        delete node;
        if (!right)
            return left;
        AVLNode *min = findMin(right);
        min->right = rmMin(right);
        min->left = left;
        return min;
    }
    return node;
}

AVLNode* AVLTree::findMin(AVLNode *node) const
{
    if (node->left)
        return findMin(node->left);
    return node;
}

AVLNode* AVLTree::rmMin(AVLNode *node)
{
    if (!(node->left))
        return node->right;
    node->left = rmMin(node->left);
    return node;
}

//--------------- /PRIVATE METHODS ------------------------
//---------------  PUBLIC METHODS -------------------------

bool AVLTree::isEmpty() const
{
    if (root)
        return false;
    return true;
}

void AVLTree::insert(int key, int val)
{
    root = ins(root, key, val);
}

void AVLTree::remove(int key)
{
    root = rmv(root, key);
}

int AVLTree::find(int key) const

{
    AVLNode *current = root;
    if (!current)
    {
        throw exception();
    }
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
}

// For find bugs
AVLNode* AVLTree::getRoot() const
{
    return root;
}

void AVLTree::drawTree(AVLNode *node) const
{
    if (node)
    {
        cout << " (" << node->key << ", " << node->value << ")";
        drawTree(node->left);
        drawTree(node->right);
    }
    else
    {
        cout << endl;
    }
}

//--------------- /PUBLIC METHODS -------------------------
