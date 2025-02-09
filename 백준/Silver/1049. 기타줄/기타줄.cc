// 1049 기타줄 (https://www.acmicpc.net/problem/1049)
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int package_min = 1000;
    int piece_min = 1000;
    
    for(int i=0;i<M;i++){
        int package_price, piece_price;
        
        cin >> package_price >> piece_price;
        
        if(package_price < package_min) {
            package_min = package_price;
        }
        
        if(piece_price < piece_min) {
            piece_min = piece_price;
        }
    }
    
    int tmp1 = package_min*(N / 6) + piece_min*(N % 6);
    int tmp2 = package_min*((N/6)+1);
    int tmp3 = piece_min * N;
    
    int result = tmp1 <= tmp2 ? tmp1 : tmp2;
    
    result = result <= tmp3 ? result : tmp3;
    
    
    cout << result;
    
}