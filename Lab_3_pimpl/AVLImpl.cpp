#include "AVLImpl.h"

#include <string>
#include <iostream>

using namespace std;

AVLImpl::~AVLImpl()
{
}

ConsoleImpl::~ConsoleImpl()
{
}

void ConsoleImpl::draw(AVLNode *node, string s) const
{
    if (node)
    {
        cout << (s.length() ? (s.substr(0, s.length() - 4) + "|---") : "") << "(" << node->key << ", " << node->value << "):[" << (int)node->height << "]" << endl;
        draw(node->right, s + "|   ");
        draw(node->left, s + "    ");
    }
}
