#include <iostream>

using namespace std;

int arr[5][8];

void turn_wheel(int num, int dic);

int main()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<8;j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    
    int K;
    cin >> K;
    
    for(int i=0;i<K;i++)
    {
        bool turn[5] = {false, false, false, false, false};
        int dirt[5] = {0, 0, 0, 0, 0};
        int n, d;
        cin >> n >> d;
        
        turn[n] = true;
        dirt[n] = d; // 1은 시계방향, -1인 경우 반시계 방향
    
        // n번 바퀴의 왼쪽 바퀴들 체크하기
        for(int j=n-1;j>0;j--)
        {
            if(arr[j][2] == arr[j+1][6]) break; // 같은 극 회전 안함 + 회전 연쇄 멈춤 
            else // 다른 극 
            {

                // 왼쪽도 같이 돎 
                turn[j] = true;
                
                // 다른 방향으로 돎 
                if(dirt[j+1] == 1) dirt[j] = -1;
                else dirt[j] = 1;

            }
        }
        
        
        // n번 바퀴의 오른쪽 바퀴들 체크하기 
        for(int j=n+1;j<5;j++)
        {
            if(arr[j][6] == arr[j-1][2]) break; // 같은 극 회전 안함 + 회전 연쇄 멈춤 
            else // 다른 극
            {
                turn[j] = true;
                
                if(dirt[j-1] == 1) dirt[j] = -1;
                else dirt[j] = 1;
            }
        }
    
        for(int j=1;j<=4;j++)
        {
            if(turn[j] == true)
            {
                turn_wheel(j, dirt[j]);
            }
        }
    }
    
    
    int ans = 0;
    

    if(arr[1][0] == 1) ans += 1;
    if(arr[2][0] == 1) ans += 2;
    if(arr[3][0] == 1) ans += 4;
    if(arr[4][0] == 1) ans += 8;
    
    cout << ans;
}


void turn_wheel(int num, int dic)
{
    if(dic == 1) // 시계 방향 회전 
    {
        int temp = arr[num][7];
        
        for(int i=7;i>0;i--)
        {
            arr[num][i] = arr[num][i-1];
        }
        
        arr[num][0] = temp;
    }
    
    else // 반시계 방향 회전 
    {
        int temp = arr[num][0];
        
        for(int i=0;i<7;i++)
        {
            arr[num][i] = arr[num][i+1];
        }
        
        arr[num][7] = temp;
    }
    
    return;
}