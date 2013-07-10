#include "libbar.h"

using namespace std;

libbar::libbar()
    :m_foo(new libfoo())
{
}

void libbar::callFooIncrease1A()
{
    m_foo->increase1A();
}

void libbar::callFooIncrease2A()
{
    m_foo->increase2A();
}

void libbar::callFooGetA()
{
    m_foo->getA();
}
