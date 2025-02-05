// 18352 특정 거리의 도시 찾기 (https://www.acmicpc.net/problem/18352)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M, K, X;
static vector<vector<int>> v;
static vector<int> visited;

void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K >> X;
    
    v = vector<vector<int>>(N+1);
    visited.resize(N+1);
    
    for(int i=0;i<M;i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }
    
    BFS(X);
    
    bool check = false;
    
    for(int i=1;i<=N;i++){
        if(visited[i] -1 == K){
            cout << i << "\n";
            check = true;
        }
    }
    
    if(!check){
        cout << "-1\n";
    }
    
    
}

void BFS(int node) {
    visited[node] = true;
    queue<int> que;
    
    que.push(node);
    
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        
        for(int i: v[now]){
            if(!visited[i]){
                que.push(i);
                visited[i] = visited[now] + 1;
            }
        }
    }
}