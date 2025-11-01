#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int L, N, ans = 0;
    cin >> L; // 집합 S의 크기
    
    vector<int> v(L);
    
    for(int i=0;i<L;i++)
    {
        cin >> v[i];
    }
    
    cin >> N;
    
    int left = 0, right = 1001;
    bool impossible = false;
    for(int i=0;i<L;i++)
    {
        if(v[i] < N && left < v[i]) left = v[i];
        if(v[i] > N && right > v[i]) right = v[i];
        
        if(v[i] == N)
        {
            impossible = true;
            break;
        }
    }
    
    if(impossible)
    {
        cout << 0;
    }
    else
    {
        
        cout << (N - left) * (right - N) - 1;
        
    }
}