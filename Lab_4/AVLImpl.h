#ifndef AVLIMPLE_H
#define AVLIMPLE_H

#include "AVLTree.h"
#include <string>

class AVLTree::AVLImpl
{
    struct AVLNode
    {
        AVLNode *left;
        AVLNode *right;
        int height;
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
    } *root;

    int height(const AVLNode *node) const;
    char heightDiff(const AVLNode *node) const;
    void updateHeight(AVLNode *node);

    AVLNode* findMin(AVLNode *node) const;
    AVLNode* rmMin(AVLNode *node);

    AVLNode* rotateL(AVLNode *node);
    AVLNode* rotateR(AVLNode *node);
    AVLNode* balance(AVLNode *node);

	AVLNode* ins(AVLNode *node, int key, int val);
    AVLNode* rmv(AVLNode *node, int key);
	void cp(const AVLNode *node, AVLImpl *drain) const;
    void mkVisit(void (*visitor)(int key, int val, std::string s), const AVLNode *node, std::string s) const;

public:
    AVLImpl();
    AVLImpl(const AVLImpl &other);
    AVLImpl(AVLImpl &&other);
    AVLImpl& operator=(const AVLImpl &other);
    AVLImpl& operator=(AVLImpl &&other);
    ~AVLImpl();

	bool isEmpty() const;
    void insert(int key, int val);
    void remove(int key);
    int find(int key) const;
    void copy(AVLImpl *drain) const;
    void clear();

    void makeVisit(void (*visitor)(int key, int val, std::string s)) const;

};

#endif // AVLIMPLE_H
