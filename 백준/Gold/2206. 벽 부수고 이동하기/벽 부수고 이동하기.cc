#include<iostream>
#include<queue>
#include<string>
#include<tuple>

using namespace std;

// 맵
int arr[1001][1001] = { 0, };
// 이동비용
int wall_cost[1001][1001] = { 0, };
int cost[1001][1001] = { 0, };
//방문
bool wall_visited[1001][1001] = { false, };
bool visited[1001][1001] = { false , };

int main(void) {
    int n; int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    typedef tuple<int, int, int> node;
    queue<node >q;
    q.push({ 0, 0, 0 });

    visited[0][0] = true;
    wall_visited[0][0] = true;

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        int currY, currX, currWall;
        tie(currWall, currY, currX) = q.front();

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

            // 벽이 아니라면 
            if (arr[nextY][nextX] == 0) {
                if (currWall == 1 && !wall_visited[nextY][nextX]) {

                    wall_visited[nextY][nextX] = true;
                    q.push({ 1, nextY, nextX });
                    wall_cost[nextY][nextX] = wall_cost[currY][currX] + 1;
                }
                else if (currWall == 0 && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    q.push({ 0, nextY, nextX });
                    cost[nextY][nextX] = cost[currY][currX] + 1;
                }
            }
            // 벽이라면
            else {
                if (currWall == 0 && !wall_visited[nextY][nextX]) {
                    wall_visited[nextY][nextX] = true;
                    wall_cost[nextY][nextX] = cost[currY][currX] + 1;
                    q.push({ 1, nextY, nextX });
                }
            }
        }
    }

    if (!visited[n - 1][m - 1] && !wall_visited[n - 1][m - 1]) {
        cout << -1;
    }
    else {
        if (cost[n - 1][m - 1] && !wall_cost[n - 1][m - 1]) {
            cout << cost[n - 1][m - 1] + 1 << "\n";
        }
        else if (wall_cost[n - 1][m - 1] && !cost[n - 1][m - 1]) {
            cout << wall_cost[n - 1][m - 1] + 1 << "\n";
        }
        else {
            int mins = min(cost[n - 1][m - 1], wall_cost[n - 1][m - 1]);
            cout << mins + 1 << "\n";
        }
    }

    // test
    //     cout<<"wall_cost" << endl;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << wall_cost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout<<"cost" << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}