#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class DNAString{
public:
    DNAString(char* s):m_str(s){
        m_key = 0;
        for (int i = 0; i < m_str.length(); ++i){
            char t = m_str[i];
            for (int j = i; j < m_str.length(); ++j){
                if (t > m_str[j])
                    m_key++;
            }
        }
    }

    int getKey(){return m_key;}
    void setKey(int k) { m_key = k;}

    string getString() {return m_str;}
    void setString(string s) {
        m_str = s;
    } 


private:
    string m_str;
    int m_key;
};

vector<DNAString> myvector;

void mysort(int l, int u)
{
    //insert sort
    for (int i = l + 1; i <= u; ++i){
        int j = i;
        int k = myvector[i].getKey();
        string s = myvector[i].getString();
        for(j = i; j > 0 && k < myvector[j - 1].getKey(); j--){
            myvector[j].setString(myvector[j-1].getString());
            myvector[j].setKey(myvector[j-1].getKey());
        }
        myvector[j].setString(s);
        myvector[j].setKey(k);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    char s[64];

    while(m--){
        fscanf(stdin, "%s", s);
        DNAString tmp(s);
        myvector.push_back(tmp);
    }
    
    vector<DNAString>::iterator it;

    mysort(0, myvector.size() - 1);

    for (it = myvector.begin(); it != myvector.end(); ++it){
        cout << it->getString() << endl;
    }

    return 0;
}
