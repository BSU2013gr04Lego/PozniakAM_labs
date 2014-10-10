#ifndef AVLIMPLE_H
#define AVLIMPLE_H

#include "TreeNode.h"
#include <string>

class AVLImpl
{
public:
    virtual ~AVLImpl();
    virtual void draw(AVLNode *node, std::string s) const = 0;
};

class ConsoleImpl : public AVLImpl
{
    ~ConsoleImpl();
    void draw(AVLNode *node, std::string s) const;
};

#endif // AVLIMPLE_H
