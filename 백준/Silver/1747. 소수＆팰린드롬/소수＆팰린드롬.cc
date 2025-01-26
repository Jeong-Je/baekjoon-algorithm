#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isPalindrome(int answer);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    long A[10000001];
    
    for(int i=2;i < 10000000; i++){
        A[i] = i;
    }
    
    for(int i=2;i<=sqrt(10000000);i++) {
        if(A[i] == 0) continue;
        
        for(int j=2; i*j < 10000001; j++) {
            A[i*j] = 0;
        }
    }
    
    int answer = N;
    
    while(true) {
        if(A[answer]) {
            if(isPalindrome(answer)) {
                cout << answer;
                break;
            }
        }
        answer++;
    }
    
    return 0;
}


bool isPalindrome(int answer) {
    string str = to_string(answer);
    
    int s = 0;
    int e = str.size()-1;
    
    while(s < e) {
        if(str[s] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    
    return true;
}