#include "libnewbar.h"

using namespace std;

libnewbar::libnewbar()
    :m_foo(new libfoo())
{
}

void libnewbar::callFooIncrease1A()
{
    m_foo->increase1A();
}

void libnewbar::callFooIncrease2A()
{
    m_foo->increase2A();
}

void libnewbar::callFooGetA()
{
    m_foo->getA();
}
