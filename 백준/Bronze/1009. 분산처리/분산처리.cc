// 1009 분산처리 (https://www.acmicpc.net/problem/1009)
#include <iostream>

using namespace std;

/*
3 9 27 81 243 729 2187 (3의 제곱들)
3 9  7  1   3   9    7 (1의 자리만 필요함)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int a, b;
        cin >> a >> b;
        
        int units = 1;
        for(int j=0;j<b;j++){
            units = units * a % 10;
        }
        
        if(units == 0) {
            cout << "10\n";
        } else {
            cout << units << "\n";
        }
    }
}