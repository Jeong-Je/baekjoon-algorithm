/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    vector<int> sum(n-k+1);
    
    for(int i=0;i<k;i++){
        cin >> v[i];
        sum[0] += v[i];
    }
    
    int m =1;
    for(int i=k;i<n;i++){
        cin >> v[i];
        sum[m] = v[i] + sum[m-1] - v[i-k];
        m++;
    }
    
    int max = *max_element(sum.begin(), sum.end());
    cout << max;
    
    return 0;
}