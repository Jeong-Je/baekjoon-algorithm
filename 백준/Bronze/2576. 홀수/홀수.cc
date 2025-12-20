#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum = 0, min = 100;
    
    for(int i=0;i<7;i++)
    {
        int num;
        cin >> num;
        
        if(num%2 == 1) 
        {
            sum += num;
            
            if(num < min) min = num;
        }
        
    }
    
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << min;
}