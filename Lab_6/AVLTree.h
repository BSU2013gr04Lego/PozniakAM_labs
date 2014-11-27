#ifndef AVLTREE_H
#define AVLTREE_H

#include <utility>
#include <exception>
#include <iostream>
#include <string>

#include "iterator.h"
#include "Exceptions.h"
#include "SmartPointer.h"

template <typename K, typename V>
struct AVLNode
{
    typedef AVLNode<K, V> Tree_node;
    typedef SmartPointer<Tree_node> Node;

    Node left;
    Node right;
    Node parent;
    unsigned char height;
    K key;
    V value;

    bool hasLeft()
    {
        return left.isNullptr();
    }

    bool hasRight()
    {
        return right.isNullptr();
    }

    bool hasParent()
    {
        return parent.isNullptr();
    }

    // Constructor
    AVLNode(K key, V val, Node parent = Node(nullptr))
    {
        this->key = key;
        this->value = val;
        this->left = Node(nullptr);
        this->right = Node(nullptr);
        this->parent = parent;
        this->height = 1;
    }
};

template <typename K, typename V>
class AVLTree
{
private:
    typedef AVLNode<K, V> Tree_node;
    typedef SmartPointer<Tree_node> Node;

public:
    typedef Iterator_implementation<SmartPointer<Tree_node>, AVLTree<K, V>, V> Iterator;

private:
    friend Iterator;

    Node root;

    unsigned char height(Node node) const
    {
        if (!(node== Node()))
            return node->height;
        return 0;
    }

    char heightDiff(Node node) const
    {
        return height(node->right) - height(node->left);
    }

    void updateHeight(Node node)
    {
        unsigned char leftHeight = height(node->left);
        unsigned char rightHeight = height(node->right);
        if (leftHeight > rightHeight)
            node->height = leftHeight + 1;
        else
            node->height = rightHeight + 1;
    }

    Node ins(Node node, K key, V val, Node parent = nullptr)
    {
        if (node == Node())
            return Node(new Tree_node(key, val, parent));
        if (key < node->key)
            node->left = ins(node->left, key, val, node);
        else if (key > node->key)
            node->right = ins(node->right, key, val, node);
        else // key == node->key
        {
            node->key = key;
            node->value = val;
        }
        return balance(node);
    }

    Node rmv(Node node, K key)
    {
        if (node == Node())
            return nullptr;
        if (key < node->key)
        {
            node->left = rmv(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = rmv(node->right, key);
        }
        else // key == node->key
        {
            Node left = node->left;
            Node right = node->right;
            Node parent = node->parent;
            if (right == Node())
            {
                if (!(left == Node()))
                    left->parent = parent;
                return left;
            }
            Node min = findMin(right);
            if (!(min == Node()))
                min->parent = parent;

            min->right = rmMin(right);
            if (!(min->right == Node()))
                min->right->parent = min;

            min->left = left;
            if (!(min->left == Node()))
                min->left->parent = min;
            return balance(min);
        }
        return balance(node);
    }

    Node findMin(Node node) const
    {
        if (!(node->left == Node()))
            return findMin(node->left);
        return node;
    }

    Node rmMin(Node node)
    {
        if (node->left == Node())
        {
            if (!(node->right == Node()))
                node->right->parent = node->parent;
            return node->right;
        }
        node->left = rmMin(node->left);
        return balance(node);
    }

    Node rotateL(Node node)
    {
        Node parent = node->parent;
        Node nodeR = node->right;
        if (!(nodeR == Node()))
            nodeR->parent = parent;

        node->right = nodeR->left;
        if (!(node->right == Node()))
            node->right->parent = node;

        nodeR->left = node;
        if (!(nodeR->left == Node()))
            nodeR->left->parent = nodeR;

        updateHeight(nodeR->left);
        updateHeight(nodeR);
        return nodeR;
    }

    Node rotateR(Node node)
    {
        Node parent = node->parent;
        Node nodeL = node->left;
        if (!(nodeL == Node()))
            nodeL->parent = parent;

        node->left = nodeL->right;
        if (!(node->left == Node()))
            node->left->parent = node;

        nodeL->right = node;
        if (!(nodeL->right == Node()))
            nodeL->right->parent = nodeL;

        updateHeight(nodeL->right);
        updateHeight(nodeL);
        return nodeL;
    }

    Node balance(Node node)
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

    void draw(Node node, std::string s) const
    {
        if (!(node == Node()))
        {
            std::cout << (s.length() ? (s.substr(0, s.length() - 4) + "|---") : "")
                      << "(" << node->key << ", " << node->value << "):[" << (int)node->height << "]" << std::endl;
            draw(node->right, s + "|   ");
            draw(node->left, s + "    ");
        }
    }

    void cpy(const Node node, AVLTree<K, V> *drain) const
    {
        drain->insert(node->key, node->value);
        if (!(node->left == Node()))
            cpy(node->left, drain);
        if (!(node->right == Node()))
            cpy(node->right, drain);
    }

    bool isThere(K key)
    {
        Node current = root;
        if (current == Node())
        {
            return false;
        }
        while (current->key != key)
        {
            if (key < current->key)
                current = current->left;
            else if (key > current->key)
                current = current->right;
            if (current == Node())
                return false;
        }
        return true;
    }

    // Iterator methods

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
        return root == Node();
    }

    void insert(K key, V val)
    {
        if (isThere(key))
        {
            throw Insert_AVLException();
        }
        root = ins(root, key, val);
    }

    void remove(K key)
    {
        if (!isThere(key))
        {
            throw Remove_AVLException();
        }
        root = rmv(root, key);
    }

    int find(K key) const
    {
        Node *current = root;
        if (!current)
        {
            throw Find_AVLException();
        }
        while (current->key != key)
        {
            if (key < current->key)
                current = current->left;
            else if (key > current->key)
                current = current->right;
            if (!current)
            {
                throw Find_AVLException();
            }
        }
        return current->value;
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

    // Iterator methods

    Iterator begin() const
    {
        Node node = root;
        while (node->hasLeft())
            node = node->left;
        return Iterator(this, node);
    }

    Iterator end() const
    {
        return Iterator(this, nullptr);
    }

    // Debug methods
    void drawTree() const
    {
        draw(root, "");
    }
};

#endif // AVLTREE_H
