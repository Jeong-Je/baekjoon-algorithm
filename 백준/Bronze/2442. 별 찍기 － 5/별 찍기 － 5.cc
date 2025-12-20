#include <iostream>


using namespace std;


int main()
{
    int N;
    cin >> N;
    
    int total_star = 2 * N - 1;
    
    for(int i=1;i<=N;i++)
    {
        int now_star = 2 * i - 1;
        
        int space = total_star - now_star;
        
        for(int j=0;j<space / 2;j++) cout << " ";
        for(int j=0;j<now_star;j++)  cout << "*";
        cout << "\n";
    }
    
}