#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int N, M, L, K, ans = 0;
    cin >> N >> M >> L >> K;
    
    vector<pair<int, int>> v(K);
    
    for(int i=0;i<K;i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            int x = v[i].first;
            int y = v[j].second;
            int count = 0;
            
            for(int k=0;k<K;k++){
                int kx = v[k].first;
                int ky = v[k].second;
                
                if(x <= kx && y <= ky && x + L >= kx && y + L >= ky) count++;
            }
            ans = max(ans, count);
        }
    }
    
    
    cout << K - ans;
}