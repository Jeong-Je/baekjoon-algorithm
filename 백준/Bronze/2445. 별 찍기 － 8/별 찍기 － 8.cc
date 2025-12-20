#include <iostream>


using namespace std;


int main()
{
    int N;
    cin >> N;
    
    int total = 2 * N;
    
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<i;j++) cout << "*";
        
        int space = total - i * 2;
        
        for(int j=0;j<space;j++)cout << " ";
        
        for(int j=0;j<i;j++) cout << "*";
        
        cout << "\n";
    }

    for(int i=N-1;i>0;i--)
    {
        for(int j=0;j<i;j++) cout << "*";
        
        int space = total - i * 2;
        
        for(int j=0;j<space;j++)cout << " ";
        
        for(int j=0;j<i;j++) cout << "*";
        
        cout << "\n";
    }
}