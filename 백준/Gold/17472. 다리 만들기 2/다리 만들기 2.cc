// 17472 다리 만들기2 (https://www.acmicpc.net/problem/17472)
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

static int map[11][11];
static int visited[11][11];

static vector<pair<int, int>> mlist;
static vector<vector<pair<int, int>>> sumlist;

static vector<int> parent;

typedef tuple<int, int, int> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;

void BFS(int x, int y, int count);
void munion(int x, int y);
int find(int x);

int main(){
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
    
    int count = 1;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(map[i][j] && !visited[i][j]) {
                BFS(i, j, count);
                count++;
                sumlist.push_back(mlist);
            }
        }
    }
    

    for(int i=0;i<sumlist.size();i++){
        vector<pair<int, int>> now = sumlist[i];
        
        for(int j=0;j<now.size();j++){
            int x = now[j].first;
            int y= now[j].second;
            int now_S = visited[x][y];
            
            for(int d=0;d<4;d++){
                int next_x = x + dx[d];
                int next_y = y + dy[d];
                int blength = 0;
                
                while(next_x > 0 && next_x <= N && next_y > 0 && next_y <=M) {
                    if(visited[next_x][next_y] == now_S) { // 같은 섬이면 다리를 놓치 않음
                        break;
                    }
                    else if(visited[next_x][next_y] != 0) { // 다른 섬 도착
                        if(blength > 1) {
                            pq.push({blength, now_S, visited[next_x][next_y]});
                        }
                        break;
                    } else { // 바다임
                        blength++;
                    }
                    
                    if(dx[d] < 0) {
                         next_x--;
                    } else if(dx[d] > 0) {
                        next_x++;
                    } else if (dy[d] < 0) {
                        next_y--;
                    } else if (dy[d] > 0) {
                        next_y++;
                    }
                }
            }
        }
    }
    parent.resize(count+1);
    
    for(int i=1;i<=parent.size()-1;i++){
        parent[i] = i;
    }
    
    int useEdge = 0;
    int result = 0;
    
    while(!pq.empty()){
        Edge now = pq.top();
        pq.pop();
        
        int now_w = get<0>(now);
        int now_s = get<1>(now);
        int now_e = get<2>(now);
        
        if(find(now_s) != find(now_e)){
            munion(now_s, now_e);
            result += now_w;
            useEdge++;
        }
    }
    
    if(useEdge == count-2) {
        cout << result << "\n";
    } else {
        cout << "-1\n";
    }
}


void BFS(int x, int y, int count) {
    visited[x][y] = count;

    mlist.clear();

    mlist.push_back({x, y});

    queue<pair<int, int>> que;
    que.push({x, y});

    while(!que.empty()){
        pair<int, int> now;
        now = que.front();
        que.pop();
        
        int x = now.first;
        int y = now.second;
        
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x > 0 && next_x <= N && next_y > 0 && next_y <= M) {
                if(map[next_x][next_y] && !visited[next_x][next_y]) {
                    visited[next_x][next_y] = count;
                    que.push({next_x, next_y});
                    mlist.push_back({next_x, next_y});
                }
            }
        }
    }

}

void munion(int x, int y) {
    x = find(x);
    y = find(y);
    if(x!=y){
        parent[y] = x;
    }
}
int find(int x) {
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}