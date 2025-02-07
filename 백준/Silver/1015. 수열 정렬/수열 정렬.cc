// 1015 수열 정렬 (https://www.acmicpc.net/problem/1015)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    
    vector<pair<int, int>> A(N);
    vector<int> P(N);
    
    for(int i=0; i<N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    
    sort(A.begin(), A.end());
    
    for(int i=0;i<N;i++){
        P[A[i].second] = i;
    }
    
    
    for(int i=0;i<N;i++){
        cout << P[i] << " ";
    }
    
}