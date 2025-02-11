// 1072 게임 (https://www.acmicpc.net/problem/1072)
#include <iostream>

#define MAX 1000000000

using namespace std;

int main(){
    int X, Z;
    long Y;
    cin >> X >> Y;
    
    Z = Y*100/X;
    
    if(Z >= 99) {
        cout << -1;
        return 0;
    }
    
    int left=0, right=MAX;
    
    while(left<=right) {
        int mid = (left+right)/2;
        int tmp = (Y+mid) * 100 / (X+mid);
        
        if(Z < tmp) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left;
}