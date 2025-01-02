/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int map[26][26];
static int N;
static bool visited[26][26];
static vector<int> result;

void DFS(int i, int j);

int cnt;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int main(){
    
    cin >> N;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visited[i][j] && map[i][j]){
                cnt = 0;
                DFS(i, j);
                result.push_back(cnt);
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
}

void DFS(int i, int j){
    visited[i][j] = true;
    cnt++;
    for(int k=0;k<4;k++){
        
        int next_x = i + mx[k];
        int next_y = j + my[k];
        
        if(next_x > 0 && next_x <= N && next_y > 0 && next_y <= N){
            if(!visited[next_x][next_y] && map[next_x][next_y]){
                visited[next_x][next_y] = true;
                DFS(next_x, next_y);
            }
        }
    }
}