#ifndef libbar_h
#define libbar_h

#include "libfoo.h"

class libbar{
public:
    libbar();
    void callFooIncrease1A();
    void callFooIncrease2A();
    void callFooGetA();
private:
    libfoo* m_foo;
};

#endif
