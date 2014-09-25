#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    cout << ";ldne >> 'cout << ';ldne >> 'cout << ' ' << endl; ' >> tuoc' << endl; ' >> tuoc" << endl;

    AVLTree tree;
    tree.insert(2, 10);
    //tree.drawTree(tree.getRoot());
    tree.insert(1, 20);
    //tree.drawTree(tree.getRoot());
    tree.insert(0, 30);
    //tree.drawTree(tree.getRoot());
    tree.insert(3, 40);
    //tree.drawTree(tree.getRoot());
    //tree.remove(3);
    //tree.drawTree(tree.getRoot());
    //tree.remove(2);
    tree.drawTree(tree.getRoot());
    return 0;
}
