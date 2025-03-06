#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N);
    
    int max = 0;
    for(int i=0;i<N;i++){
        cin >> v[i];
        if(v[i] > max) max = v[i];
    }
    
    int left = 0, right = max, mid;
    int result;
    while(left<=right){
        mid = (left+right) / 2;
        
        long long tmp = 0;
        for(int i=0;i<N;i++){
            if(v[i] > mid){
                tmp += v[i] - mid;
            }
        }
        
        
        if(tmp >= M){ // 만든 나무가 너무 길 경우 -> 더 높이서 자르자
            left = mid + 1;
            result = mid;
        } else { // 만든 나무가 너무 짧아 -> 더 낮은 곳에서 자르자
            right = mid - 1;
        }
    }
    cout << result;
}