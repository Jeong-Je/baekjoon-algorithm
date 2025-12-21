#include <iostream>

using namespace std;


int freq[10];

int main()
{
    int N, ans = -1;
    cin >> N;
    
    while(N)
    {
        int num = N % 10;
        
        if(num != 6 && num != 9)
        {
            freq[num]++;
        }
        
        else
        {
            if(freq[6] < freq[9]) freq[6]++;
            else freq[9]++;
        }
        
        N /= 10;
    }
    
    for(int i=0;i<10;i++)
    {
        if(ans < freq[i]) ans = freq[i];
    }
    
    cout << ans;
}