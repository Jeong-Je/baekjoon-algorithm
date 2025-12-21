#include <iostream>
#include <vector>

using namespace std;

bool arr[100001];

int main()
{
    int N, X, ans = 0;
    cin >> N;
    
    vector<int> v(N);
    
    for(int i=0;i<N;i++)
    {
        int num;
        cin >> num;
        
        arr[num] = 1;
        v[i] = num;
    }
    
    cin >> X;
    
    for(int i=0;i<N;i++)
    {
        if(X > v[i] && X-v[i] < 100001)
        {
            if(arr[X-v[i]] == 1) ans++;
        }
    }
    
    
    cout << ans / 2;
}