/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

int count = 0;

void DFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    A.resize(N+1);
    visited = vector<bool>(N+1, false);
    
    for(int i=0;i<M;i++){
        int s, e;
        cin >> s >> e;
        
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    DFS(1);
    
    cout << count;
}

void DFS(int node){
    visited[node] = true;
    
    for(int i: A[node]) {
        if(!visited[i]){
            visited[i] = true;
            count ++;
            DFS(i);
        }
    }
}