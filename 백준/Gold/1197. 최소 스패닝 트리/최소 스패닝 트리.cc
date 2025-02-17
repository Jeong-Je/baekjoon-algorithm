#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

void munion(int a, int b);
int find(int a);
static vector<int> parent;

typedef tuple<int, int, int> Edge;

int main(){
    int N, M;
    cin >> N >> M;
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(N+1);
    
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<M;i++) {
        int s,e,v;
        cin >> s >> e >> v;
        pq.push({v, s, e});
    }
    
    int result = 0;
    int useEdge = 0;
    
    while(useEdge < N -1) {
        Edge now = pq.top();
        pq.pop();
        
        int now_v = get<0>(now);
        int now_s = get<1>(now);
        int now_e = get<2>(now);
        
        if(find(now_s) != find(now_e)) { // 연결해도 사이클이 형성 안된다면
            munion(now_s, now_e);
            result = result + now_v;
            useEdge++;
        }
    }
    
    cout << result;
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);
    if( a!=b ) {
        parent[b] = a;
    }
}

int find(int a) {
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}
