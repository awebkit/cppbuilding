#ifndef libnewbar_h
#define libnewbar_h

#include "libfoo.h"

class libnewbar{
public:
    libnewbar();
    void callFooIncrease1A();
    void callFooIncrease2A();
    void callFooGetA();
private:
    libfoo* m_foo;
};

#endif
