#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    
    for(int i=0;i<T;i++){
        int N, K;
        cin >> N >> K;
        
        vector<int> D(N+1, 0);  // 진입 차수
        vector<int> times(N+1, 0);  // 건물 건설 시간
        vector<int> build_time(N+1, 0);  // 누적 건설 시간
        vector<vector<int>> A(N+1);  // 그래프 인접 리스트
        
        for(int j=1;j<=N;j++){
            cin >> times[j];
        }
        
        for(int j=0;j<K;j++){
            int a, b;
            cin >> a >> b;
            D[b]++;
            A[a].push_back(b);
        }
        
        int target;
        cin >> target;
        
        queue<int> q;
        
        
        for(int i=1;i<=N;i++){
            if(D[i] == 0) {
                q.push(i);
                build_time[i] = times[i];
            }
        }
    
        while(!q.empty()){
            int now = q.front();
            q.pop();
            
            for(int next: A[now]) {
                D[next]--;
                if(build_time[next] < build_time[now] + times[next] ) {
                    build_time[next] = build_time[now] + times[next];            
                }    
                if(D[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        cout << build_time[target] << "\n";
    }


    
}