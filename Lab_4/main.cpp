#include <iostream>
#include "BeautyCAVL.h"

using namespace std;

int main()
{
    BeautyCAVL tree;
    for (int i = 0; i < 40; ++i)
    {
        tree.insert(i, i * 10);
    }

	/*
    tree.insert(2, 10);
    tree.draw();
    cout << "=================" << endl;
    tree.insert(1, 20);
    tree.draw();
    cout << "=================" << endl;
    tree.insert(0, 30);
    tree.draw();
    cout << "=================" << endl;
    tree.insert(3, 40);
    tree.draw();
    cout << "=================" << endl;
    tree.remove(3);
    tree.draw();
    cout << "=================" << endl;
    tree.remove(2);

    tree.draw();
    cout << "=================" << endl;
    */

    BeautyCAVL new_tree(tree);
    new_tree.insert(55, 155);
    BeautyCAVL new_tree2(new_tree);
    new_tree2.remove(1);
    tree.clear();
    cout << tree.isEmpty() << endl;
    tree.draw();
    new_tree.draw();
    new_tree2.draw();
    cout << new_tree2.find(10) << " " << new_tree2.isEmpty() << endl;
    new_tree2 = new_tree;
    new_tree2.draw();
    return 0;
}
