#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string S, T;

void dfs(string t);

int main() {
    cin >> S >> T;
    
    dfs(T);
    
    cout << 0;
}


void dfs(string t) {
    if(t.length() == S.length()) {
        if(t == S) {
            cout << 1;
            exit(0);
        }
        
        return;
    }
    
    if(t.back() == 'A') {
        string next = t;
        next.pop_back();
        dfs(next);
    }
    if(t.front() == 'B') {
        string next = t;
        reverse(next.begin(), next.end());
        next.pop_back();
        dfs(next);
    }
}