#include <iostream>
#include <vector>

using namespace std;

static int durability[201];
static bool robot_exist[201];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    for(int i=1;i<=2*N;i++){
        cin >> durability[i];
    }
    
    int durability_zero_count = 0;
    int result = 0;
    while(durability_zero_count < K){
        result++;
        
        
        // 1.벨트 회전
        int tmp_d = durability[2*N];
        for (int i=2*N;i>=2;i--) {
            durability[i] = durability[i-1];
            robot_exist[i] = robot_exist[i-1];
        }
        durability[1] = tmp_d;
        robot_exist[1] = false;
        robot_exist[N] = false; // 내리는 칸에서 로봇 내리기
        
        
        // 2. 로봇 움직이기
        for(int i=N-1;i>=1;i--){
           if(robot_exist[i] && !robot_exist[i+1] && durability[i+1]) {
               robot_exist[i+1] = true;
               robot_exist[i] = false;
               durability[i+1]--;
               if(durability[i+1] == 0) durability_zero_count++;
           }
        }
        robot_exist[N] = false;
        
        // 3. 로봇 올리기 
        if(robot_exist[1] == false && durability[1] != 0) { 
            robot_exist[1] = true;
            durability[1]--; 
            if(durability[1] == 0) durability_zero_count++;
        } 
    }
    
    
    cout << result;
}