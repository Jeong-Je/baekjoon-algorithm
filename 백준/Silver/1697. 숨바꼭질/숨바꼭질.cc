#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, K;

static bool visited[100001];
static int dx[2] = {-1, 1};

void BFS(int x);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    if(N==K){
        cout << "0";
        return 0;
    }
    
    BFS(N);
}

void BFS(int x) {
    visited[x] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, 1));
    while(!q.empty()){

        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=0;i<3;i++){
            int next_x;
            if(i==2){
                next_x = now * 2;
            }else {
                next_x = now + dx[i];
            }
            if(next_x > -1 && next_x < 100001 && !visited[next_x]){
                q.push(make_pair(next_x, cnt +1));
                visited[next_x] = true;
                if(next_x == K) {
                    cout << cnt;
                    return;
                }
            }
        }
    }
}