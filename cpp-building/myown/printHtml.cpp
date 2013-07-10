#include <iostream>

using namespace std;

const char* html = "<html><body><h2>it is title</h2><p>it is text</p></body></html>";
int main()
{
    deque<string> dq;
    char* c = html;
    for (;c!=0;){
        if (c == '<'){ //left tag
            char* n = ++c;
            if (n != '/'){ // left tag
                char* e = n;
                for(;e!='>';++e);
                dq.push_back();
                c = ++e;
            } else {
            }
        } else {//
        }
    }
    return 0;
}
