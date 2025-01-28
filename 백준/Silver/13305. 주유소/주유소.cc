#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<long long> distances(N-1);
    vector<long long> prices(N);
    
    for(int i=0;i<N-1;i++){
        cin >> distances[i];
    }
    
    for(int i=0;i<N;i++){
        cin >> prices[i];
    }
    
    long long result = 0;
    long long min_prices = prices[0];
    
    for(int i=0;i<N-1;i++) {
        if(i==0){
            result += prices[0] * distances[0];
        } else {
            if(min_prices > prices[i]) {
                min_prices = prices[i];
                result += min_prices * distances[i];
            } else {
                result += min_prices * distances[i];
            }
        }
    }
    
    cout << result;
    
    return 0;
}