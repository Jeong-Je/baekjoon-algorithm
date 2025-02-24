#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> buildings(N+1);
    vector<int> answer(N+1);
    
    for(int i=1;i<=N;i++){
        cin >> buildings[i];
    }
    
    for(int i=1;i<=N;i++){
        double max_level = INT_MIN;
        for(int j=i+1;j<=N;j++){
            double level = (double)(buildings[j] - buildings[i]) / (j - i);
            if(level > max_level) {
                answer[i]++; answer[j]++;
                max_level = level;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer[N];
}