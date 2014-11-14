#ifndef AVLTREE_H
#define AVLTREE_H

#include <utility>
#include <exception>
#include <iostream>
#include <string>

template <typename K, typename V> struct AVLNode
{
    AVLNode<K, V> *left;
    AVLNode<K, V> *right;
    unsigned char height;
    K key;
    V value;

    // Constructor
    AVLNode(K key, V val)
    {
        this->key = key;
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

template <typename K, typename V> class AVLTree
{
    AVLNode<K, V> *root;

    unsigned char height(AVLNode<K, V> *node) const
    {
        if (node)
            return node->height;
        return 0;
    }

    char heightDiff(AVLNode<K, V> *node) const
    {
        return height(node->right) - height(node->left);
    }

    void updateHeight(AVLNode<K, V> *node)
    {
        unsigned char leftHeight = height(node->left);
        unsigned char rightHeight = height(node->right);
        if (leftHeight > rightHeight)
            node->height = leftHeight + 1;
        else
            node->height = rightHeight + 1;
    }

    AVLNode<K, V>* ins(AVLNode<K, V> *node, K key, V val)
    {
        if (!node)
            return new AVLNode<K, V>(key, val);
        if (key < node->key)
            node->left = ins(node->left, key, val);
        else
            node->right = ins(node->right, key, val);
        return balance(node);
    }

    AVLNode<K, V>* rmv(AVLNode<K, V> *node, K key)
    {
        if (!node)
            return nullptr;
        if (key < node->key)
        {
            node->left = rmv(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = rmv(node->right, key);
        }
        else
        {
            AVLNode<K, V> *left = node->left;
            AVLNode<K, V> *right = node->right;
            delete node;
            if (!right)
                return left;
            AVLNode<K, V> *min = findMin(right);
            min->right = rmMin(right);
            min->left = left;
            return balance(min);
        }
        return balance(node);
    }

    AVLNode<K, V>* findMin(AVLNode<K, V> *node) const
    {
        if (node->left)
            return findMin(node->left);
        return node;
    }

    AVLNode<K, V>* rmMin(AVLNode<K, V> *node)
    {
        if (!(node->left))
            return node->right;
        node->left = rmMin(node->left);
        return balance(node);
    }

    AVLNode<K, V>* rotateL(AVLNode<K, V> *node)
    {
        AVLNode<K, V> *nodeR = node->right;
        node->right = nodeR->left;
        nodeR->left = node;
        updateHeight(nodeR->left);
        updateHeight(nodeR);
        return nodeR;
    }

    AVLNode<K, V>* rotateR(AVLNode<K, V> *node)
    {
        AVLNode<K, V> *nodeL = node->left;
        node->left = nodeL->right;
        nodeL->right = node;
        updateHeight(nodeL->right);
        updateHeight(nodeL);
        return nodeL;
    }

    AVLNode<K, V>* balance(AVLNode<K, V> *node)
    {
        updateHeight(node);
        if (heightDiff(node) == 2)
        {
            if (heightDiff(node->right) == -1)
                node->right = rotateR(node->right);
            return rotateL(node);
        }
        else if (heightDiff(node) == -2)
        {
            if (heightDiff(node->left) == 1)
                node->left = rotateL(node->left);
            return rotateR(node);
        }
        return node;
    }

    void draw(AVLNode<K, V> *node, std::string s) const
    {
        if (node)
        {
            std::cout << (s.length() ? (s.substr(0, s.length() - 4) + "|---") : "")
                 << "(" << node->key << ", " << node->value << "):[" << (int)node->height << "]" << std::endl;
            draw(node->right, s + "|   ");
            draw(node->left, s + "    ");
        }
    }

    void cpy(const AVLNode<K, V> *node, AVLTree<K, V> *drain) const
    {
        drain->insert(node->key, node->value);
        if (node->left)
            cpy(node->left, drain);
        if (node->right)
            cpy(node->right, drain);
    }

public:
    AVLTree() : root(nullptr)
    {
    }

    AVLTree(const AVLTree<K, V> &other) : root(nullptr)
    {
        other.copy(this);
    }

    AVLTree(AVLTree<K, V> &&other) : root(nullptr)
    {
        swap (this->root, other.root);
    }

    AVLTree<K, V>& operator=(const AVLTree<K, V> &other)
    {
        if (this != &other)
        {
            other.copy(this);
        }
        return *this;
    }

    AVLTree<K, V>& operator=(AVLTree<K, V> &&other)
    {
        swap (this->root, other.root);
        return *this;
    }

    ~AVLTree()
    {
        while (!isEmpty())
        {
            remove(root->key);
        }
    }

    // Binary tree methods
    bool isEmpty() const
    {
        return !root;
    }

    void insert(K key, V val)
    {
        root = ins(root, key, val);
    }

    void remove(K key)
    {
        root = rmv(root, key);
    }

    int find(K key) const
    {
        AVLNode<K, V> *current = root;
        if (!current)
        {
            throw std::exception();
        }
        while (current->key != key)
        {
            if (key < current->key)
            {
                current = current->left;
            }
            if (key > current->key)
            {
                current = current->right;
            }
            if (key == current->key)
            {
                return current->value;
            }
        }
    }

    void copy(AVLTree<K, V> *drain) const
    {
        drain->clear();
        cpy(root, drain);
    } // copy this within drain

    void clear()
    {
        while (!isEmpty())
        {
            remove(root->key);
        }
    }

    // Debug methods
    void drawTree() const
    {
        draw(root, "");
    }
};

#endif // AVLTREE_H
