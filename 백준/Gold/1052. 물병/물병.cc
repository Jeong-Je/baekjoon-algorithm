#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    if(N <= K) 
    {
        cout << 0;
    }
    else
    {
        int ans = 0;
        
        while(true)
        {
            int cnt = 0;
            int temp = N;
            
            while(temp > 0)
            {
                if(temp % 2 == 0)
                {
                    temp /= 2;
                }
                else
                {
                    temp /= 2;
                    cnt++;
                }
            }
            
            if(cnt <= K) break;
            
            N++;
            ans++;

            
        }
        cout << ans;
    }
}