#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

class AVLTree
{
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

protected:
    void makeVisit(void (*visitor)(int key, int val, std::string s)) const;

private:
    class AVLImpl;
    AVLImpl *pimpl;
};

#endif // AVLTREE_H
