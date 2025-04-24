#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N, M, L;
    cin >> N >> M >> L;
    
    vector<int> v(N+2);
    
    v[N] = 0;
    v[N+1] = L;
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int left = 1;
    int right = L;
    int ans = 1000;
    while(left <= right) {
        int sum = 0;
        int mid = (left + right) / 2;
        
        for(int i=1;i<v.size();i++){
            
            int distance = v[i] - v[i-1];
            
            int cnt = distance / mid;
            
            if(cnt > 0) {
                if(distance % mid == 0) {
                    sum += cnt - 1;
                } else {
                    sum += cnt;
                }
            }
        }
        
        
        if(sum > M) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ans = (mid > ans ? ans : mid);
        }
    }
    cout << ans;
    
}