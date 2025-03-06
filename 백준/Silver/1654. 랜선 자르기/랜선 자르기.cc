#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned int N, K;
    cin >> K >> N;
    
    vector<int> v(K);
    
    unsigned int max = 0;
    for(int i=0;i<K;i++){
        cin >> v[i];
        if(max < v[i]) 
            max = v[i];
    }
    
    unsigned int left = 1, right = max, mid;
    
    unsigned int result = 0;
    while(left<=right) {
        mid = (left + right) / 2;
        
        int cnt = 0;
        for(int i=0;i<K;i++){
            cnt += v[i] / mid;
        }
        
        if(cnt >= N) { // 너무 많이 만들었다면 -> 길이를 더욱 길게
            left = mid + 1;
            result = mid;
        } else { // 개수가 부족하다면 -> 길이를 더욱 짧게
            right = mid - 1;
        }
    }
    cout << result;
}