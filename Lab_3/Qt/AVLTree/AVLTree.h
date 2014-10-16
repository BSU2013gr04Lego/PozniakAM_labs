#ifndef AVLTREE_H
#define AVLTREE_H

#include <QPainter>
#include "AVLNode.h"

#ifndef WIDTH
#define WIDTH 80
#define HEIGHT 60
#endif

class AVLTree
{
    AVLNode *root;

    unsigned char height(AVLNode *node) const;
    unsigned char heightDiff(AVLNode *node) const;
    void updateHeight(AVLNode *node);

    AVLNode* ins(AVLNode *node, int key, int val);
    AVLNode* rmv(AVLNode *node, int key);
    AVLNode* findMin(AVLNode *node) const;
    AVLNode* rmMin(AVLNode *node);

    AVLNode* rotateL(AVLNode *node);
    AVLNode* rotateR(AVLNode *node);
    AVLNode* balance(AVLNode *node);

    void draw(AVLNode *node) const;
    int paint(AVLNode * node, QPainter *painter, int row, int column) const;

public:
    AVLTree();
    AVLTree(AVLTree &other);
    AVLTree(AVLTree &&other);
    AVLTree& operator=(AVLTree &other);
    AVLTree& operator=(AVLTree &&other);
    ~AVLTree();

    // Binary tree methods
    unsigned char rootHeight() const;
    bool isEmpty() const;
    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;
    void clear();

    // Show methods
    void drawTree() const;
    void paintTree(QPainter *painter) const;
};

#endif // AVLTREE_H
