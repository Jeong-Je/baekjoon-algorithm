#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int num, maxTail, maxSoFar;
    
    cin >> num;
    maxTail = maxSoFar = num;
    
    for(int i=1;i<N;i++){
        cin >> num;
        maxTail = max(maxTail+num, num);
        maxSoFar = max(maxTail, maxSoFar);
    }
    
    cout << maxSoFar;
}