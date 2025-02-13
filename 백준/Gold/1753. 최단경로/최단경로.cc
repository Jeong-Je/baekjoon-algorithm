#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int V, E, K;
    cin >> V >> E >> K;
    
    typedef pair<int, int> edge;
    
    priority_queue<edge, vector<edge>, greater<edge>> q;
    //queue<edge> q;
    
    vector<int> visited(V+1, false);
    vector<vector<edge>> mlist(V+1);
    vector<int> mdistance(V+1, INT_MAX);
    
    for(int i=0;i<E;i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        mlist[u].push_back({v, w});
    }
    
    mdistance[K] = 0;
    q.push({0, K});
    
    while(!q.empty()){
        edge now = q.top();
        q.pop();
        
        int now_v = now.second;
        
        if(visited[now_v]) continue;
        visited[now_v] = true;
        
        for(int i=0;i<mlist[now_v].size();i++){
            edge tmp = mlist[now_v][i];
            int next = tmp.first;
            int weight = tmp.second;
            
            if(mdistance[next] > mdistance[now_v] + weight) { // 최저 값으로 갱신
                mdistance[next] = mdistance[now_v] + weight;
                q.push({mdistance[next], next});
            }
        }
    }
    
    
    for(int i=1;i<=V;i++){
        if(visited[i]) {
            cout << mdistance[i] << endl;
        } else {
            cout << "INF\n";
        }
    }
}