#include <iostream>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int N, M, D;

static int map[16][16];
static int map_copy[16][16];
static bool visited[16][16];
static int answer;
static bool enemyExist, removeEnemyFound;

void BFS(int row, int column);
void backTracking(int start, int count);
int max(int a, int b);


vector<int> archerColumns;
set<pair<int, int>> removeEnemy;

int enemyRow, enemyColumn, castle_row;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main(){
    cin >> N >> M >> D;
   
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
   
   
    // M개의 열에서 궁수 3명의 위치를 백트래킹으로 선정함
    backTracking(0, 0);
    
    
    cout << answer;
}  

void BFS(int row, int column) {
    queue<tuple<int, int, int>> q;
    q.push({row, column, 0});
   
    int minDistance;
    while(!q.empty()) {
        auto [now_row, now_column, dis] = q.front();
        q.pop();
        
        if(map_copy[now_row][now_column] && dis == minDistance) {
            if(now_column < enemyColumn) {
                enemyRow = now_row;
                enemyColumn = now_column;
            }
        }
        
    
        for(int d=0;d<4;d++){
            int next_row = now_row + dr[d];
            int next_column = now_column + dc[d];
           
            if(next_row < castle_row && next_row > -1 && next_column < M && next_column > -1 && !visited[next_row][next_column]) {
                
               if(map_copy[next_row][next_column] && !removeEnemyFound) {  // 적이 있음
                   if(dis + 1 <= D) {
                       enemyRow = next_row;
                       enemyColumn = next_column;
                       minDistance = dis + 1;
                       
                       removeEnemyFound = true;
                   }
                   
                   enemyExist = true;
                   
               } else { // 적이 없는 곳 
                   visited[next_row][next_column] = true;
                   
                   q.push({next_row, next_column, dis + 1});
               }
            }
        }
    }
}


void backTracking(int start, int count) {
    if(count == 3) { // 궁수 3명 배치 완료
    
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                map_copy[i][j] = map[i][j];
            }
        }
        
        int i = 0;
        int temp = 0;
        castle_row = N;
        do {
            enemyExist = false;
            removeEnemyFound = false;
            
            fill(visited[0], visited[N], 0);
            
            BFS(castle_row, archerColumns[i]);
            
            if(!enemyExist) break;
            
            if(removeEnemyFound) {
                removeEnemy.insert({enemyRow, enemyColumn});
            }
            
            i++;
            
            
            if(i == 3)  {
                // 적 제거는 세 명의 궁수가 모두 활을 쏜 다음에 진행한다. 
                for (const auto& p : removeEnemy) {
                    map_copy[p.first][p.second] = 0;
                    temp++;
                }
                
                i = 0;
                castle_row--; // 성을 한 칸 앞으로 당겨서 적이 다가 오는것과 같은 효과를 줌 
                removeEnemy.clear();
            }
            
        } while(enemyExist);
        
        answer = max(answer, temp);
    }
   
    for(int i = start; i < M; i++) {
        archerColumns.push_back(i);
        backTracking(i + 1, count + 1);
        archerColumns.pop_back();
    }
}


int max(int a, int b) {
    if(a < b) return b;
    else return a;
}