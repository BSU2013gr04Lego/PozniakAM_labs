#ifndef CONSOLEAVL_H
#define CONSOLEAVL_H

#include "AVLTree.h"

class ConsoleAVL : public AVLTree
{
protected:
	void draw_phase() const;

public:
    ConsoleAVL();
    ConsoleAVL(ConsoleAVL &other);
    ConsoleAVL(ConsoleAVL &&other);
    ConsoleAVL& operator=(ConsoleAVL &other);
    ConsoleAVL& operator=(ConsoleAVL &&other);
    virtual ~ConsoleAVL();

    void draw() const;
};

#endif // CONSOLEAVL_H
