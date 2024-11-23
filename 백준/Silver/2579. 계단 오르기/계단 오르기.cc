/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> v(n+1);
    vector<int> D(n+1);
    
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    
    D[1] = v[1];
    D[2] = v[1] + v[2];
    D[3] = max(v[1], v[2]) + v[3];
    
    
    for(int i =4;i<=n;i++){
        D[i] = max(v[i] + D[i-2], v[i] + v[i-1] + D[i-3]);
    }
    
    cout << D[n];
    

    return 0;
}