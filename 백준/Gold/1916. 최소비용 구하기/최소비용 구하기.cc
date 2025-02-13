// 1916 최소비용 구하기 (https://www.acmicpc.net/problem/1916)
// 다익스트라 문제
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    typedef pair<int, int> edge;
    
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    
    vector<vector<edge>> mlist(N+1);
    vector<int> mdistance(N+1, INT_MAX);
    vector<bool> visited(N+1, false);
    
    for(int i=0;i<M;i++){
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back({v, w});
    }
    
    int S, E;
    cin >> S >> E;
    
    mdistance[S] = 0;
    
    pq.push({0, S});
    
    while(!pq.empty()){
        edge now = pq.top();
        pq.pop();
        
        int now_v = now.second;
        
        if(visited[now_v]) continue;
        visited[now_v] = true;
            
        for(int i=0;i<mlist[now_v].size();i++){
            int next_v = mlist[now_v][i].first;
            int next_w = mlist[now_v][i].second;
    
            if(mdistance[next_v] > mdistance[now_v] + next_w) {
                mdistance[next_v] = mdistance[now_v] + next_w;
                pq.push({mdistance[next_v], next_v});
            }
        }
    }
    
    cout << mdistance[E];
}