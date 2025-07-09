#include <iostream>

using namespace std;

int arr[1000000];

int main() {
    int N, B, C;
    long long count = 0;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    cin >> B >> C;
    
    for(int i=0;i<N;i++){
        int remain = arr[i] - B;
        count++; // 총감독관
        
        if(remain > 0) {
            // 부감독관
            if(remain % C == 0) count += remain / C;
            else count += remain / C + 1;
        }
    }
    
    cout << count;
}