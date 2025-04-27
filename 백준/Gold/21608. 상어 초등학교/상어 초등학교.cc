#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

static int map[21][21];
static int student_cnt;
static vector<vector<int>> v;
static int N;

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

void arrange(int num);


int main(){
    cin >> N;
    
    student_cnt = N*N;
    
    v.resize(student_cnt);
    
    for(int i=0;i<student_cnt;i++){
        int num;
        cin >> num;
        
        v[i].push_back(num);
        
        for(int j=0;j<4;j++){
            int like;
            cin >> like;
            
            v[i].push_back(like);
        }
    }
    
    
    for(int i=0;i<student_cnt;i++){
        arrange(v[i][0]);
    }
    
    int score = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int cnt = 0;
            
            for(int d =0; d<4;d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                
                if(ni < 1 || ni > N || nj < 1 || nj > N) continue;
                
                int now_student = map[i][j]; 
            
                int num_idx;
                for(int k=0;k<=student_cnt;k++){
                    if(v[k][0] == now_student) {
                        num_idx = k;
                        break;
                    }
                }
                
                for(int k=1;k<=4;k++){
                    if(v[num_idx][k] == map[ni][nj]) cnt++;
                }
                
            }
            
            switch(cnt){
                case 0: break;
                case 1: score += 1; break;
                case 2: score += 10; break;
                case 3: score += 100; break;
                case 4: score += 1000; break;
            }
        }
    }
    
    cout << score;
}


void arrange(int num){
    priority_queue<tuple<int, int, int, int>> pq; // 친구 수, 빈 자리, 행 번호, 열 번호 
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j] != 0) continue;
            
            int like = 0;
            int blank = 0;
            
            for(int d=0;d<4;d++){
                int next_i = i + dx[d];
                int next_j = j + dy[d];
                
                if(next_i < 1 || next_i > N || next_j < 1 || next_j > N) continue;
                
                if(map[next_i][next_j] == 0) blank++;
                else{
                    int num_idx;
                    for(int k=0;k<=student_cnt;k++){
                        if(v[k][0] == num) {
                            num_idx = k;
                            break;
                        }
                    }
                    
                    for(int k=1;k<=4;k++){
                        if(v[num_idx][k] == map[next_i][next_j]) like++;
                    }
                }
            }
            pq.push({like, blank, i, j});
        }
    }
    
    auto [like, blank, i, j] = pq.top();
    map[i][j] = num;
}