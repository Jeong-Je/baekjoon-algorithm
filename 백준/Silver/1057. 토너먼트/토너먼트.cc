#include <iostream>

using namespace std;

int main()
{
    int N, kim, lim, ans = 0;
    cin >> N >> kim >> lim;
    
    while(kim != lim)
    {
        int kim_next = (kim + 1) / 2;
        int lim_next = (lim + 1) / 2;
        
        if(kim_next == lim_next)
        {
            break;
        }
        else
        {
            kim = kim_next;
            lim = lim_next;
            ans++;
        }
    }
    
    cout << ans + 1;
}