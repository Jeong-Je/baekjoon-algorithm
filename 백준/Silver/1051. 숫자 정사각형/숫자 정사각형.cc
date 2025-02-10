// 1051 숫자 정사각형 (https://www.acmicpc.net/problem/1051)
#include <iostream>

using namespace std;

static int arr[51][51];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int side_length = N < M ? N : M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(side_length; side_length > 0; side_length--){
        for(int i=1; i+side_length-1 <= N; i++){
            for(int j=1;j+side_length-1 <= M; j++) 
                if(arr[i][j] == arr[i][j+side_length-1] && arr[i][j+side_length-1] == arr[i+side_length-1][j] && arr[i+side_length-1][j] == arr[i+side_length-1][j+side_length-1]) {
                    cout << side_length * side_length;
                    return 0;
            } 
        }
    }

    
    cout << "1";
    
    return 0;
    
}
