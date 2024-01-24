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
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        int n,m;
        cin >> n >> m;
        long long result = 1;
        
        int r = 1;
        for(int j=m;j>m-n;j--){
            result *= j;
            result /= r;
            r++;
        }
        
        cout<<result<<"\n";
    }
    
    return 0;
}
