#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> sol(N);
    
    for(int i=0;i<N;i++){
        cin >> sol[i];
    }
    
    int left = 0, right = N-1;
    int ans_left = left, ans_right = right;
    int min_sum = abs(sol[left] + sol[right]);
    
    while(left < right) {
        int cur_sum = sol[left] + sol[right];
        
        if(abs(cur_sum) < min_sum) {
            min_sum = abs(cur_sum);
            ans_left = left;
            ans_right = right;
        }
        
        if(cur_sum == 0) {
            break;
        }
        
        if(cur_sum < 0) {
            left++;
        } else {
            right --;
        }
    }
    
    
    cout << sol[ans_left] << " " << sol[ans_right];
}