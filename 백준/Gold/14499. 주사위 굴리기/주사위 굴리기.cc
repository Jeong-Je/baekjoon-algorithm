#include <iostream>

using namespace std;

int map[20][20];
int dice[7] = {0, 0, 0, 0, 0, 0, 0};


int main(){
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    
    int up = 1, down = 6, right = 3, left = 4, front = 2, back = 5;
    for(int i=0;i<K;i++){
        int d;
        cin >> d;
        
        int next_x, next_y;
        int tmp_up = up, tmp_down = down, tmp_right = right, tmp_left = left, tmp_front = front, tmp_back = back;
        if(d==1) { // 동
            // 주사위 위치 이동 
            next_x = x;
            next_y = y+1;
            
            // 주사위 굴리기 (front, back 변화 x)
            tmp_down = tmp_right;
            tmp_left = down;
            tmp_right = up;
            tmp_up = left;
            
        } else if(d==2) { // 서 
            // 주사위 위치 이동 
            next_x = x;
            next_y = y - 1;
            
            // 주사위 굴리기 (front, back 변화 x)
            tmp_down = tmp_left;
            tmp_left = up;
            tmp_right = down;
            tmp_up = right;
            
        } else if(d==3) { // 북 
            // 주사위 위치 이동 
            next_x = x - 1;
            next_y = y;
            
            // 주사위 굴리기 (left, right 변화 x)
            tmp_down = back;
            tmp_up = front;
            tmp_front = down;
            tmp_back = up;
            
        } else if(d==4) { // 남
            // 주사위 위치 이동 
            next_x = x + 1;
            next_y = y;
            
            // 주사위 굴리기 (left, right 변화 x)
            tmp_down = front;
            tmp_up = back;
            tmp_front = up;
            tmp_back = down;
            
        }
        
        // 주사위가 지도 밖으로 굴러간 경우 아무것도 처리하지 않음 
        if(next_x >= N || next_x < 0 || next_y >= M || next_y < 0) continue;
        
        // 주사위 정보 업데이트 
        x = next_x;
        y = next_y;
        up = tmp_up; down = tmp_down;
        left = tmp_left; right = tmp_right;
        front = tmp_front; back = tmp_back;
        
        
        if(map[x][y] == 0) { // 지도에 아무것도 쓰여있지 않은 경우 
            // 주사위의 바닥면에 쓰여 있는 수가 지도에 복사 된다.
            map[x][y] = dice[down];
            
        } else { // 지도에 자연수가 쓰여 있는 경우 
            // 바닥면에 쓰여 있는 수가 주사위 바닥면에 복사되고 바닥면의 수는 0이 된다. 
            dice[down] = map[x][y];
            map[x][y] = 0;
        }
        
        // 매 반복마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 
        cout << dice[up] << "\n";
    }
}