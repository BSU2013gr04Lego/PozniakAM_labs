#ifndef CONSOLEAVL_H
#define CONSOLEAVL_H

#include "AVLTree.h"

class ConsoleAVL : public AVLTree
{
protected:
    virtual int find_phase(int key) const;

public:
    ConsoleAVL();
    ConsoleAVL(ConsoleImpl *p);
    ConsoleAVL(ConsoleAVL &other);
    ConsoleAVL(ConsoleAVL &&other);
    ConsoleAVL& operator=(ConsoleAVL &other);
    ConsoleAVL& operator=(ConsoleAVL &&other);
    virtual ~ConsoleAVL();

    void drawTree() const;
};

#endif // CONSOLEAVL_H
