#ifndef CONSOLEAVL_H
#define CONSOLEAVL_H

#include "AVLTree.h"

class ConsoleAVL : public AVLTree
{
public:
    ConsoleAVL();
    ConsoleAVL(ConsoleImpl *p);
    ConsoleAVL(ConsoleAVL &other);
    ConsoleAVL(ConsoleAVL &&other);
    ConsoleAVL& operator=(ConsoleAVL &other);
    ConsoleAVL& operator=(ConsoleAVL &&other);
    ~ConsoleAVL();

    void drawTree() const;
};

#endif // CONSOLEAVL_H
