// 11403 경로 찾기(https://www.acmicpc.net/problem/11403)
#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int mdistance[101][101];
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> mdistance[i][j];
        }
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(mdistance[i][k] && mdistance[k][j])
                    mdistance[i][j] = 1;
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << mdistance[i][j] << " ";
        }
        cout << "\n";
    }
}