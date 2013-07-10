#include <iostream>

#include "libfoo.h"
using namespace std;

void foo::seta(int a){m_a = a;}
void foo::newseta(int b){m_a = b;}
void foo::geta(){cout<<m_a<<endl;}
