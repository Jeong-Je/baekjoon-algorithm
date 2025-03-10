#include <iostream>

using namespace std;

int main(){
    int H,W,N,M;
    cin >> H >> W >> N >> M;
    
    int cnt_w = 0;
    for(int i=1;i<=W;i+=M+1) {
        cnt_w++;
    }
    
    int cnt_h = 0;
    for(int i=1;i<=H;i+=N+1){
        cnt_h++;
    }
    
    cout << cnt_w * cnt_h;
}