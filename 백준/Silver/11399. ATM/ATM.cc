/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> s(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    
    sort(a.begin()+1, a.end());
    
    s[1] = a[1];
    for(int i=2;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }
    
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum = sum + s[i];
    }
    
    cout << sum;

    return 0;
}