/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    
    cout << factorial(n) / (factorial(n-k) * factorial(k));
    
    return 0;
}

int factorial(int n) {
    int result=1;
    for(int i=1;i <=n;i++){
        result *= i;
    }
    return result;
}