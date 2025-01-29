// BOJ 1707 (https://www.acmicpc.net/problem/1707)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, V, E;
static vector<vector<int>> vec;
static vector<int> visited;

#define RED 1
#define BLUE 2

void BFS(int node);
bool isBipartiteGraph();

int main()
{
    cin >> K;
    
    for(int i=0;i<K;i++){
        cin >> V >> E;
        vec.resize(V+1);
        visited = vector<int>(V+1, false);
        for(int j=0;j<E;j++){
            int s, e;
            cin >> s >> e;
            vec[s].push_back(e);
            vec[e].push_back(s);
        }
        for(int i=1;i<=V;i++){
            if(!visited[i]) BFS(i);
        }
        if(isBipartiteGraph()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
        for(int i=0;i<=V;i++){
            vec[i].clear();
        }
    }
    
    return 0;
}

void BFS(int node) {
    int color = RED;
    visited[node] = color;
    queue<int> que;
    que.push(node);
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        if(visited[now] == RED) {
            color = BLUE;
        } else {
            color = RED;
        }
        for(int i=0;i<vec[now].size();i++){
            int next = vec[now][i];
            if(!visited[next]){
                visited[next] = color;
                que.push(next);           
            }
        }
    }
}

bool isBipartiteGraph() {
    for(int i=1;i<=V;i++){
        for(int j=0;j<vec[i].size();j++){
            int next = vec[i][j];
            if(visited[i] == visited[next]) return false;
        }
    }
    
    return true;
}