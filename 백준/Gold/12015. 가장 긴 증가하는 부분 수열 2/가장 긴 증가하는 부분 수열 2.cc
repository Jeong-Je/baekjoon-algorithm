#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr, ans;

int binary(int key)
{
    int left = 0, right = ans.size() - 1;
    
    while(left < right)
    {
        int mid = (left + right) / 2;
        
        if(key > ans[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int main()
{
    cin >> N;
    
    arr.resize(N);
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    
    ans.push_back(arr[0]);
    
    for(int i=1;i<N;i++)
    {
        if(ans.back() < arr[i])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int idx = binary(arr[i]);
            ans[idx] = arr[i];
        }
    }
    
    cout << ans.size();
}