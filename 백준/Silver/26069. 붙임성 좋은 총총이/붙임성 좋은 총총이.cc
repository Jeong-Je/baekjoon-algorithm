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
    s.insert("ChongChong");
    
    string str1, str2;
    
    for(int i=0;i<n;i++){
        cin >> str1 >> str2;
        if(s.find(str1) != s.end() || s.find(str2) != s.end()) {
            s.insert(str1); s.insert(str2);
        }
    }
    
    cout << s.size();

    return 0;
}