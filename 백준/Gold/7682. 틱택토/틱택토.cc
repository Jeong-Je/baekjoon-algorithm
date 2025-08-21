#include <iostream>
#include <string>

using namespace std;

static char map[3][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    
    while(true)
    {
        cin >> input;
        if(input == "end") break;
        
        int x_cnt = 0, o_cnt = 0, dot_cnt = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                map[i][j] = input[3*i + j];
                if(input[3*i+j] == 'O') o_cnt++;
                else if(input[3*i+j] == 'X') x_cnt++;
                else dot_cnt++;
            }
        }
        
        if(dot_cnt == 0) // 격자판이 모두 찬 상황에서 
        {
            // x가 5개, o가 4개가 아니면 invalid 상황 
            if(x_cnt != 5 || o_cnt != 4) {cout << "invalid\n"; continue;}
        } 
        // O는 X보다 많을 수 없음. 
        if(o_cnt > x_cnt)
        {
            cout << "invalid\n";
            continue;
        }
        
        // X는 O랑 같은 개수이거나 1개 더 많아야 됨 
        if(x_cnt - o_cnt > 1)
        {
            cout << "invalid\n";
            continue;
        }
        
        int game_over = 0;
        char game_over_c = 'f';
        bool double_win = false;
        // 가로 연속 체크
        for(int i=0;i<3;i++)
        {
            if(map[i][0] != '.' && map[i][0] == map[i][1] && map[i][1] == map[i][2]) {
                game_over++;  
                if(game_over_c != 'f')
                {
                    if(game_over_c != map[i][0]) double_win = true;
                }
                game_over_c = map[i][0];
            }
        }
        
        // 세로 연속 체크
        for(int i=0;i<3;i++)
        {
            if(map[0][i] != '.' && map[0][i] == map[1][i] && map[1][i] == map[2][i]) {
                game_over++;  
                if(game_over_c != 'f')
                {
                    if(game_over_c != map[0][i]) double_win = true;
                }
                game_over_c = map[0][i];
                
            }
        }
        
        //  [\] 방향 대각선 체크
        if(map[0][0] != '.' && map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
                game_over++;  
                if(game_over_c != 'f')
                {
                    if(game_over_c != map[0][0]) double_win = true;
                }
                game_over_c = map[0][0];
            
        }
        
        // [/] 방향 대각선 체크
        if(map[0][2] != '.' && map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
                game_over++;  
                if(game_over_c != 'f')
                {
                    if(game_over_c != map[0][2]) double_win = true;
                }
                game_over_c = map[0][2];
            
        }
        
        if(game_over == 1)
        {
            if(game_over_c == 'O') // O로 게임을 끝냈다면
            {
                // X랑 O의 개수가 같아야 valid한 경우 
                if(x_cnt == o_cnt) cout << "valid\n";
                else cout << "invalid\n";
            } else // X로 게임이 끝났다면 
            {
                // X의 개수는 O보다 1개 많은 상황이어야 함 
                if(x_cnt - o_cnt == 1) cout << "valid\n";
                else cout << "invalid\n";
            }
        
        }
        else if (game_over >= 2) 
        {
            if(dot_cnt ==0 && !double_win) cout << "valid\n";
            else cout << "invalid\n";
        }
        else 
        {
            if(dot_cnt == 0) cout << "valid\n";
            else cout << "invalid\n";
        }
        
    }
}