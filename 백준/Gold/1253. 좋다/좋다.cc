#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> v(N);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int count = 0;
    
    for(int i=0;i<N;i++){
        int target = v[i];
        
        int left = 0;
        int right = N-1;
        
        while(left < right) {
            if(v[left] + v[right] == target) {
                if(left != i && right != i) {
                    count++; 
                    break;
                }
                else if(left == i) {
                    left++;
                } else if(right == i) {
                    right--;
                } 
            } else if (v[left] + v[right] < target) {
                left++;
            } else {
                right--;
            }
            
        }
    }
    
    cout << count;
}