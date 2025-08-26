#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cctv_cnt = 0, ans = 64;
static int arr[8][8];
static int cctv_arrange[8];
vector<pair<int, int>> cctv1;
vector<pair<int, int>> cctv2;
vector<pair<int, int>> cctv3;
vector<pair<int, int>> cctv4;
vector<pair<int, int>> cctv5;


void backTracking(int cnt);
void cctv1_run();
void cctv2_run();
void cctv3_run();
void cctv4_run();
void cctv5_run();

void look_right(int row, int column);
void look_up(int row, int column);
void look_left(int row, int column);
void look_down(int row, int column);

int blind_spot_check();

void clean();

int main()
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1) cctv1.push_back({i, j});
            else if(arr[i][j] == 2) cctv2.push_back({i, j});
            else if(arr[i][j] == 3) cctv3.push_back({i, j});
            else if(arr[i][j] == 4) cctv4.push_back({i, j});
            else if(arr[i][j] == 5) cctv5.push_back({i, j});
        }
    }
    
    cctv_cnt = cctv1.size() + cctv2.size() + cctv3.size() + cctv4.size() + cctv5.size();

    backTracking(0);
    
    cout << ans;
}

void backTracking(int cnt)
{
    if(cnt == cctv_cnt)
    {
        cctv1_run();
        cctv2_run();
        cctv3_run();
        cctv4_run();
        cctv5_run();
        
        int blind_spot_cnt = blind_spot_check();
        ans = min(ans, blind_spot_cnt);
        
        clean();
        
        return;
    }
    
    for(int i=1;i<=4;i++)
    {
        cctv_arrange[cnt] = i;
        backTracking(cnt + 1);
    }
}

void clean()
{
    for(int i=0;i<cctv1.size();i++)
    {
        auto [row, column] = cctv1[i];
        arr[row][column] = 1;
    }
    for(int i=0;i<cctv2.size();i++)
    {
        auto [row, column] = cctv2[i];
        arr[row][column] = 2;
    }
    for(int i=0;i<cctv3.size();i++)
    {
        auto [row, column] = cctv3[i];
        arr[row][column] = 3;
    }
    for(int i=0;i<cctv4.size();i++)
    {
        auto [row, column] = cctv4[i];
        arr[row][column] = 4;
    }
    for(int i=0;i<cctv5.size();i++)
    {
        auto [row, column] = cctv5[i];
        arr[row][column] =5;
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(arr[i][j] == '#')
            {
                arr[i][j] = 0;
            }
        }
    }
}

int blind_spot_check()
{
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(0 <= arr[i][j] && arr[i][j] <= 5) cnt++;
        }
    }
    
    return cnt;
}

void look_right(int row, int column)
{
    for(int i = column; i<M;i++)
    {
        if(arr[row][i] == 6) return;
        arr[row][i] = '#';
    }
}

void look_left(int row, int column)
{
    for(int i=column;i>-1;i--)
    {
        if(arr[row][i] == 6) return;
        arr[row][i] = '#';
    }
}

void look_up(int row, int column)
{
    for(int i = row; i > -1;i--)
    {
        if(arr[i][column] == 6) return;
        arr[i][column] = '#';
    }
}

void look_down(int row, int column)
{
    for(int i=row;i<N;i++)
    {
        if(arr[i][column] == 6) return;
        arr[i][column] = '#';
    }
}

void cctv1_run()
{
    for(int i=0;i<cctv1.size();i++)
    {
        auto [row, column] = cctv1[i];
        int direction = cctv_arrange[i];
        
        if(direction == 1)
        {
            look_right(row, column);
        } else if(direction == 2)
        {
            look_up(row, column);
        } else if(direction == 3)
        {
            look_left(row, column);
        } else if(direction == 4)
        {
            look_down(row, column);
        }
    }
}

void cctv2_run()
{
    for(int i=0;i<cctv2.size();i++)
    {
        auto [row, column] = cctv2[i];
        int direction = cctv_arrange[cctv1.size() + i];
        
        if(direction == 1 || direction == 3)
        {
            look_right(row, column);
            look_left(row, column);
        } else
        {
            look_up(row, column);
            look_down(row, column);
        }
    }
}

void cctv3_run()
{
    for(int i=0;i<cctv3.size();i++)
    {
        auto [row, column] = cctv3[i];
        int direction = cctv_arrange[cctv1.size() + cctv2.size() + i];
        
        if(direction == 1)
        {
            look_up(row, column);
            look_right(row, column);
        } else if(direction == 2)
        {
            look_down(row,column);
            look_right(row, column);
        } else if(direction == 3)
        {
            look_down(row,column);
            look_left(row, column);
        } else {
            look_left(row, column);
            look_up(row, column);
        }
    }
}

void cctv4_run()
{
    for(int i=0;i<cctv4.size();i++){
        auto [row, column] = cctv4[i];
        int direction = cctv_arrange[cctv1.size() + cctv2.size() + cctv3.size() + i];
        
    if(direction == 1)
    {
        look_up(row, column);
        look_right(row, column);
        look_left(row, column);
    } else if(direction == 2)
    {
        look_up(row, column);
        look_right(row, column);
        look_down(row, column);
    } else if(direction == 3)
    {
        look_right(row, column);
        look_down(row, column);
        look_left(row, column);
    } else // direction == 4
    {
        look_down(row, column);
        look_left(row, column);
        look_up(row, column);
    }

    }
}

void cctv5_run()
{
    for(int i=0;i<cctv5.size();i++){
        auto [row, column] = cctv5[i];
        
        look_up(row, column);
        look_right(row, column);
        look_left(row, column);
        look_down(row,column);

    }
}