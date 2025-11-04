#include <iostream>
#include <string>
#include <cmath>


using namespace std;

char map[9][9];

bool is_square(int num)
{
    return sqrt(num) == (int)sqrt(num);
}

int max(int a, int b)
{
    if(a < b) return b;
    return a;
}

int main()
{
    int N, M, ans = -1;
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int di=-N;di<N;di++)
            {
                for(int dj=-M;dj<M;dj++)
                {
                    if(di == 0 && dj == 0) continue;
                    int x = i, y = j;
                    string num = "";
                    
                    while(x >= 0 && x < N && y >= 0 && y < M)
                    {
                        num += map[x][y];
                        if(is_square(stoi(num)))
                        {
                            ans = max(ans, stoi(num));
                        }
                        x += di;
                        y += dj;
                    }
                    
                }
            }
        }
    }
    
    cout << ans;
}