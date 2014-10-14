#ifndef TREENODE_H
#define TREENODE_H

struct AVLNode
{
    AVLNode *left;
    AVLNode *right;
    int height;
    int key;
    int value;

    // Constructor
    AVLNode(int key, int val);
};

#endif // TREENODE_H
