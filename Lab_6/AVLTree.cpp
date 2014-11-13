#include <utility>
#include <exception>
#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLTree::AVLTree() : root(nullptr)
{
}

AVLTree::AVLTree(const AVLTree &other) : root(nullptr)
{
    other.copy(this);
}

AVLTree::AVLTree(AVLTree &&other) : root(nullptr)
{
    swap (this->root, other.root);
}

AVLTree& AVLTree::operator=(const AVLTree &other)
{
    if (this != &other)
    {
        other.copy(this);
    }
    return *this;
}

AVLTree& AVLTree::operator=(AVLTree &&other)
{
    swap (this->root, other.root);
    return *this;
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

unsigned char AVLTree::height(AVLNode *node) const
{
    if (node)
        return node->height;
    return 0;
}

char AVLTree::heightDiff(AVLNode *node) const
{
    return height(node->right) - height(node->left);
}

void AVLTree::updateHeight(AVLNode *node)
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
    return balance(node);
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
        return balance(min);
    }
    return balance(node);
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
    return balance(node);
}

AVLNode* AVLTree::rotateL(AVLNode *node)
{
    AVLNode *nodeR = node->right;
    node->right = nodeR->left;
    nodeR->left = node;
    updateHeight(nodeR->left);
    updateHeight(nodeR);
    return nodeR;
}

AVLNode* AVLTree::rotateR(AVLNode *node)
{
    AVLNode *nodeL = node->left;
    node->left = nodeL->right;
    nodeL->right = node;
    updateHeight(nodeL->right);
    updateHeight(nodeL);
    return nodeL;
}

AVLNode* AVLTree::balance(AVLNode *node)
{
    updateHeight(node);
    if (heightDiff(node) == 2)
    {
        if (heightDiff(node->right) == -1)
            node->right = rotateR(node->right);
        return rotateL(node);
    }
    else if (heightDiff(node) == -2)
    {
        if (heightDiff(node->left) == 1)
            node->left = rotateL(node->left);
        return rotateR(node);
    }
    return node;
}

void AVLTree::draw(AVLNode *node, string s) const
{
    if (node)
    {
        cout << (s.length() ? (s.substr(0, s.length() - 4) + "|---") : "")
             << "(" << node->key << ", " << node->value << "):[" << (int)node->height << "]" << endl;
        draw(node->right, s + "|   ");
        draw(node->left, s + "    ");
    }
}


void AVLTree::cpy(const AVLNode *node, AVLTree *drain) const
{
    drain->insert(node->key, node->value);
    if (node->left)
        cpy(node->left, drain);
    if (node->right)
        cpy(node->right, drain);
}

//--------------- /PRIVATE METHODS ------------------------
//---------------  PUBLIC METHODS -------------------------

bool AVLTree::isEmpty() const
{
    return !root;
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

void AVLTree::copy(AVLTree *drain) const
{
    drain->clear();
    cpy(root, drain);
}

void AVLTree::clear()
{
    while (!isEmpty())
    {
        remove(root->key);
    }
}

// For find bugs

void AVLTree::drawTree() const
{
    draw(root, "");
}

//--------------- /PUBLIC METHODS -------------------------
