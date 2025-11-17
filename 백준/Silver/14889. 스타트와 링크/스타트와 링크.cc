#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N, start_team_score = 0, link_team_score = 0, ans = INT_MAX;
vector<vector<int>> v;
vector<bool> check;


void back_tracking(int start, int count);
void calc_score_diff();

int main()
{
    cin >> N;
    
    v.resize(N);
    check.resize(N);
    
    for(int i=0;i<N;i++)
    {
        v[i].resize(N);
        for(int j=0;j<N;j++)
        {
            cin >> v[i][j];
        }
    }
    
    back_tracking(0, 0);
    
    cout << ans;
}

void calc_score_diff()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(check[i] == check[j])
            {
                int score_sum = v[i][j] + v[j][i];
                if(check[i] == 0) start_team_score += score_sum;
                else link_team_score += score_sum;
            }
        }
    }
    
    ans = min(ans, abs(start_team_score - link_team_score) / 2);
}

void back_tracking(int start, int count)
{
    if(count == N / 2)
    {
        start_team_score = link_team_score = 0;
        calc_score_diff();
        return;
    }
    
    
    for(int i=start;i<N;i++)
    {
        if(check[i] == true) continue;
        
        check[i] = true;
        
        back_tracking(i+1, count+1);
        
        check[i] = false;
        
    }
}