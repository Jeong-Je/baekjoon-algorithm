#include <iostream>

using namespace std;

int freq_a[26];
int freq_b[26];

int main()
{
    int T;
    cin >> T;
    
    
    for(int i=0;i<T;i++)
    {
        string a, b;
        
        cin >> a >> b;
        
        fill(freq_a, freq_a+26, 0);
        fill(freq_b, freq_b+26, 0);
        
        for(int i=0;i<a.size();i++)
        {
            freq_a[a[i]-'a']++;
        }
        
        for(int i=0;i<b.size();i++)
        {
            freq_b[b[i]-'a']++;
        }
        
        bool possible = true;
        for(int i=0;i<26;i++)
        {
            if(freq_a[i] != freq_b[i]) 
            {
                possible = false; 
                break;
            }
        }
        
        if(possible)
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}