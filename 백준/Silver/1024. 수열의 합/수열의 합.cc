#include <iostream>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    
    int mul = 0, plu = 0;
    for(int i=2;i<=100;i++)
    {
        mul = i;
        plu = plu + i - 1;
        
        if(i < L) continue;
        
        if((N - plu) % mul == 0)
        {
            int a = (N - plu) / mul;
            if(a < 0) continue;
            for(int j=0;j<i;j++)
            {
                cout << a << " ";
                a++;
            }
            return 0;
        }
    }
    
    cout << -1;
}