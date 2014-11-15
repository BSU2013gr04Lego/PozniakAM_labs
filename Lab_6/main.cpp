#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree<int, string> tree, new_tree;

    for (int i = 0; i < 40; ++i)
    {
        tree.insert(i, "Leaf");
        cout << "**************************" << endl;
        tree.drawTree();
    }


    tree.insert(2, "BEAR");
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(1, "APPLE");
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(0, "TREE");
    tree.drawTree();
    cout << "=================" << endl;
    tree.insert(3, "BATMAN");
    tree.drawTree();
    cout << "=================" << endl;
    tree.remove(3);
    tree.drawTree();
    cout << "=================" << endl;
    tree.remove(2);

    tree.drawTree();
    cout << "=================" << endl;

    new_tree = tree;
    new_tree.drawTree();
    return 0;
}

// TODO у вас у гэтай дэрэкторыі не заліты файл AVLnode.h
