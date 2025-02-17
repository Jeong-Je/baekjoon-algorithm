#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    long mdistance[N+1][N+1];
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                mdistance[i][j] = 0;
            else 
                mdistance[i][j] = INT_MAX;
        }
    }
    
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        mdistance[a][b] = 1;
        mdistance[b][a] = 1;
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j])
                    mdistance[i][j] =  mdistance[i][k] + mdistance[k][j];
            }
        }
    }
    
    int min = INT_MAX;
    int result;
    for(int i=1;i<=N;i++){
        int tmp = 0;
        for(int j=1;j<=N;j++){
            tmp = tmp + mdistance[i][j];
        }
        if(tmp < min) {
            min = tmp;
            result = i;
        }
    }
    
    cout << result;

    return 0;
}