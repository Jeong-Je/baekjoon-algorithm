/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

long long factorial(int n){
    if(n==1) return 1;
    return factorial(n-1)*n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n==0){
        cout << "1";
    }else {
        cout << factorial(n);

    }

    return 0;
}