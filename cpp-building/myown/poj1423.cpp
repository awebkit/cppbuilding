#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

class numWrapper {
public:
    numWrapper(int num, int key)
        : m_num(num),
        m_key(key)
        {}
    int getNum() {return m_num;}
    void setNum(int num) {m_num = num;}
    int getKey() {return m_key;}
    void setKey(int key) {m_key = key;}
    double getCount() {return m_count;}
    void setCount(double count) {m_count = count;}
private:
    int m_num;
    int m_key;
    double m_count;
};

void insort(vector<numWrapper>& numVector)
{
    vector<numWrapper>::iterator i = numVector.begin() + 1;
    for (; i != numVector.end(); ++i) {
        vector<numWrapper>::iterator j = i;
        int num = j->getNum();
        int key = j->getKey();
        for (; j != numVector.begin() && (num < (j-1)->getNum() ); --j){
            j->setNum((j-1)->getNum());
            j->setKey((j-1)->getKey());
        }
        j->setNum(num);
        j->setKey(key);
    }
}

void insort2(vector<numWrapper>& numVector)
{
    vector<numWrapper>::iterator i = numVector.begin() + 1;
    for (; i != numVector.end(); ++i) {
        vector<numWrapper>::iterator j = i;
        int num = j->getNum();
        int key = j->getKey();
        double count = j->getCount();
        for (; j != numVector.begin() && (key < (j-1)->getKey() ); --j){
            j->setNum((j-1)->getNum());
            j->setKey((j-1)->getKey());
            j->setCount((j-1)->getCount());
        }
        j->setNum(num);
        j->setKey(key);
        j->setCount(count);
    }
}

int main()
{
    int m, t;
    int i = 1;
    vector<numWrapper> myvector;
    cin >> m;
    while(m--){
        cin >> t;
        numWrapper tmp(t, i++);
        myvector.push_back(tmp);
    }

    vector<numWrapper>::iterator it;

    insort(myvector);

    for (it = myvector.begin(); it != myvector.end(); ++it){
        int test = it->getNum();
        double tmpCount = 1.0;

        if (it != myvector.begin()){
            tmpCount = (it-1)->getCount();
            for (int i = (it-1)->getNum() + 1; i <= test; ++i)
                tmpCount += log10(i);
        }else {
            for (int i = 1; i <= test; ++i)
                tmpCount += log10(i);
        }
       
        it->setCount(tmpCount);
    }

    insort2(myvector);

    for(it=myvector.begin(); it != myvector.end(); ++it){
        cout << (int)it->getCount() << endl; 
    }

    return 0;
}
