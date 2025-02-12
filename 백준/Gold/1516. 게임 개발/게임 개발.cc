// 1516 게임 개발 https://www.acmicpc.net/problem/1516
// 위상 정렬 문제
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> indegree(N+1);
    vector<vector<int>> A(N+1);
    vector<int> pre_time(N+1);
    vector<int> self_time(N+1);
    
    
    for(int i=1;i<=N;i++){
        cin >> self_time[i];
        
        int tmp;
        cin >> tmp;
        while(tmp!=-1){
            A[tmp].push_back(i);
            indegree[i]++;
            
            cin >> tmp;
        }
    }
    
    queue<int> q;
    
    for(int i=1;i<=N;i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int next: A[now]) {
            indegree[next]--;
            
            // 🌟  간선이 2개 이상 들어올 경우 더 긴 경우를 선택 🌟
            pre_time[next] = max(pre_time[next], pre_time[now] + self_time[now]);
            
            
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        cout << pre_time[i] + self_time[i] << "\n";
    }
}