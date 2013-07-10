#ifndef RefCounted_h
#define RefCounted_h
#include <iostream>

using namespace std;
class RefCountedBase {
public:
    void ref()
    {
        ++m_refCount;
        cout << "refCount:" << m_refCount << endl;
    }

    bool hasOneRef() const
    {
        return m_refCount == 1;
    }

    int refCount() const
    {
        return m_refCount;
    }
protected:
    RefCountedBase()
        : m_refCount(1)
    {
    }

    ~RefCountedBase()
    {
    }

    // Returns whether the pointer should be freed or not.
    bool derefBase()
    {
        cout << "derefBase: refCount:" << m_refCount << endl;
        if (m_refCount == 1) {
            return true;
        }

        --m_refCount;
        return false;

    }

private:

    int m_refCount;
};

template<typename T> class RefCounted : public RefCountedBase {
public:
    void deref()
    {
        cout << "deref" << endl;
        if (derefBase()) {
            cout << "delete " <<endl;
            delete static_cast<T*>(this);
        } else 
            cout << "not delete " << endl;
    }

protected:
    RefCounted() { }
    ~RefCounted()
    {
    }
};

#endif
