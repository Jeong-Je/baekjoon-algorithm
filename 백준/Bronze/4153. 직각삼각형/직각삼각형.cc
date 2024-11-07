/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2 ,n3;
    
    while(true) {
        cin >> n1 >> n2 >> n3;
        if(n1 == 0 && n2 == 0 && n3 == 0) break;
        if(pow(n1, 2) == pow(n2, 2) + pow(n3, 2)){
            cout << "right\n";
        }else if(pow(n2, 2) == pow(n1, 2) + pow(n3, 2)) {
            cout << "right\n";
        }else if(pow(n3, 2) == pow(n1, 2) + pow(n2 ,2)){
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }

    return 0;
}