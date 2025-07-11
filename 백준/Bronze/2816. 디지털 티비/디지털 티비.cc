#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<string> v(N);
    
    int kbs1_idx, kbs2_idx;
    for(int i=0;i<N;i++){
        cin >> v[i];
        
        if(v[i] == "KBS1") kbs1_idx = i;
        if(v[i] == "KBS2") kbs2_idx = i;
    }
    
    for(int i=0; i < kbs1_idx; i++){
        cout << 1;
    }
    
    for(int i=0; i < kbs1_idx; i++){
        cout << 4;
    }
    
    if(kbs1_idx > kbs2_idx) kbs2_idx++;
    
    for(int i=0; i < kbs2_idx; i++){
        cout << 1;
    }
    
    for(int i=0; i < kbs2_idx - 1; i++){
        cout << 4;
    }
}