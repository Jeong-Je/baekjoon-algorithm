#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, C;
    cin >> N >> C;
    
    vector<int> X(N+1);
    
    for(int i=1;i<=N;i++){
        cin >> X[i];
    }
    
    sort(X.begin(), X.end()); // 우선 정렬 (x축에 일렬로)
    
    int right = X[N] - X[1]; // 가잔 먼 거리
    int left = 1; // 가장 가까운 거리
    int result;
    while(left <= right) {
        int mid = (left + right) / 2; // 최소의 간격임 
        int router = 1;
        int start = X[1];
        
        for(int i=2;i<=N;i++){
            if(X[i] - start >= mid) { // 최소 간격보다 크거나 같으므로 공유기 설치
                router++;
                start = X[i];
            }
        }
        
        if(router >= C) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result;
}

