// 1219 오민식의 고민 (https://www.acmicpc.net/problem/1219)
// 벨만 포드 문제
#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, S, E, M;
    cin >> N >> S >> E >> M;
    
    typedef tuple<int, int, int> edge;
    vector<edge> edges;
    vector<long> mdistance(N, LONG_MIN);
    vector<int> money(N);
    
    for(int i=0;i<M;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    for(int i=0; i<N;i++){
        cin >> money[i];
    }
    
    mdistance[S] = money[S];
    
    for(int i=0;i<=N+50;i++){
        for(int j=0;j<M;j++){
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int price = get<2>(medge);
            
            if(mdistance[start] == LONG_MIN) continue;
            
            if(mdistance[start] == LONG_MAX) mdistance[end] = LONG_MAX;
            
            if(mdistance[end] < mdistance[start] + money[end] - price) {
                if(i >= N-1) {
                    mdistance[end] = LONG_MAX;
                } else {
                    mdistance[end] = mdistance[start] + money[end] - price;
                }
            }
            
            
        }
    }
    
    if(mdistance[E] == LONG_MIN) {
        cout << "gg";
    } else if(mdistance[E] == LONG_MAX) {
        cout << "Gee";
    } else {
        cout << mdistance[E];
    }
    
}