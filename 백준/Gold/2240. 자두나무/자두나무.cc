#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][31];
int tree[1001];

int main()
{
    int T, W;
    cin >> T >> W;
    
    for(int i=1;i<=T;i++)
    {
        cin >> tree[i];
    }
    
    for(int t=1;t<=T;t++)
    {
        for(int w=0;w<=W;w++)
        {
            int position = (w % 2 == 0 ? 1 : 2);
            dp[t][w] = dp[t-1][w];
            
            if(w > 0)
            {
            dp[t][w] = max(dp[t][w], dp[t-1][w-1]);
            }
            
            if(position == tree[t]) dp[t][w]++;
        }
    }
    
    int ans = -1;
    for(int w=0;w<=W;w++)
    {
        ans = max(ans, dp[T][w]);
    }
    
    cout << ans;
}