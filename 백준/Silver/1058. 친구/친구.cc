#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, ans;

vector<vector<int>> A;
vector<bool> visited;

void BFS(int start);

int max(int a, int b)
{
    if(a < b) return b;
    else return a;
}

int main()
{
    cin >> N;
    
    A.resize(N+1);
    visited.resize(N+1);
    
    // 친구 관계 형성하기 
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            char c;
            cin >> c;
            
            if(c == 'Y')
            {
                A[i].push_back(j);
            }
        }
    }
    
    // 최대 2-친구의 수 구하기 
    for(int i=1;i<=N;i++)
    {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }
    
    
    // 정답 출력
    cout << ans;
}

void BFS(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    visited[start] = true;
    
    int friends = 0;
    while(!q.empty())
    {
        int now = q.front().first;
        int depth = q.front().second;
        
        q.pop();
        
        if(depth == 2) continue;
        
        for(int next: A[now])
        {
            if(visited[next] == false)
            {
                visited[next] = true;
                friends++;
                q.push({next, depth + 1});
            }
        }
    }
    
    ans = max(ans, friends);
}