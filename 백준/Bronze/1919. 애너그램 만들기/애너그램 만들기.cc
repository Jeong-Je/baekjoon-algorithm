#include <iostream>
#include <cmath>

using namespace std;

int alpha_a[26];
int alpha_b[26];

int main()
{
    string a, b;
    cin >> a >> b;
    
    for(int i=0;i<a.size();i++)
    {
        alpha_a[a[i] - 'a']++;
    }
    
    
    for(int i=0;i<b.size();i++)
    {
        alpha_b[b[i] - 'a']++;
    }
    
    int ans = 0;
    
    for(int i=0;i<26;i++)
    {
        if(alpha_a[i] == alpha_b[i]) continue;
        
        ans += abs(alpha_a[i] - alpha_b[i]);
    }
    
    cout << ans;
}