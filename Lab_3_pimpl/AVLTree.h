#ifndef AVLTREE_H
#define AVLTREE_H

/***********************************
 *	Tree can not contain node with value = 0
 *	In the find method zero - error indicator
 *	Bridge - AVLImpl *pimpl;
 *	NVI - virtual int find_phase(int key) const;
 ***********************************/

#include <string>
#include "TreeNode.h"
#include "AVLImpl.h"

class AVLTree
{
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

    void cpy(const AVLNode *node, AVLTree *drain) const;

protected:
    AVLNode *root;
    AVLImpl *pimpl;

    virtual int find_phase(int key) const;

public:
    AVLTree();
    AVLTree(ConsoleImpl *p);
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

    virtual void drawTree() const = 0;
};

#endif // AVLTREE_H
