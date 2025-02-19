#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--){
        long long x, y;
        cin >> x >> y;
        
        double dis = y - x;
        double dpow = sqrt(dis);
        int pow = round(dpow);
        
        if(dpow <= pow) cout << pow * 2 - 1 << "\n";
        else cout << pow * 2 << "\n";
    }
}