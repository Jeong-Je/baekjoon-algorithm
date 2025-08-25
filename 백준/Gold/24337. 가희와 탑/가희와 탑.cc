#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, a, b;
    cin >> N >> a >> b;
    
    vector<int> ans_1;
    vector<int> ans_2;
    
    int max_h = max(a, b);
    
    for(int i=1;i<=a;i++)
    {
        if(i == a)
            ans_1.push_back(max_h);
        else 
            ans_1.push_back(i);
    }
    
    for(int i=b-1;i>=1;i--)
    {
        ans_2.push_back(i);
    }
    
    
    
    if(ans_1.size() + ans_2.size() > N)
    {
        cout << -1;
        return 0;
    }
    
    
    int add = N- (ans_1.size() + ans_2.size());
    
    if(add == 0)
    {
        for(int i=0;i<ans_1.size();i++)
            cout << ans_1[i] << " ";
        for(int i=0;i<ans_2.size();i++)
            cout << ans_2[i] << " ";
    }
    else 
    {
        if(a==1){
            for(int i=0;i<ans_1.size();i++)
                cout << ans_1[i] << " ";
            for(int i=0;i<add;i++)
                cout << "1 ";
            for(int i=0;i<ans_2.size();i++)
                cout << ans_2[i] << " ";
        }
        else
        {
            for(int i=0;i<add;i++)
                cout << "1 ";
            for(int i=0;i<ans_1.size();i++)
                cout << ans_1[i] << " ";
            for(int i=0;i<ans_2.size();i++)
                cout << ans_2[i] << " ";
        }
    }
}