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
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
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

    AVLNode* rotateL(AVLNode *node);
    AVLNode* rotateR(AVLNode *node);
    AVLNode* balance(AVLNode *node);

    void draw(AVLNode *node) const;

public:
    AVLTree();
    AVLTree(AVLTree &other);
    AVLTree(AVLTree &&other);
    AVLTree& operator=(AVLTree &other);
    AVLTree& operator=(AVLTree &&other);
    ~AVLTree();

    // Binary tree methods
    bool isEmpty() const;
    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;
    void clear();

    // Methods for balancing

    // Debug methods
    void drawTree() const;
};

#endif // AVLTREE_H
