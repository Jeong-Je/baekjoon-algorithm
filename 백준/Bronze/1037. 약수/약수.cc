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
    cin.tie(NULL);
    
    int count;
    cin >> count;
    
    vector<int> v(count);
    
    for(int i=0;i<count;i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    cout<< v[0] * v[count -1];
    
    return 0;
}
