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
    AVLNode *root;

    unsigned char height(AVLNode *node) const;
    unsigned char heightDiff(AVLNode *node) const;
    void updateHeight(AVLNode *node);

    AVLNode* ins(AVLNode *node, int key, int val);
    AVLNode* rmv(AVLNode *node, int key);
    AVLNode* findMin(AVLNode *node) const;
    AVLNode* rmMin(AVLNode *node);

public:
    AVLTree();
    AVLTree(const AVLTree &other);
    AVLTree(AVLTree &&other);
    AVLTree& operator=(const AVLTree &other);
    AVLTree& operator=(AVLTree &&other);
    ~AVLTree();

    bool isEmpty() const;
    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;


    AVLNode* getRoot() const;
    void drawTree(AVLNode *node) const;
};

#endif // AVLTREE_H
