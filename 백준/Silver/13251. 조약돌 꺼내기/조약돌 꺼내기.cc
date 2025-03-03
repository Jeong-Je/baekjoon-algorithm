#include <iostream>

using namespace std;

static int D[51];

int main(){
    int M, K, T = 0;
    cin >> M;
    
    
    for(int i=0;i<M;i++){
        cin >> D[i];
        T += D[i];
    }
    
    cin >> K;
    
    double ans = 0.0;
    for(int i=0;i<M;i++){
        double p = 1.0;
        for(int k=0;k<K;k++){
            p *= (double)(D[i] - k) / (T - k);
        }
        ans += p;
    }
    
    cout << fixed;
    cout.precision(9);
    cout << ans;
}