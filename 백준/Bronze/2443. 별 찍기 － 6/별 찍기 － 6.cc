#include <iostream>


using namespace std;


int main()
{
    int N;
    cin >> N;
    
    int total_star = 2 * N - 1;
    
    for(int i=0;i < N;i++)
    {
        int now_space = i;
        
        int star = total_star - (now_space * 2);
        
        for(int j=0;j<now_space;j++) cout << " ";
        for(int j=0;j<star;j++)  cout << "*";
        cout << "\n";
    }
    
}