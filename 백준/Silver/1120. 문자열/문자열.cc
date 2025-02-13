#include <iostream>
#include <string>

using namespace std;

int main(){
    string A, B;
    cin >> A >> B;
    
    int cnt = 0;
    
    if(A.size() == B.size()) {
        for(int i=0;i<A.size();i++){
            if(A[i] != B[i]) cnt ++;
        }
    } else {
        cnt = A.size();
        for(int i=0;i <= B.size()-A.size();i++){
            int tmp_cnt = 0;
            for(int j=0;j<A.size();j++){
                if(A[j] != B[i+j]) {
                    tmp_cnt++;
                }
            }
            if(cnt > tmp_cnt) cnt = tmp_cnt;
        }
    }
    
    
    
    cout << cnt;
}