#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string map("2223334445556667#77888999#"); 
          //ABCDEFGHIJKLMNOPQRSTUVWXYZ
char s[40];

int convert();   // convert s to standard form s1

int main()
{
    int n, cnt;

    scanf("%d", &n); getchar();
    vector<int> ivec(n);
    for (int i = 0; i < n; i++) {
        gets(s);
        ivec[i] = convert();
    }
    sort(ivec.begin(), ivec.end());

    // output the result
    bool no_duplicate = true;
    for (int i = 1; i < n; i++) {
        cnt = 1;
        while (i < n && ivec[i] == ivec[i - 1]) {
            cnt++;
            i++;
        }
        if (cnt > 1) {
            printf("%03d-%04d %d\n", ivec[i-1]/10000, ivec[i-1]%10000, cnt);
            no_duplicate = false;
        }
    }
    if (no_duplicate)
        printf("No duplicates. \n");

    return 0;
}

int convert()
{
    int sum = 0;
    for (unsigned i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            sum = sum * 10 + (s[i] - '0');
        else if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'Q' && s[i] != 'Z')
            sum = sum * 10 + (map[s[i] - 'A'] - '0');
    }
    
    return sum;
}
