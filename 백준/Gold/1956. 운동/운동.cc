#include <iostream>
#include <limits.h>

using namespace std;

static long mdistance[401][401];

int main(){
    int V, E;
    cin >> V >> E;
    
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            if(i==j)mdistance[i][j] = 0;
            else mdistance[i][j] = INT_MAX;
        }
    }
    
    for(int i=0;i<E;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(mdistance[a][b] > c) mdistance[a][b] = c;
    }
    
    
    
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j]) {
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    
    int min = INT_MAX;
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            if(i==j)continue;
            if(min > mdistance[i][j] + mdistance[j][i]) min = mdistance[i][j] + mdistance[j][i];
        }
    }
    
    cout << (min == INT_MAX ? -1 : min);
}