#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char map[50][50];
bool pop[50][50];
bool visited[50][50];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int n, m;

bool bfs(int i, int j);

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            map[i][j] = storage[i][j];
        }
    }
    
    for(int r=0;r<requests.size();r++)
    {
        string req = requests[r];
        
        // 크레인을 쓰는 경우 
        if(req.size() == 2) 
        {
            char target = req[0];
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(map[i][j] == target)
                    {
                        pop[i][j] = true;
                    }
                }
            }
        }
        // 지게차를 쓰는 경우 
        else           
        {
            string target = req;
            vector<pair<int, int>> v;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(map[i][j] == target[0] && pop[i][j] == false)
                    {
                        memset(visited, false, sizeof(visited));
                        bool possible = bfs(i, j);
                        
                        if(possible)
                        {
                            v.push_back({i, j});
                        }
                    }
                }
            }
            
            for(int i=0;i<v.size();i++)
            {
                auto [r, c] = v[i];
                pop[r][c] = true;
            }
        }
    }
    
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(pop[i][j] == false) answer++;
        }
    }
    
    return answer;
}


bool bfs(int i, int j)
{
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    
    while(!q.empty())
    {
        auto [now_i, now_j] = q.front();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int next_i = now_i + di[i];
            int next_j = now_j + dj[i];
            
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) return true;
            
            if(visited[next_i][next_j] == true || pop[next_i][next_j] == false) continue;
            
            visited[next_i][next_j] = true;
            
            q.push({next_i, next_j});
           
        }
    }
    
    return false;
}