// 1004 어린왕자 https://www.acmicpc.net/problem/1004
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int N, cnt=0;
        cin >> N;
        for(int j=0;j<N;j++){
            int cx, cy, r;
            cin >> cx >> cy >> r;
            
            bool is_start_inner = sqrt(pow(x1-cx, 2) + pow(y1-cy,2)) < r;
            bool is_end_inner = sqrt(pow(x2-cx, 2) + pow(y2-cy,2)) < r;
            
            if(is_start_inner != is_end_inner) 
            {
                cnt++;
            }
            

        }
        cout << cnt << "\n";
    }
}