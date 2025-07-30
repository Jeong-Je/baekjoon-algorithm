#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int A[50][50];
static bool check[50][50];

int di[4] = {-1 ,1 ,0, 0};
int dj[4] = {0, 0, -1, 1};

bool found =  false;

void BFS(int row, int column);

int N,L,R, ans = 0;

int main(){
    cin >> N >> L >> R;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    
    do {
        found = false;
        
        fill(check[0], check[50], false);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) {
                if(check[i][j] == false) BFS(i, j);
            }
        }
        
        if(found) ans++;
    } while(found);
      
    
    cout << ans;
}


void BFS(int row, int column) {
    queue<pair<int, int>> q;
    q.push({row, column});
    
    check[row][column] = true;
    
    int sum = A[row][column];
    int count = 1;
    
    vector<pair<int, int>> v;
    v.push_back({row, column});
    
    while(!q.empty()) {
        auto [now_r, now_c] = q.front();
        q.pop();
        
        for(int d=0;d<4;d++){
            int next_r = now_r + di[d];
            int next_c = now_c + dj[d];
            
            if(check[next_r][next_c]) continue;
            if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
            
            int diff = abs(A[next_r][next_c] - A[now_r][now_c]);
            if(L <= diff && diff <= R) {
                q.push({next_r, next_c});
                check[next_r][next_c] = true;
                
                found = true;
                
                sum += A[next_r][next_c];
                count ++;
                
                v.push_back({next_r, next_c});
            }
        }
    }
    
    int change_value = sum / count;
    for(int i=0;i<v.size();i++){
        auto[r, c] = v[i];
        A[r][c] = change_value;
    }
    
}