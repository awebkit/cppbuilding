#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define OPEN_MODE (O_RDWR | O_NONBLOCK)
#define WRITE_MODE (O_RDWR | O_CREAT)

int main()
{
    int rfd = open("readfile", OPEN_MODE);
    if (rfd < 0)
        printf("open file 'readfile' error!\n");

    int wfd = open("writefile", WRITE_MODE);
    if (wfd < 0)
        printf("write file 'writefile' error!\n");

    char ptr[1024];
    int status = 0;
    int count;
    long time1 = times(0);
    while((count = read(rfd, ptr, 1024)) != status){
        if (count < 0){
            if (errno == EINTR){
                long time2 = times(0);
                if (time2- time1 > 100)
                    return -4;
                continue;
            }else
                return -3;
        }
        printf("read %s\n", ptr);
        write(wfd, ptr, count);
    }

    close(rfd);
    close(wfd);
    return 0;
}
