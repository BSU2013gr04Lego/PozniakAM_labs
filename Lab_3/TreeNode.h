#ifndef TREENODE_H
#define TREENODE_H

struct AVLNode
{
    AVLNode *left;
    AVLNode *right;
    unsigned char height;
    int key;
    int value;

    // Constructor
    AVLNode(int key, int val)
    {
        this->key = key;
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

#endif // TREENODE_H
