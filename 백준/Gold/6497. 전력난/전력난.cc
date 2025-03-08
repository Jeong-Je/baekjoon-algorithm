#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

static int parent[200000];

void munion(int a, int b);
int find(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    
    typedef tuple<int, int, int> route;
    priority_queue<route, vector<route>, greater<route>> pq;
    
    while(true){
        cin >> m >> n;
        if(m==0 && n ==0) break;
        
        for(int i=0;i<m;i++){
            parent[i] = i;
        }
        
        int max_w = 0;
        for(int i=0;i<n;i++){
            int x, y, z;
            cin >> x >> y >> z;
            max_w += z;
            pq.push({z, x, y});
        }
        
        int min_w = 0;
        while(!pq.empty()){
            route now = pq.top();
            pq.pop();
            
            int weight = get<0>(now);
            int x = get<1>(now);
            int y = get<2>(now);
            
            if(find(x) != find(y)) {
                munion(x, y);
                min_w += weight;
            }
        }
        cout << max_w - min_w << "\n";
    }
    
    return 0;
}


void munion(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a!=b){
        parent[b] =a;
    }
}
int find(int a) {
    if(a==parent[a]) return a;
    else return a = find(parent[a]);
}