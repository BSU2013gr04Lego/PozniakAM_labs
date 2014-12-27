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
        count = new int();
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
        if (count)
        {
            (*count)--;
            if (*count < 1)
            {
                delete obj;
                delete count;
            }
        }
    }

    T* operator->() const
    {
        return obj;
    }

    T& operator*() const
    {
        return *obj;
    }

    bool operator==(const SmartPointer& spointer) const
    {
        return this->obj == spointer.obj;
    }

    bool isNullptr()
    {
        return obj == nullptr;
    }
};

#endif // SMARTPOINTER_H
