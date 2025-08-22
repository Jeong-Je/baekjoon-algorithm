#include <iostream>

using namespace std;


int main()
{
    int N, new_score, P;
    cin >> N >> new_score >> P;
    
    if(N == 0)
    {
        cout << 1;
        return 0;
    }
    
    int ans = -1;
    for(int i=1;i<=N;i++)
    {
        int score;
        cin >> score;
        
        if(score < new_score)
        {
            if(ans == -1) ans = i;
            break;
        }
        else if(score == new_score)
        {
            if(i == P) ans = -1;
            else if(ans == -1) ans = i;
        }
        
    }
    if(ans == -1 && N < P) ans = N+1;
    cout << ans;
}