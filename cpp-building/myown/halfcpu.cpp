#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int busy = 10;
    int idle = busy;

    for (int i = 0; i < 1000000000; ++i){
        time_t start = time(0); 
        while(time(0) - start < busy)
            ;
        sleep(idle);
        
    }
}
