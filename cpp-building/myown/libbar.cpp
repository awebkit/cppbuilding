#include "libbar.h"

using namespace std;

libbar::libbar()
{
    m_foo = new foo();
}
void libbar::fooSeta(int a)
{
    m_foo->seta(a);
}

void libbar::fooGeta()
{
    m_foo->geta();
}
