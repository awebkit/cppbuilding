#include "libfoo.h"
#include <iostream>

using namespace std;
#if TEST_GLOBAL
int libfoo::m_a = 10;
#endif

libfoo::libfoo()
#if !TEST_GLOBAL
    :m_a(100)
#endif
{
}

void libfoo::increase1A()
{
    m_a++;
}

void libfoo::getA()
{
    cout << m_a << endl;
}

void libfoo::increase2A()
{
    m_a += 2;
}
