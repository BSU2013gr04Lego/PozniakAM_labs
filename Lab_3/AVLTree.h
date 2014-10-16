#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include "TreeNode.h"

class AVLTree
{
    AVLNode *root;

    unsigned char height(AVLNode *node) const;
    char heightDiff(AVLNode *node) const;
    void updateHeight(AVLNode *node);

    AVLNode* ins(AVLNode *node, int key, int val);
    AVLNode* rmv(AVLNode *node, int key);
    AVLNode* findMin(AVLNode *node) const;
    AVLNode* rmMin(AVLNode *node);

    AVLNode* rotateL(AVLNode *node);
    AVLNode* rotateR(AVLNode *node);
    AVLNode* balance(AVLNode *node);

    void draw(AVLNode *node, std::string s) const;

    void cpy(const AVLNode *node, AVLTree *drain) const;

public:
    AVLTree();
    AVLTree(const AVLTree &other);
    AVLTree(AVLTree &&other);
    AVLTree& operator=(const AVLTree &other);
    AVLTree& operator=(AVLTree &&other);
    ~AVLTree();

    // Binary tree methods
    bool isEmpty() const;
    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;
    void copy(AVLTree *drain) const; // copy this within drain
    void clear();

    // Debug methods
    void drawTree() const;
};

#endif // AVLTREE_H
