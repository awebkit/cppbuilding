#include "libnewbar.h"

libnewbar::libnewbar()
{
    m_foo = new foo();
}

void libnewbar::newbarNewSeta(int a)
{
    m_foo->seta(a);
}

