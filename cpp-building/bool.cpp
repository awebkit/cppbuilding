/*
 * 算法描述：
 *   f(a, n)表示计算数组a，项数为n的布尔表达式的值
 *   f的算法为最后一个孩子（可能为单独的项，或者两项（对应!的情况），或者很多项（对应括号的情况））
 *   和最后一个孩子的前一位作为运算符
 *   与运算符前的a,n-x项做运算
 * 
 * 最后一个孩子的函数为lastChild(a, n),返回值为最后一个孩子的首位置
 * 
 * 不考虑!!情况
 */
#include <iostream>

using namespace std;

int lastChild(char a[], int n) {
    //a[n-1] 一定是F/V/)
    if (a[n - 1] != ')'){
        if (a[n - 2] == '!'){
            return n - 2;
        } else
            return n - 1;
    } else{
        int i = n - 2;
        int value = 0;
        for (; i > 0; --i){
            if (a[i] == ')')
                value++;
            if (a[i] == '('){
                value--;
                if (value == 0){
                    //Got it. However, we should judge '!'
                    if ( i > 0 && a[i - 1] == '!')
                        return i - 1;
                    else
                        return i;
                }
            }
        }
        cout << "Error, can not match ), please reinput" << endl;
    }
}

bool judgeBool(char a[], int n){

    //递归结束条件
    if ( n == 1){
        if (a[0] == 'F')
            return false;
        else if (a[0] == 'V')
            return true;
        else
            cout << "Error, please reinput" << endl;
    }

    if ( n == 2) {

        if ( a[0]!= '!' || a[1] != 'F' && a[1] != 'V')
            cout << "Error, please check input" << endl;

        //Because a[0] == '!'
        if (a[1] == 'F')
            return true;
        else
            return false;
    }

    int m = lastChild(a, n);
    
    cout << "Last child position " << m << endl;

    //计算最后一个孩子的值
    bool result;
    if (a[m] == '(')
        result = judgeBool(&a[m], n - m - 1); //不再考虑左右括号
    else if (a[m] == '!' && a[m + 1] == '(')
        result = judgeBool(&a[m + 2], n - m - 2);
    else
        result = judgeBool(&a[m], n - m);

    /*
    // a[m + 1]一定是符号运算符，否则输入有误
    if (a[m + 1] != '|' && a[m + 1] != '&')
        cout << "Erro input after first child " << endl;
    */

    //从前往后是不能利用短路性的，所以我们从后往前
    //考虑 F & V | V -> V
    //短路性，为了效率
    if ((result == true) && (a[m - 1] == '|'))
        return true;
    if ((result == false) && (a[m - 1] == '&'))
        return false;

    return judgeBool(a, n - m - 1);
}

int main(){

    //test
    char a[5] ={'!', 'V', '|', '!', 'V'};
    bool ret = judgeBool(a, 5);

    cout << "Return is ";

    if (ret == true)
        cout << "V";
    else
        cout << "F";
    cout <<endl;
}
