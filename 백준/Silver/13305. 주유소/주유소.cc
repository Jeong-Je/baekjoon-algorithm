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
    
    int point_17 = 0;
    
    for(int i=0;i<N-1;i++){
        point_17 += distances[i];
    }
    
    
    cout << point_17;
    return 0;
}