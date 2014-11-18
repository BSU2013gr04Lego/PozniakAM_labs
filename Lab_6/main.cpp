#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

int main()
{
    typedef AVLTree<int, int> AVLTree;

    AVLTree tree, new_tree;

    for (int i = 0; i < 40; ++i)
    {
        tree.insert(i, i);
    }
/*
    tree.insert(2, 1);
    tree.insert(2, 2);
    tree.insert(2, 3);
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(1, 4);
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(0, 1);
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(3, 6);
    tree.drawTree();
    cout << "=================" << endl;
    tree.remove(3);
    tree.drawTree();
    cout << "=================" << endl;
    tree.remove(2);
*/

    tree.remove(3);
    tree.remove(2);
    cout << "**************************" << endl;
    tree.drawTree();
    cout << "=========Iterator========" << endl;

    for (AVLTree::Iterator it = tree.begin(); it != tree.end(); ++it)
    {
        cout << *(it) << endl;
    }
    return 0;
}
