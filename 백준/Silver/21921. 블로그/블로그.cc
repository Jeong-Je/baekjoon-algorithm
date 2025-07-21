#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    
    vector<int> visitor(N);
    
    for(int i=0;i<N;i++) {
        cin >> visitor[i];
    }

    int max = 0;
    int count = 1;
    for(int i=0;i<X;i++){
        max += visitor[i];
        
    }

    int left = 0, right = X - 1;
    int sum = max;
    for(int i=right+1;i<N;i++){
        sum += visitor[i];
        sum -= visitor[left++];

        if(sum == max) count ++;
        else if(sum > max) {
            max = sum;
            count = 1;
        }
    }
    
    
    if(max == 0) {
        cout << "SAD";
    } else {
        cout << max << "\n" << count;
    }
    
}