#include <iostream>

#include "libbar.h"
#include "libnewbar.h"

using namespace std;

int main()
{
    libbar* bar = new libbar();

    bar->fooSeta(10);
    bar->fooGeta();

    libnewbar* newbar = new libnewbar();
    newbar->newbarNewSeta(20);
    
    bar->fooGeta();

    return 0;
}
