#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree tree, new_tree;

    for (int i = 0; i < 40; ++i)
    {
        tree.insert(i, i * 10);
    }

    /*
    tree.insert(2, 10);
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(1, 20);
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(0, 30);
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(3, 40);
    tree.drawTree();
    cout << "=================" << endl;
    tree.remove(3);
    tree.drawTree();
    cout << "=================" << endl;
    tree.remove(2);
    */
    tree.drawTree();
    cout << "=================" << endl;

    new_tree = tree;
    new_tree.drawTree();
    return 0;
}
