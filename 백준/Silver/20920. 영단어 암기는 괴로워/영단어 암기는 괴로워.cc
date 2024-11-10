/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> v;
map<string, int> mp;

bool compare(string a, string b) {
    if (a.size() == b.size() && mp[a] == mp[b]) {
        return a < b;
    }
    else if (mp[a] == mp[b]) {
        return a.size() > b.size();
    }
    return mp[a] > mp[b];
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str;
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> str;
        if(str.size() < m) continue;
        if(mp.find(str) == mp.end()){
            mp[str] = 1;
            v.push_back(str);
        } else {
            mp[str]++;
        }
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }

    return 0;
}