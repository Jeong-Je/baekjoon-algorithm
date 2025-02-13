#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    typedef tuple<int,int,int> edge;
    
    vector<long> mdistance(N+1, LONG_MAX);
    vector<edge> edges;
    
    for(int i=0;i<M;i++){
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }
    
    mdistance[1] = 0;
    
    for(int i=1;i<N;i++){
       for(int j=0;j<M;j++){
           edge now = edges[j];
           int s = get<0>(now);
           int e = get<1>(now);
           int w = get<2>(now);
           
           if(mdistance[s] != LONG_MAX && mdistance[e] > mdistance[s] + w) {
               mdistance[e] = mdistance[s] + w;
           }
       } 
    }
    
    
    bool cycle = false;
    
   for(int j=0;j<M;j++){
       edge now = edges[j];
       int s = get<0>(now);
       int e = get<1>(now);
       int w = get<2>(now);
       
       if(mdistance[s] != LONG_MAX && mdistance[e] > mdistance[s] + w) {
           cycle = true;
       }
    } 
    
    if(cycle) {
        cout << -1;
    } else {
        for(int i=2;i<=N;i++){
            if(mdistance[i] == LONG_MAX) {
                cout << "-1\n";
            } else {
                cout << mdistance[i] << "\n";
            }
        }
    }
}