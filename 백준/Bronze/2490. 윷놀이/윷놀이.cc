#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    for(int j=0;j<3;j++)
    {
        int back = 0, front = 0;
        for(int i=0;i<4;i++)
        {
            int a;
            cin >> a;
            
            if(a == 0) back++;
            else front++;
        }
        
        if(back == 1) cout << "A\n";
        else if(back == 2) cout << "B\n";
        else if(back == 3) cout << "C\n";
        else if(back == 4) cout << "D\n";
        else cout << "E\n";
    }
}