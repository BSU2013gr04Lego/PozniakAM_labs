#include "AVLImpl.h"

#include <string>
#include <iostream>
#include <exception>
#include <utility>

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLTree::AVLImpl::AVLImpl() :
    root(nullptr)
{
}

AVLTree::AVLImpl::AVLImpl(const AVLImpl &other) :
    root(nullptr)
{
    other.copy(this);
}

AVLTree::AVLImpl::AVLImpl(AVLImpl &&other) :
    root(nullptr)
{
    swap (this->root, other.root);
}

AVLTree::AVLImpl& AVLTree::AVLImpl::operator=(const AVLImpl &other)
{
    if (this != &other)
    {
        other.copy(this);
    }
    return *this;
}

AVLTree::AVLImpl& AVLTree::AVLImpl::operator=(AVLImpl &&other)
{
    swap (this->root, other.root);
    return *this;
}

AVLTree::AVLImpl::~AVLImpl()
{
    clear();
}

//--------------- /THE GREAT 6 ----------------------------
//---------------  PRIVATE METHODS ------------------------

int AVLTree::AVLImpl::height(const AVLNode *node) const
{
    if (node)
        return node->height;
    return 0;
}

char AVLTree::AVLImpl::heightDiff(const AVLNode *node) const
{
    return height(node->right) - height(node->left);
}

void AVLTree::AVLImpl::updateHeight(AVLNode *node)
{
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight)
        node->height = leftHeight + 1;
    else
        node->height = rightHeight + 1;
}

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::findMin(AVLNode *node) const
{
    if (node->left)
        return findMin(node->left);
    return node;
}

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::rmMin(AVLNode *node)
{
    if (!(node->left))
        return node->right;
    node->left = rmMin(node->left);
    return balance(node);
}

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::rotateL(AVLNode *node)
{
    AVLNode *nodeR = node->right;
    node->right = nodeR->left;
    nodeR->left = node;
    updateHeight(nodeR->left);
    updateHeight(nodeR);
    return nodeR;
}

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::rotateR(AVLNode *node)
{
    AVLNode *nodeL = node->left;
    node->left = nodeL->right;
    nodeL->right = node;
    updateHeight(nodeL->right);
    updateHeight(nodeL);
    return nodeL;
}

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::balance(AVLNode *node)
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

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::ins(AVLNode *node, int key, int val)
{
    if (!node)
        return new AVLNode(key, val);
    if (key < node->key)
        node->left = ins(node->left, key, val);
    else
        node->right = ins(node->right, key, val);
    return balance(node);
}

AVLTree::AVLImpl::AVLNode* AVLTree::AVLImpl::rmv(AVLNode *node, int key)
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

void AVLTree::AVLImpl::cp(const AVLNode *node, AVLImpl *drain) const
{
    drain->insert(node->key, node->value);
    if (node->left)
        cp(node->left, drain);
    if (node->right)
        cp(node->right, drain);
}

void AVLTree::AVLImpl::mkVisit(void (*visitor)(int key, int val, string s), const AVLNode *node, string s) const
{
    if (node)
		visitor(node->key, node->value, s);
	else
		return;
	mkVisit(visitor, node->left, s + "|   ");
	mkVisit(visitor, node->right, s + "    ");
}

//--------------- /PRIVATE METHODS ------------------------
//---------------  PUBLIC METHODS -------------------------

// Binary tree methods
bool AVLTree::AVLImpl::isEmpty() const
{
	return !root;
}

void AVLTree::AVLImpl::insert(int key, int val)
{
	root = ins(root, key, val);
}

void AVLTree::AVLImpl::remove(int key)
{
	root = rmv(root, key);
}

int AVLTree::AVLImpl::find(int key) const
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

void AVLTree::AVLImpl::copy(AVLImpl *drain) const
{
	drain->clear();
	cp(root, drain);
}

void AVLTree::AVLImpl::clear()
{
    while (root)
    {
        remove(root->key);
    }
}

void AVLTree::AVLImpl::makeVisit(void (*visitor)(int key, int val, string s)) const		//public
{
	mkVisit(visitor, root, "");
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
