// 1075 나누기 (https://www.acmicpc.net/problem/1075)

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string N;
    int F;
    
    cin >> N >> F;
    
    for(int i=0;i<=99;i++){
        int last = i % 10;
        int last2 = i / 10;
        
        N[N.size()-1] = last + '0';
        N[N.size()-2] = last2 + '0';
        
        if(stoi(N) % F == 0) {
            cout << last2 << last;
            break;
        }
    }
}