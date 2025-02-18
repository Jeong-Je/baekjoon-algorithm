#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

vector<int> parent;

void munion(int a,int b);
int find(int a);

int main(){
    int N;
    cin >> N;
    
    typedef tuple<int, int, int> Edge;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    

    
    int sum = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char w = cin.get();
            
            if(w == '\n'){
                w = cin.get();
            }
            
            
            int weight = 0; 
            if(w >= 'a' && w <= 'z') {
                weight = w - 'a' + 1;
            } else if(w >= 'A' && w <= 'Z') {
                weight = w - 'A' + 27;
            }
            
            sum += weight;
            
            if(i!=j && weight != 0) {
                pq.push({weight, i, j});
            }
        }
    }
    
    
    parent.resize(N+1);
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
    
    
    int useEdge = 0;
    int result = 0;
    while(!pq.empty()) {
        tuple<int, int, int> now = pq.top();
        pq.pop();
        
        int w = get<0>(now);
        int s = get<1>(now);
        int e = get<2>(now);
        
        if(find(s) != find(e)) {
            munion(s, e);
            result += w;
            useEdge++;
        }
        
    }
    
    
    if(useEdge == N-1) {
        cout << sum - result;
    } else {
        cout << -1;
    }
}


void munion(int a,int b){
    a = find(a);
    b = find(b);
    
    if(a!=b){
        parent[b] = a;
    }
}
int find(int a)
{
    if(a==parent[a]) return a;
    else return parent[a] = find(parent[a]);
}