#include <iostream> 
#include <string> 
#include <cmath>
#include <sstream>
#include <stdio.h>
using namespace std;

const double PRECISION = 1E-6; 
const int COUNT_OF_NUMBER  = 4; 
//const int NUMBER_TO_CAL = 24;
const int NUMBER_TO_CAL = 18;
//double number[COUNT_OF_NUMBER] = {5.0, 5.0, 5.0, 1.0};
double number[COUNT_OF_NUMBER] = {2.0, 3.0, 3.0, 4.0};
string expression[COUNT_OF_NUMBER];

string stringify(double x)
{
    ostringstream o;
    return o.str();
}

bool Search(int n) 
{ 
    if (n == 1) { 
        if ( fabs(number[0] - NUMBER_TO_CAL) < PRECISION ) { 
            cout << expression[0] << endl; 
            return true; 
        } else { 
            return false; 
        } 
    }
    for (int i = 0; i < n; i++) { 
        if (n == 4){
            cout << "==================" << i  << endl;
            for (int k = 0; k < n; k++){
            cout << k << ":" << number[k] << " ";
            }
            cout << endl;
        }
        for (int j = i + 1; j < n; j++) { 
            double a, b; 
            string expa, expb;
            a = number[i]; 
            b = number[j]; 
            string astr, bstr;
            astr = stringify(a);
            bstr = stringify(b);
            //char astr[4], bstr[4];
            //cout << "aaaaaaaaaaaaa" << endl;
            //sprintf(astr, "%.1f", a);
            //sprintf(bstr, "%.1f", b);
            number[j] = number[n - 1];
            expa = expression[i]; 
            expb = expression[j]; 
            expression[j] = expression[n - 1];
            expression[i] = '(' + expa + astr + '+' + bstr + expb + ')'; 
            number[i] = a + b; 
            cout << "try " << a << " + " << b << endl;
            if ( Search(n - 1) ) {
                cout << "++++" << endl;
                return true; 
            } else {
                cout << "XXXXXXXXXXXXX++++" << endl;
            }

            cout << "try " << a << " - " << b << endl;
            expression[i] = '(' + expa + astr + '-' + bstr + expb + ')'; 
            number[i] = a - b; 
            if ( Search(n - 1) ){
                cout << "----"<< endl;
                return true; 
            } else {
                cout << "XXXXXXXXXXXXX----" << endl;
            }

            cout << "try " << b << " - " << a << endl;
            expression[i] = '(' + expb + bstr + '-' + astr + expa + ')'; 
            number[i] = b - a; 
            if ( Search(n - 1) ) {
                cout << "------------" << endl;
                return true; 
            } else {
                cout << "XXXXXXXXXXXXX------------" << endl;
            }

            cout << "try " << a << " * " << b << endl;
            expression[i] = '(' + expa + astr + '*' + bstr + expb + ')'; 
            number[i] = a * b; 
            if ( Search(n - 1) ) {
                cout << "********"<< endl;
                return true;
            } else {
                cout << "XXXXXXXXXXXXX************" << endl;
            }
            if (b != 0) { 
            cout << "try " << a << " / " << b << endl;
                expression[i] = '(' + expa + astr + '/' + bstr + expb + ')'; 
                number[i] = a / b; 
                if ( Search(n - 1) ) {
                    cout << "////" << endl;
                    return true; 
                } else {
                    cout << "XXXXXXXXXXXXX////"<< endl;
                }
            } 
            if (a != 0) { 
                cout << "try " << b << " / " << a << endl;
                expression[i] = '(' + expb + bstr + '/' + astr + expa + ')'; 
                number[i] = b / a; 
                if ( Search(n - 1) ) {
                    cout << "////////////////"<< endl;
                    return true; 
                } else {
                    cout << "XXXXXXXXXXXXX////////////////"<< endl;
                }
            }
            number[i] = a; 
            number[j] = b; 
            expression[i] = expa; 
            expression[j] = expb; 
        } 
    } 
    return false; 
}

int main()
{
    bool found24 = Search(4);
    if (found24)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
