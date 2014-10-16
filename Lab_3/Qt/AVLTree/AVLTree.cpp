#include <utility>
#include <exception>
#include <iostream>
#include "AVLTree.h"
#include "AVLNode.h"

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLTree::AVLTree() : root(nullptr)
{
}

AVLTree::AVLTree(AVLTree &other) : root(nullptr)
{
    AVLTree temp;
    while (!other.isEmpty())
    {
        this->insert(other.root->key, other.root->value);
        temp.insert(other.root->key, other.root->value);
        other.remove(other.root->key);
    }
    swap(other.root, temp.root);
}

AVLTree::AVLTree(AVLTree &&other) : root(nullptr)
{
    swap (this->root, other.root);
}

AVLTree& AVLTree::operator=(AVLTree &other)
{
    AVLTree temp;
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

AVLTree& AVLTree::operator=(AVLTree &&other)
{
    if (&other != this)
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

unsigned char AVLTree::heightDiff(AVLNode *node) const
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

void AVLTree::draw(AVLNode *node) const
{
    if (node)
    {
        cout << " (" << node->key << ", " << node->value << ")[" << (int)node->height << "]";
        draw(node->left);
        draw(node->right);
    }
    else
    {
        cout << endl;
    }
}

int AVLTree::paint(AVLNode *node, QPainter *painter, int row, int column) const
{
    if (node)
    {
        int saved_column = column;
        painter->fillRect(column * WIDTH, row * HEIGHT, WIDTH - 4, HEIGHT - 3, QBrush(Qt::green));
        painter->drawText(column * WIDTH, row * HEIGHT, WIDTH - 4, HEIGHT - 3,
                          Qt::AlignCenter, QString::number(node->key));
        painter->drawLine((column + 1) * WIDTH - WIDTH / 2 - 2, (row + 1) * HEIGHT - 3,
                          (column + 1) * WIDTH - WIDTH / 2 - 2, (row + 1) * HEIGHT);
        column = paint(node->left, painter, row + 1, column);
        painter->drawLine((saved_column + 1) * WIDTH - 4, (row + 1) * HEIGHT - HEIGHT / 2 - 1,
                          (column + 2) * WIDTH - WIDTH / 2 - 2, (row + 1) * HEIGHT);
        column = paint(node->right, painter, row + 1, column + 1);
    }
    else
    {
        painter->fillRect(column * WIDTH, row * HEIGHT, WIDTH -4, HEIGHT - 3, QBrush(Qt::gray));
    }
    return column;
}

//--------------- /PRIVATE METHODS ------------------------
//---------------  PUBLIC METHODS -------------------------

unsigned char AVLTree::rootHeight() const
{
    return height(root);
}

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
    return 0; // but t should never start
}

void AVLTree::clear()
{
    while (!isEmpty())
    {
        remove(root->key);
    }
}

// Show methods

void AVLTree::drawTree() const
{
    draw(root);
}

void AVLTree::paintTree(QPainter *painter) const
{
    paint(root, painter, 0, 0);
}

//--------------- /PUBLIC METHODS -------------------------
