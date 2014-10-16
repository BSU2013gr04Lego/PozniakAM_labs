#include "TreeNode.h"

AVLNode::AVLNode(int key, int val)
{
    this->key = key;
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}
