// 1026 보물 (https://www.acmicpc.net/problem/1026)

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(short a, short b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    short N;
    cin >> N;
    
    short A[N];
    short B[N];
    
    for(short i=0;i<N;i++){
        cin >> A[i];
    }
    
    for(short i=0;i<N;i++){
        cin >> B[i];
    }
    
    sort(A, A+N);
    sort(B, B+N, cmp);
    
    int result = 0;
    
    for(short i=0;i<N;i++){
        result += B[i] * A[i];
    }

    cout << result;
    
}

bool cmp(short a, short b) {
    return a > b;
}