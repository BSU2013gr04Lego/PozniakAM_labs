#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    cout << ";ldne >> 'cout << ';ldne >> 'cout << ' ' << endl; ' >> tuoc' << endl; ' >> tuoc" << endl;

    AVLTree tree, new_tree;

    for (int i = 0; i < 10; ++i)
    {
        tree.insert(i, i * 10);
    }

    new_tree = tree;

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
    new_tree.drawTree();
    return 0;
}
