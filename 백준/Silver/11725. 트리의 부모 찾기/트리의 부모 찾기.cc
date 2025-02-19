#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static vector<int> answer;

void DFS(int node);

int main(){
    int N;
    cin >> N;
    
    tree.resize(N+1);
    visited.resize(N+1);
    answer.resize(N+1);
    
    for(int i=1;i<N;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1);
    
    for(int i=2;i<=N;i++)
        cout << answer[i] << "\n";
    
}

void DFS(int node){
    visited[node] = true;
    
    for(int i: tree[node]) {
        if(!visited[i]) {
            answer[i] = node;
            DFS(i);
        }
    }
}