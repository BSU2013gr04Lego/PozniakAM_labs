#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer
{
    T* obj;
    int* count;

public:
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

    SmartPointer(const SmartPointer& other) :
        obj(other.obj),
        count(other.count)
    {
        (*count)++;
    }

    SmartPointer& operator=(const SmartPointer& other)
    {
        this->obj = other.obj;
        this->count = other.count;
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

    bool operator==(const SmartPointer& other) const
    {
        return this->obj == other.obj;
    }

    bool isNullptr()
    {
        return obj == nullptr;
    }
};

#endif // SMARTPOINTER_H
