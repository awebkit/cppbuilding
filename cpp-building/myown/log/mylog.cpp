#include <stdio.h>


#define LOG(channel, ...) \
    do { \
        printf(__VA_ARGS__); \
        printf("\n"); \
    } while(0)

enum {
    CHANNEL_ONE,
    CHANNEL_TWO,
};
int main()
{
    int a = 10;
    const char *b = "new test";
    LOG(CHANNEL_ONE, "test %d", a);
    LOG(CHANNEL_TWO, "test %s", b);
    return 0;
}
