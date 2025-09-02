#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, ans = -1;
    cin >> N >> M;
    
    int x, pre = 0;
    for(int i=0;i<M;i++)
    {
        cin >> x;
        
        if(i == 0) ans = x;
        else ans = max(ans, (x - pre + 1) / 2);
        
        pre = x;
    }
    
    if(N - x > ans) ans = N - x;
    
    cout << ans;
}