#include<iostream>

using namespace std;
using ll = long long;

void swap(int& A, int& B)
{
    int temp = A;
    A = B;
    B = temp;
}

int main()
{
    ll A, B;
    cin >> A >> B;
    
    if(A > B) swap(A, B);
    
    int cnt = B - A - 1;
    if(cnt < 0) cnt = 0;
    
    cout << cnt << "\n";
    for(ll i=A+1;i<B;i++)
    {
        cout << i << " ";
    }
}

