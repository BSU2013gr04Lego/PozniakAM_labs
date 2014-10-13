#include "AVLImpl.h"

#include <string>
#include <iostream>
#include <exception>
#include <utility>

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLImpl::AVLImpl() :
    root(nullptr)
{
}

AVLImpl::AVLImpl(const AVLImpl &other) :
    root(nullptr)
{
    other.copy(this);
}

AVLImpl::AVLImpl(AVLImpl &&other) :
    root(nullptr)
{
    swap (this->root, other.root);
}

AVLImpl& AVLImpl::operator=(const AVLImpl &other)
{
    if (this != &other)
    {
        other.copy(this);
    }
    return *this;
}

AVLImpl& AVLImpl::operator=(AVLImpl &&other)
{
    swap (this->root, other.root);
    return *this;
}

AVLImpl::~AVLImpl()
{
    clear();
}

//--------------- /THE GREAT 6 ----------------------------
//---------------  PRIVATE METHODS ------------------------

int AVLImpl::height(const AVLNode *node) const
{
    if (node)
        return node->height;
    return 0;
}

char AVLImpl::heightDiff(const AVLNode *node) const
{
    return height(node->right) - height(node->left);
}

void AVLImpl::updateHeight(AVLNode *node)
{
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight)
        node->height = leftHeight + 1;
    else
        node->height = rightHeight + 1;
}

AVLNode* AVLImpl::findMin(AVLNode *node) const
{
    if (node->left)
        return findMin(node->left);
    return node;
}

AVLNode* AVLImpl::rmMin(AVLNode *node)
{
    if (!(node->left))
        return node->right;
    node->left = rmMin(node->left);
    return balance(node);
}

AVLNode* AVLImpl::rotateL(AVLNode *node)
{
    AVLNode *nodeR = node->right;
    node->right = nodeR->left;
    nodeR->left = node;
    updateHeight(nodeR->left);
    updateHeight(nodeR);
    return nodeR;
}

AVLNode* AVLImpl::rotateR(AVLNode *node)
{
    AVLNode *nodeL = node->left;
    node->left = nodeL->right;
    nodeL->right = node;
    updateHeight(nodeL->right);
    updateHeight(nodeL);
    return nodeL;
}

AVLNode* AVLImpl::balance(AVLNode *node)
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

AVLNode* AVLImpl::ins(AVLNode *node, int key, int val)
{
    if (!node)
        return new AVLNode(key, val);
    if (key < node->key)
        node->left = ins(node->left, key, val);
    else
        node->right = ins(node->right, key, val);
    return balance(node);
}

AVLNode* AVLImpl::rmv(AVLNode *node, int key)
{
    if (!node)
        throw exception();
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

void AVLImpl::cp(const AVLNode *node, AVLImpl *drain) const
{
    drain->insert(node->key, node->value);
    if (node->left)
        cp(node->left, drain);
    if (node->right)
        cp(node->right, drain);
}

void AVLImpl::mkVisit(void (*visitor)(const AVLNode *node), const AVLNode *node) const
{
    if (node)
		visitor(node);
	else
		return;
	mkVisit(visitor, node->left);
	mkVisit(visitor, node->right);
}

//--------------- /PRIVATE METHODS ------------------------
//---------------  PUBLIC METHODS -------------------------

// Binary tree methods
bool AVLImpl::isEmpty() const
{
	return !root;
}

void AVLImpl::insert(int key, int val)
{
	root = ins(root, key, val);
}

void AVLImpl::remove(int key)
{
	root = rmv(root, key);
}

int AVLImpl::find(int key) const
{
    AVLNode *current = root;
    do
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
    } while (current->key != key);
    throw exception();
}

void AVLImpl::copy(AVLImpl *drain) const
{
	drain->clear();
	cp(root, drain);
}

void AVLImpl::clear()
{
    while (root)
    {
        remove(root->key);
    }
}

void AVLImpl::makeVisit(void (*visitor)(const AVLNode *node)) const		//public
{
	mkVisit(visitor, root);
}

//--------------- /PUBLIC METHODS -------------------------


/*

void ConsoleImpl::draw(AVLNode *node, string s) const
{
    if (node)
    {
        cout << (s.length() ? (s.substr(0, s.length() - 4) + "|---") : "") << "(" << node->key
																	   << ", " << node->value << "):["
																	   << (int)node->height << "]" << endl;
        draw(node->right, s + "|   ");
        draw(node->left, s + "    ");
    }
}

*/
