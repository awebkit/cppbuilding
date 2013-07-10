#ifndef _AUTOPTR1_H
#define _AUTOPTR1_H

#include <iostream>

using namespace std;
template <class ElementType>
class SimpleAutoPointer {
public:
    // class for the value
    typedef ElementType element_type;

    // constructor
    explicit SimpleAutoPointer(ElementType* pointer = 0) throw() :
        m_Pointer(pointer) {} 

    // copy constructors
    // - note: nonconstant parameter
    SimpleAutoPointer(SimpleAutoPointer& rhs) throw() :
        m_Pointer(rhs.release()) {}
    template <class AnotherElementType>
        SimpleAutoPointer(SimpleAutoPointer<AnotherElementType>& rhs) throw() :
            m_Pointer(rhs.release()) {}

    // assignments
    SimpleAutoPointer& operator=(SimpleAutoPointer& rhs) throw(){
        reset(rhs.release());
    }
    template<class AnotherElementType>
        SimpleAutoPointer& operator=(SimpleAutoPointer<AnotherElementType>& rhs) throw(){
            reset(rhs.release());
        }


    // destructor
    ~SimpleAutoPointer() throw(){
        if ( m_Pointer ) {
            delete m_Pointer;
        }
    }

    // value access
    ElementType* get() const throw(){
        return m_Pointer;
    }
    ElementType& operator*() const throw(){
        return *m_Pointer;
    }
    ElementType* operator->() const throw(){
        return m_Pointer;
    }

    // release ownership
    ElementType* release() throw(){
        ElementType* oldPointer = m_Pointer;
        m_Pointer = 0;
        return oldPointer;
    }

    // reset value
    void reset(ElementType* newPointer) throw(){
        if ( m_Pointer ) {
            delete m_Pointer;
        }

        m_Pointer = newPointer;
    }

private:
    ElementType* m_Pointer;
};

#endif //_AUTOPTR1_H
