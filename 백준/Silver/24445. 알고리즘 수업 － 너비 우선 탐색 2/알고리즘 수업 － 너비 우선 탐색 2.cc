/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static vector<int> order;

void BFS(int R);

bool compare(int a, int b){
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, R;
    cin >> N >> M >> R;
    
    A.resize(N+1);
    order.resize(N+1, 0);
    visited = vector<bool>(N+1, false);
    
    for(int i=0;i<M;i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    for(int i=1;i<=N;i++){
        sort(A[i].begin(), A[i].end(), compare);
    }
    
    BFS(R);
    
    for(int i=1;i<=N;i++){
        cout<<order[i]<<"\n";
    }

    return 0;
}

void BFS(int R){
    visited[R] = true;
    
    queue<int> q;
    q.push(R);
    
    int index = 1;
    
    while(!q.empty()){
        int now_node = q.front();
        q.pop();
        order[now_node] = index++;
        for(int i: A[now_node]) {
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}