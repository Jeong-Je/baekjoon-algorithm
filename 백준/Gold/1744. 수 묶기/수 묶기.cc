#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    priority_queue<int> pq1; // 내림차순 정렬 (양수)
    priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순 정렬 (음수)
    int one = 0;
    int zero = 0;
    
    for(int i=0;i<N;i++){
        int data;
        cin >> data;
        
        if(data>1){
            pq1.push(data);
        } else if (data < 0) {
            pq2.push(data);
        } else if (data == 0) {
            zero++;
        } else {
            one ++;
        }
    }
    
    
    int sum = 0;
    
    while(pq1.size() > 1) {
        int data1 = pq1.top();
        pq1.pop();
        int data2 = pq1.top();
        pq1.pop();
        
        sum += data1 * data2;
    }
    if(!pq1.empty()) {
        sum += pq1.top();
        pq1.pop();
    }
    
    while(pq2.size() > 1) {
        int data1 = pq2.top();
        pq2.pop();
        int data2 = pq2.top();
        pq2.pop();
        
        sum += data1 * data2;
    }
    
    if(!pq2.empty()){
        if(zero == 0) {
            sum += pq2.top();
            pq2.pop();
        }
    }
    
    sum += one;
    
    cout << sum;
}