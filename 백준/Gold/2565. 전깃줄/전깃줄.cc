#include <iostream>

using namespace std;

int dp[501];
int arr[501];

int main()
{
    int N;
    cin >> N;
    
    int max_a_line = -1;
    for(int i=0;i<N;i++)
    {
        int a, b;
        cin >> a >> b;
        
        arr[a] = b;
        
        if(max_a_line < a) max_a_line = a;
    }
    
    
    for(int i=1;i<=max_a_line;i++)
    {
        if(arr[i] == 0) continue;
        dp[i] = 1;
        for(int j=1;j<i;j++)
        {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j];
                dp[i] += 1;
            }
        }
    }
    
    
    int lis = -1;
    for(int i=1;i<=max_a_line;i++)
    {
        if(dp[i] > lis) lis = dp[i];
    }
    
    cout << N - lis;
}