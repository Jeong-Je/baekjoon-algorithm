#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int Y = 0, M = 0;
    for(int i=0;i<N;i++)
    {
        int sec;
        cin >> sec;
        
        Y += ((sec / 30) + 1) * 10;
        
        M += ((sec / 60) + 1) * 15;
        
        
    }
    
    if(Y < M) cout << "Y" << " " << Y;
    else if(M < Y) cout << "M" << " " << M;
    else cout << "Y M " << Y;
}