// 11404 플로이드 (https://www.acmicpc.net/problem/11404)
#include <iostream>
#include <limits.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    long mdistance[101][101]; // 배열 선언
    
    for(int i=1;i<=n;i++){ // 배열 초기화
        for(int j=1;j<=n;j++){
            if(i==j) {
                mdistance[i][j] = 0;
            } else {
                mdistance[i][j] = INT_MAX;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(mdistance[a][b] > c)
            mdistance[a][b] = c;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j])
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
            }
        }
    }
    
    for(int i=1;i<=n;i++){ // 배열 초기화
        for(int j=1;j<=n;j++){
            if(mdistance[i][j] == INT_MAX) {
                cout << 0 << " ";
            } else {
                cout << mdistance[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
}