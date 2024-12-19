/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int arr[40];
    arr[0] = 1, arr[1] = 1;
    
    for(int i=2;i<=40;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    int t, n;
    cin >> t;
    
    for(int i=0;i<t;i++){
        cin >> n;
        if(n==0){
            cout << "1 0\n";
        } else if(n==1){
            cout << "0 1\n";
        } else {
            cout << arr[n-2] << " " << arr[n-1] << "\n";
        }
    }
    
    
    return 0;
}