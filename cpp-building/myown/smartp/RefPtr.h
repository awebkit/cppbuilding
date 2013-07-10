#ifndef WTF_RefPtr_h
#define WTF_RefPtr_h

#include <iostream>
#include "PassRefPtr.h"
using namespace std;

template<typename T> class RefPtr {
public:
    ALWAYS_INLINE RefPtr() : m_ptr(0) { cout << "RefPtr()" << endl;} 
    ALWAYS_INLINE RefPtr(T* ptr) : m_ptr(ptr) { refIfNotNull(ptr); }
    ALWAYS_INLINE RefPtr(const RefPtr& o) : m_ptr(o.m_ptr) { refIfNotNull(m_ptr); }
    template<typename U> RefPtr(const RefPtr<U>& o) : m_ptr(o.get()) { refIfNotNull(m_ptr); }

    template<typename U> RefPtr(const PassRefPtr<U>&);

    ALWAYS_INLINE ~RefPtr() { cout << "~RefPtr()" << endl; derefIfNotNull(m_ptr); }

    T* get() const { return m_ptr; }

    RefPtr& operator=(const RefPtr&);
    RefPtr& operator=(T*);
private:
        T* m_ptr;
};

template<typename T> template<typename U> inline RefPtr<T>::RefPtr(const PassRefPtr<U>& o)
: m_ptr(o.leakRef())
{   
}

template<typename T> inline RefPtr<T>& RefPtr<T>::operator=(const RefPtr<T>& o)
{
    cout << "operator=(const RefPtr<T>& o)" << endl;   
    T* optr = o.get();
    refIfNotNull(optr);
    T* ptr = m_ptr;
    m_ptr = optr;
    derefIfNotNull(ptr);
    return *this;
} 

template<typename T> inline RefPtr<T>& RefPtr<T>::operator=(T* optr)
{
    cout << "operator =" << endl;
    refIfNotNull(optr);
    T* ptr = m_ptr;
    m_ptr = optr;
    derefIfNotNull(ptr);
    return *this;
}

#endif
