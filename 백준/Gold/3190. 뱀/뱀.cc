#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K, L;
static int map[101][101];
vector<pair<int, char>> direction_info;

void DFS(int r, int c, int d, int times);

int dx[5] = {0, 0, -1, 0, 1};
int dy[5] = {0, 1, 0 ,-1 ,0};

deque<pair<int, int>> snake;

int main(){
    cin >> N >> K;
    
    for(int i=0;i<K;i++){
        int row, column;
        cin >> row >> column;
        
        // 1이면 사과가 있는 곳
        map[row][column] = 1;
    }
    
    cin >> L;
    
    for(int i=0;i<L;i++){
        int t;
        char d;
        cin >> t >> d;
        
        direction_info.push_back({t, d});
    }
    
    // 2이면 뱀의 신체 일부가 있는 곳 
    map[1][1] = 2;
    
    snake.push_back({1, 1});
    
    // 방향
    // 오른쪽 = 1 , 위 = 2 , 왼 = 3, 아래 = 4
    DFS(1, 1, 1, 0);
}

void DFS(int r, int c, int d, int times){
    
    for(int i=0;i<L;i++){
        if(times == direction_info[i].first) {
            if(direction_info[i].second == 'L') { // 왼쪽으로 90도 
                d++;
            } else { // 오른쪽으로 90도 
                d--;
            }
            
            if(d == 0) d = 4;
            if(d == 5) d = 1;
            
            break;
        }
    }
    
    int next_r = r + dx[d];
    int next_c = c + dy[d];

    if(next_r == 0 || next_r == N+1 || next_c == 0 || next_c == N+1 || map[next_r][next_c] == 2) {
        cout << times + 1;
        exit(0);
    }
    
    
    
    if(map[next_r][next_c] == 0) { // 사과가 없음 
        map[next_r][next_c] = 2;
        
        auto [tail_r, tail_c ] = snake.back();
        snake.pop_back();
        
        map[tail_r][tail_c] = 0;
        
    } else { // 사과 있음 
        map[next_r][next_c] = 2;
    }
    
    snake.push_front({next_r, next_c});
    DFS(next_r, next_c, d, times + 1);
}