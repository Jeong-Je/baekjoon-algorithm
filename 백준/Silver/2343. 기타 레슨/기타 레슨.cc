//   https://www.acmicpc.net/problem/2343
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    
    int start = 0;
    int end = 0;
    
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(start < v[i])
            start = v[i];
        end += v[i];
    }
    
    while(start<=end){
        int mid = (start + end) / 2;
        //cout << "start " << start << "mid " <<  mid << "end " << end << endl;
        
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<n;i++){
            
            if(sum + v[i] > mid){
                count++;
                sum = 0;
            }
            sum += v[i];
        }
        
        if(sum!=0){
            count++;
        }
        
        //cout << "count " << count << endl;
        
        if(count > m){
            start = mid+1;
        }
        else 
        {
            end = mid - 1;
        }
    }
    
    cout << start;
}