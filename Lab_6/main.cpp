#include <iostream>
#include <string>
#include "AVLTree.h"
#include "SmartPointer.h"

using namespace std;

int main()
{
    typedef AVLTree<int, int> AVLTree;

    SmartPointer<AVLTree> tree(new AVLTree);

    cout << endl << "******* BASIC SECTION *******" << endl;
    for (int i = 0; i < 40; ++i)
    {
        tree->insert(i, i);
        for (AVLTree::Iterator it = tree->begin(); it != tree->end(); ++it)
        {
            cout << *(it) << " ";
        }
        cout << endl << endl;
    }
/*
    tree->insert(2, 1);
    tree->insert(2, 2);
    tree->insert(2, 3);
    tree->drawTree();
    cout << "=================" << endl;
    tree->insert(1, 4);
    tree->drawTree();
    cout << "=================" << endl;
    tree->insert(0, 1);
    tree->drawTree();
    cout << "=================" << endl;
    tree->insert(3, 6);
    tree->drawTree();
    cout << "=================" << endl;
    tree->remove(3);
    tree->drawTree();
    cout << "=================" << endl;
    tree->remove(2);
*/
    AVLTree safe = *(tree);
    cout << endl << "***** TRY/CATCH SECTION *****" << endl;
    try
    {
        tree->remove(3);
        tree->remove(3);
        tree->remove(2);
        tree->insert(3, 42);
    } catch (const exception& e)
    {
        *(tree) = safe;
        cerr << e.what() << endl;
    }

    cout << endl << "******* COUT SECTION ********" << endl;
    tree->drawTree();
    cout << endl << "***** ITERATOR SECTION ******" << endl;
    for (AVLTree::Iterator it = tree->begin(); it != tree->end(); ++it)
    {
        cout << *(it) << endl;
    }

    return 0;
}
