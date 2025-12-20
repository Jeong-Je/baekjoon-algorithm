#include <iostream>


using namespace std;


int main()
{
    int N;
    cin >> N;
    
    
    for(int i=0;i<N;i++)
    {
        // 공백 출력
        for(int j=0;j<i;j++) cout << " ";
        
        // 별 출력
        for(int j=i*2;j<2*N-1;j++) cout << "*";
        
        cout << "\n";
    }
    
    for(int i=N-2;i>=0;i--)
    {
        // 공백 출력
        for(int j=0;j<i;j++) cout << " ";
        
        // 별 출력
        for(int j=i*2;j<2*N-1;j++) cout << "*";
        
        cout << "\n";
    }
}