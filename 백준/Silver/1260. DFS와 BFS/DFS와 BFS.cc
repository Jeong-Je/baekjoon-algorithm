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

vector<vector<int>> A;
vector<bool> visited;
bool arrive;

void DFS(int node);
void BFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	arrive = false;
	A.resize(N+1);
	visited = vector<bool>(N+1, false);

	for(int i=0; i<M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for(int i=1; i<=N; i++) {
		sort(A[i].begin(), A[i].end());
	}

	DFS(V);
	cout << "\n";

	visited = vector<bool>(N+1, false);

    BFS(V);
    
	return 0;
}


void DFS(int node) {
	cout << node << " ";
	visited[node] = true;

	for(int i : A[node]) {
		if(!visited[i]) {
			DFS(i);
		}
	}
}


void BFS(int node) {
    queue<int> q;
    visited[node] = true;
    
    q.push(node);
    
    while(!q.empty()){
        int now_node = q.front();
        q.pop();
        
        cout << now_node << " ";
        
        for(int i: A[now_node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
