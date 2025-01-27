#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long min, max;
    cin >> min >> max;
    
    bool check[max-min+1] = {};
    
    for(long long i = 2; i * i <= max; i++) {
        long long pow = i * i;
        
        long long start = min / pow;
    
    
        if(min%pow!=0) start++;
        
        for(long long j = start; j*pow <= max; j++) {
            check[(pow*j) - min] = true;
        }
        
    }
    
    int cnt = 0;
    
    for(int i=0; i<max-min+1;i++){
        if(!check[i]) cnt++;
    }
    
    cout << cnt;
}