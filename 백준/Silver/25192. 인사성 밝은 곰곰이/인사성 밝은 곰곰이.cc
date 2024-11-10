/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    set<string> s;
    
    string str;
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> str;
        if(str == "ENTER") {
            cnt += s.size();
            s.clear();
            continue;
        }
        s.insert(str);
    }
    
    cnt += s.size();
    
    cout << cnt;

    return 0;
}