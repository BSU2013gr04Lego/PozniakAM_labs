#ifndef ITERATOR_H
#define ITERATOR_H

template <typename Node, typename Tree, typename T>
class Iterator_implementation
{
    friend Tree;

    Node* node_ptr;
    const Tree* parent;

    Iterator_implementation(const Tree *parent, Node *node) :
        parent(parent),
        node_ptr(node)
    {
    }

public:
    Iterator_implementation() :
        parent(nullptr),
        node_ptr(nullptr)
    {
    }

    Iterator_implementation(const Iterator_implementation &iter) :
        parent(iter.parent),
        node_ptr(iter.node_ptr)
    {
    }

    Iterator_implementation& operator=(const Iterator_implementation &iter)
    {
        parent = iter.parent;
        node_ptr = iter.node_ptr;
        return *this;
    }

    ~Iterator_implementation()
    {
    }

    T operator*()
    {
        return node_ptr->value;
    }

    T operator->()
    {
        return node_ptr->value;
    }

    void operator++()
    {
        if (node_ptr->right)
        {
            node_ptr = node_ptr->right;
            while (node_ptr->left)
                node_ptr = node_ptr->left;
        } else
        {
            while (node_ptr->parent)
            {
                if (node_ptr == node_ptr->parent->right)
                    node_ptr = node_ptr->parent;
                else
                {
                    node_ptr = node_ptr->parent;
                    return;
                }
            }
        }
        node_ptr = nullptr;
    }

    Iterator_implementation operator++(int)
    {
        Iterator_implementation iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(Iterator_implementation const &i)
    {
        return (node_ptr == i.node_ptr) && (parent == i.parent);
    }

    bool operator!=(Iterator_implementation const &i)
    {
        return !(*this == i);
    }
};

#endif // ITERATOR_H
