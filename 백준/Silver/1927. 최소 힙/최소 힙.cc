// 1927 최소 힙 (https://www.acmicpc.net/problem/1927)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
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