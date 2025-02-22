#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static int deleteNode;
static int answer = 0;

void DFS(int node);

int main(){
    int N;
    cin >> N;
    
    visited.resize(N);
    tree.resize(N);
    
    int root = 0;
    
    for(int i=0;i<N;i++){
        int p;
        cin >> p;
        
        if(p!=-1){
            tree[i].push_back(p);
            tree[p].push_back(i);
        } else {
            root = i;
        }
    }
    
    cin >> deleteNode;
    
    if(deleteNode == root) {
        cout << 0;
    } else {
        DFS(root);
        cout << answer;
    }
}

void DFS(int node){
    visited[node] = true;
    int cNode = 0;
    
    for(int i:tree[node]) {
        if(!visited[i] && i != deleteNode) {
            cNode++;
            DFS(i);
        }
    }
    
    if(cNode == 0) answer++;
}