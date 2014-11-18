#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class Remove_AVLException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Try to remove unexisting element from AVLTree";
    }
};

class Insert_AVLException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Try to insert existing element to AVLTree";
    }
};

class Find_AVLException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Could not find node with given key";
    }
};

#endif // EXCEPTIONS_H
