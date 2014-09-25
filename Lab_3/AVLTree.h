#ifndef AVLTREE_H
#define AVLTREE_H

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
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
    AVLNode *top;

    unsigned char height(AVLNode *node);
    unsigned char heightDiff(AVLNode *node);
    void updateHeight(AVLNode *node);

    AVLNode* ins(int key, int val);
    AVLNode* rmv(int key);

public:
    AVLTree();
    AVLTree(const AVLTree &other);
    AVLTree(AVLTree &&other);
    AVLTree& operator=(const AVLTree &other);
    AVLTree& operator=(AVLTree &&other);
    ~AVLTree();

    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;
    bool isEmpty() const;
};

#endif // AVLTREE_H
