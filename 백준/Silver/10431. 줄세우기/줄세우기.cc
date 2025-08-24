#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int P;
    cin >> P;
    
    for(int i=1;i<=P;i++)
    {
        int t, a, cnt = 0;
        
        cin >> t;
        vector<int> v;
        for(int j=0;j<20;j++){
            cin >> a;
            
            
            if(j==0){v.push_back(a); continue;}
            int k = j -1;
            while(k > -1 && v[k] > a)
            {
                cnt++;
                k--;
            }
            v.insert(v.begin() + (++k), a);
        }
        cout << i << " " << cnt << "\n";
    }
}