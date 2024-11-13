/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;




int fa(int n){
    if(n<=1) return n;
    return fa(n-1) + fa(n-2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n==0){
        cout << "0";
    }else if (n==1) {
        cout << "1";
    } else {
        cout << fa(n);
    }

    return 0;
}