#include <iostream>

#include "libbar.h"
#include "libnewbar.h"

using namespace std;

int main()
{
    libbar* bar = new libbar();

    bar->callFooGetA();
    bar->callFooIncrease1A();
    bar->callFooGetA();

    libnewbar* newbar = new libnewbar();

    newbar->callFooGetA();
    newbar->callFooIncrease2A();
    newbar->callFooGetA();

    bar->callFooGetA();
}
