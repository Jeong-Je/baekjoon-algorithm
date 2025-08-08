#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> A;
vector<int> go_w;
vector<int> back_w;
vector<int> visited;

int N, M, X;

void dijkstra(int start, int destination);

int main(){
    cin >> N >> M >> X;
    
    A.resize(N+1);
    go_w.resize(N+1, 0);
    back_w.resize(N+1, 0);
    visited.resize(N+1, INT_MAX);
    
    for(int i=0;i<M;i++){
        int s, e, w;
        cin >> s >> e >> w;
        
        A[s].push_back({w, e});
    }
    
    
    for(int i=1;i<=N;i++){
       fill(visited.begin(), visited.end(), INT_MAX);
       dijkstra(i, X);
       
       fill(visited.begin(), visited.end(), INT_MAX);
       dijkstra(X, i);
    }
    
    int ans = -1;
    
    for(int i=1;i<=N;i++){
        int total_cost = go_w[i] + back_w[i];
        if(ans < total_cost) ans = total_cost;
    }
    
    cout << ans;
}


void dijkstra(int start, int destination) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    visited[start] = 0;
    
    while(!pq.empty()) {
        auto[weight, now] = pq.top();
        pq.pop();
        
        if(start != X && now == X) {
            go_w[start] = weight;
            return;
        }
        
        if(start == X && now == destination) {
            back_w[destination] = weight;
            return;
        }
        
        
        for(auto[next_weight, next] : A[now]) {
            if(visited[next] > visited[now] + next_weight) {
                visited[next] = visited[now] + next_weight;
                pq.push({visited[next], next});
            }
        }
        
    }
}