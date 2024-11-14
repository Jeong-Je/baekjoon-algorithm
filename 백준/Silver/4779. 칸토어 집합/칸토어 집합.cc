/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

void cantor(int n){
    int size = pow(3,n-1);
    
    if(n==0){
        cout<<"-";
        return;
    }
    
    cantor(n-1);
    
    for(int i=0;i<size;i++){
        cout << " ";
    }
    cantor(n-1);
    
    
    
    
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    
    while(cin >> n){
        //cin >> n;
        cantor(n);
        cout << "\n";
    }
    
    return 0;
}