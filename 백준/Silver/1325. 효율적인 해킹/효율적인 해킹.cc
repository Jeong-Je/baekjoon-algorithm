// 1325 효율적인 해킹 (https://www.acmicpc.net/problem/1325)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> v;
static vector<int> visited;
static vector<int> answer;

void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    v = vector<vector<int>>(N+1);
    visited.resize(N+1);
    answer.resize(N+1);
    
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    for(int i=1;i<=N;i++){
        fill(visited.begin(), visited.end(), 0);
        BFS(i);
    }

    int max = *max_element(answer.begin(), answer.end());
    
    for(int i=1;i<=N;i++){
        if(answer[i] == max) {
            cout << i << " ";
        }
    }
}

void BFS(int node){
    visited[node] = 1;
    
    queue<int> que;
    que.push(node);
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        for(int i: v[now]) {
            if(!visited[i]) {
                visited[i] = true;
                answer[i]++;
                que.push(i);
            }
        }
    }
}