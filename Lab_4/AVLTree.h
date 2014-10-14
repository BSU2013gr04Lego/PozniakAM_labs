#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include "TreeNode.h"
#include "AVLImpl.h"

class AVLTree
{
    AVLImpl *pimpl;

protected:
   void makeVisit(void (*visitor)(const AVLNode *node)) const;

public:
    AVLTree();
    AVLTree(const AVLTree &other);
    AVLTree(AVLTree &&other);
    AVLTree& operator=(const AVLTree &other);
    AVLTree& operator=(AVLTree &&other);
    virtual ~AVLTree();

    // Binary tree methods
    bool isEmpty() const;
    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;
    void copy(AVLTree *drain) const; // copy this within drain
    void clear();
};

#endif // AVLTREE_H
