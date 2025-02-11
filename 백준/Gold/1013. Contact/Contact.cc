//1013 Contact (https://www.acmicpc.net/problem/1013)
#include <iostream>

using namespace std;

bool check(string str);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        string pattern;
        cin >> pattern;
        
        if(check(pattern)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

bool check(string str){
    // (100+1+ | 01)+
    // 100..00..11 의 반복이거나 01의 반복
    
    int i=0;
    while(i < str.size()) {
       switch(str[i]) {
            case '0':
                i++;
                if(str.size() <= i || str[i] == '0')
                    return false;
                i++;
                break;
            case '1':
                i++;
                
                if(str.size() <= i || str[i] == '1')
                    return false;
                    
                i++;
                if(str.size() <= i || str[i] == '1')
                    return false;
                    
                while(1){
                    i++;
                    if(str.size() <= i) return false;
                    if(str[i] == '1') break;
                }
                
                while(1){
                    i++;
                    if(str.size() <= i) return true;
                    if(str[i] == '0') break;
                }
                
                // (100+1+ | 01)+
                
                i++;
                if(str.size() <= i) return false;
               
                if(str[i] == '1') {
                    i--;
                    break;
                } if(str[i] == '0') {
                    if(str[i-3] == '0') return false;
                    i-=2;
                    break;
                }
        }
    }
    return true;
    
}