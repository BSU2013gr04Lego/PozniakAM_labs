#ifndef BEAUTYCAVL_H
#define BEAUTYCAVL_H

#include "ConsoleAVL.h"

class BeautyCAVL : public ConsoleAVL
{
protected:
	void draw_phase() const;

public:
    BeautyCAVL();
    BeautyCAVL(BeautyCAVL &other);
    BeautyCAVL(BeautyCAVL &&other);
    BeautyCAVL& operator=(BeautyCAVL &other);
    BeautyCAVL& operator=(BeautyCAVL &&other);
    ~BeautyCAVL();

    void draw() const;
};

#endif // BEAUTYCAVL_H
