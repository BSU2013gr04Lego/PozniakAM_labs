#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer
{
    T* obj;
    int* count;

public:
    // Constructor
    SmartPointer() :
        obj(nullptr),
        count(nullptr)
    {
    }

    SmartPointer(T *obj) :
        obj(obj)
    {
        count = new int;
        (*count)++;
    }

    SmartPointer(const SmartPointer& spointer) :
        obj(spointer.obj),
        count(spointer.count)
    {
        (*count)++;
    }

    SmartPointer& operator=(const SmartPointer& spointer)
    {
        this->obj = spointer.obj;
        this->count = spointer.count;
        (*count)++;
    }

    ~SmartPointer()
    {
        (*count)--;
        if (*count < 1)
        {
            delete obj;
            delete count;
        }
        obj = nullptr;
        count = nullptr;
    }

    T* operator->()
    {
        return obj;
    }

    T& operator*()
    {
        return *obj;
    }
};

#endif // SMARTPOINTER_H
