// 2252 줄세우기 (https://www.acmicpc.net/problem/2252)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> V;
static vector<int> A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    V.resize(N+1);
    A.resize(N+1);
    
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        
        V[a].push_back(b);
        A[b]++;
    }
    
    queue<int> q;
    
    for(int i=1;i<=N;i++){
        if(A[i] == 0){
            q.push(i);
        }
    }
    
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        cout << now << " ";
        
        for(int next: V[now]) {
           A[next]--;
           if(A[next] == 0){
               q.push(next);
           }
        }
    }
    
}