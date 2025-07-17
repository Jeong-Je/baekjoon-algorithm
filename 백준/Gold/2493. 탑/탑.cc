#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    // { 값 , 인덱스 } 
    stack<pair<int, int>> stk;
    
    for(int i=1;i<=N;i++){
        int h;
        cin >> h;
        
        if(stk.empty()) {
            cout << "0 ";
            stk.push({h, i});
        } else {
            while(!stk.empty()) {
                auto [value, index] = stk.top();
                //cout << value << " " << index << endl;
                
                if(value > h){ 
                    cout << index << " ";
                    break;
                } else {
                    stk.pop();
                }
            }
            
            if(stk.empty()) cout << "0 ";
            stk.push({h, i});
        }
    }
}