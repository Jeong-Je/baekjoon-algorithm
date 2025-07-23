#include <iostream>
#include <vector>

using namespace std;

int arr[101];
bool visited[101];
vector<int> ans;

void dfs(int cur, int start);

int main() {
    int N;
    cin >> N;
    
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<=N;i++){
        fill(visited, visited+N+1, false);
        dfs(i, i);
    }
    
    
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << "\n";
    
}

void dfs(int cur, int start) {
    if(visited[cur]) {
        if(cur == start) {
            ans.push_back(cur);
        }
        return;
    }
    
    visited[cur] = true;
    dfs(arr[cur], start);
}