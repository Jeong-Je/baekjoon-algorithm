/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>

using namespace std;

int count_fib = 0;
int count_fibonacci = 0;
int arr[41] = {0};

int fib(int n) {
    if(n==1 || n ==2) {
        count_fib++;
        return 1; // 코드1
    }
    else return (fib(n-1) + fib(n-2));
}

int fibonacci(int n){
    arr[1] = arr[2] = 1;
    for(int i = 3; i <= n; i++) {
        count_fibonacci++;
        arr[i] = arr[i-1] + arr[i-2]; // 코드 2
    }
    
    return arr[n];
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    fib(n);
    fibonacci(n);
    
    cout<<count_fib<<" "<<count_fibonacci<<"\n";

    return 0;
}