#include <iostream>
#include <vector>

using namespace std;

int arr[2][7];

int main()
{
    int N, K, ans  =0 ;
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++)
    {
        int sex, grade;
        cin >> sex >> grade;
        
        arr[sex][grade]++;
    }
    
    
    for(int i=0;i<2;i++){
        for(int j=1;j<=6;j++)
        {
            if(arr[i][j] == 0) continue;
            
            ans += arr[i][j] / K;
            
            if(arr[i][j] % K != 0) ans ++;
        }
    }
    
    cout << ans;
}