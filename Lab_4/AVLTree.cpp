#include <utility>
#include <exception>
#include <iostream>
#include <string>
#include "AVLImpl.h"

using namespace std;

//---------------- THE GREAT 6 ----------------------------

AVLTree::AVLTree() :
    pimpl(nullptr)
{
    pimpl = new AVLImpl();
}

AVLTree::AVLTree(const AVLTree &other)
{
	pimpl = new AVLImpl(*(other.pimpl));
}

AVLTree::AVLTree(AVLTree &&other)
{
	pimpl = new AVLImpl(*(other.pimpl));
}

AVLTree& AVLTree::operator=(const AVLTree &other)
{
	other.copy(this);
    return *this;
}

AVLTree& AVLTree::operator=(AVLTree &&other)
{
	other.copy(this);
    return *this;
}

AVLTree::~AVLTree()
{
    delete pimpl;
}

//--------------- /THE GREAT 6 ----------------------------
//---------------  PUBLIC METHODS -------------------------


// Binary tree methods
bool AVLTree::isEmpty() const
{
    return pimpl->isEmpty();
}

void AVLTree::insert(int key, int val)
{
    pimpl->insert(key, val);
}

void AVLTree::remove(int key)
{
	pimpl->remove(key);
}

int AVLTree::find(int key) const
{
    return pimpl->find(key);
}

void AVLTree::copy(AVLTree *drain) const
{
    drain->clear();
    pimpl->copy(drain->pimpl);
}

void AVLTree::clear()
{
	pimpl->clear();
}


void AVLTree::makeVisit(void (*visitor)(int key, int val, std::string s)) const
{
    pimpl->makeVisit(visitor);
}

//--------------- /PUBLIC METHODS -------------------------
