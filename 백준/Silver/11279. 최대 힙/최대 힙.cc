// 11279 최대 힙 (https://www.acmicpc.net/problem/11279)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>> pq;
    
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        
        if(x) {
            pq.push(x);
        } else {
            if(pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();   
            }
        }
    }
}