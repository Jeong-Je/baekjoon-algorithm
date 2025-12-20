#include <iostream>


using namespace std;


int main()
{
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        int space = i;
        int star = N-i;
        
        for(int j=0;j<space;j++)
        {
            cout << " ";
        }
        
        for(int j=0;j<star;j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}