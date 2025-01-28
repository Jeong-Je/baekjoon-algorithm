#include <iostream>

using namespace std;

int gcd(long a, long b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long a, b;
    cin >> a >> b;
    
    int result = gcd(a,b);
    
    while(result--){
        cout << "1";
    }
}

int gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}