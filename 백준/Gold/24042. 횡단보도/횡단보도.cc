#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;

int N, M;
    
static ll dis[100001];
static vector<vector<pair<int, int>>> v;

ll dijkstra(int position, int cost);

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    fill(dis, dis+100001, LONG_MAX);
    v.resize(N+1);
    
    for(int i=1;i<=M;i++){
        int a, b;
        cin >> a >> b;
        
        // 양방향 그래프 
        v[a].push_back({i, b});
        v[b].push_back({i, a});
    }
    
    ll ans = dijkstra(1, 0);
    cout << ans;
}

ll dijkstra(int position, int cost) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({cost, position});
    
    while(!pq.empty()) {
        auto[now_cost, now_p] = pq.top();
        pq.pop();
        
        ll now_cycle_cnt = now_cost / M; // 현재 몇 바퀴 돌았는지 
        ll now_cycle = now_cost % M; // 현재 위치의 한 주기에서 순서 
        
        if(now_p == N) return now_cost; // 목적지 달성 
        
        for(auto[next_cost, next_p] : v[now_p]) {
            ll next_cycle = next_cost % M;
            
            if(next_cycle < now_cycle + 1) { // 현재 사이클에 못 건너는 경우 
                ll next_cost = (now_cycle_cnt+1) * M + next_cycle;
                if(dis[next_p] <= next_cost) continue;
                dis[next_p] = next_cost;
                pq.push({next_cost, next_p});
            } else { // 현재 사이클에 건널 수 있는 경우 
                ll next_cost = now_cycle_cnt * M + next_cycle;
                if(dis[next_p] <= next_cost) continue;
                dis[next_p] = next_cost;
                pq.push({next_cost, next_p});
            }
        }
    }
    return -1;
}