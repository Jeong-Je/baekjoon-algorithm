#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

vector<vector<pair<int, int>>> A;
vector<bool> visited;
vector<int> mdistance;

void BFS(int start);

int main(){
    int N, M;
    cin >> N >> M;
    
    A.resize(N+1);
    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    
    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        A[a].push_back({b, c});
        A[b].push_back({a, c});
    }
    
    BFS(1);
    
    cout << mdistance[N];
}

void BFS(int start) {
    mdistance[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    
    pq.push({0, start});
    
    while(!pq.empty()) {
        auto [mdis, now] = pq.top();
        pq.pop();
        
        if(visited[now]) continue;
        visited[now] = true;
        
        for(auto [next, weight] : A[now]) {
            if(mdistance[next] > mdistance[now] + weight) {
                mdistance[next] = mdistance[now] + weight;
                pq.push({mdistance[next], next});
            }
        }
    }
}