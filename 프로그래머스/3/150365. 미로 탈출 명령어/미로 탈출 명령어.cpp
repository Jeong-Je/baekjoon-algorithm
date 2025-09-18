#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int nn, mm, xx, yy, rr, cc, kk;
int di[4] = {1, 0, 0, -1};
int dj[4] = {0, -1, 1, 0};
char way[4] = {'d', 'l', 'r', 'u'};

string answer = "";

void backtracking(int i, int j, string s) {
    if(s.length() == kk) {
        if(i == rr && j == cc) {
            if(answer.empty()) answer = s;
        }
        return;
    }

    int remain = kk - s.length();
    int dist = abs(i - rr) + abs(j - cc);

    if(dist > remain) return;
    if((remain - dist) % 2 != 0) return;

    for(int d=0; d<4; d++) {
        int next_i = i + di[d];
        int next_j = j + dj[d];
        if(next_i <= 0 || next_i > nn || next_j <= 0 || next_j > mm) continue;

        backtracking(next_i, next_j, s + way[d]);
        
        if(!answer.empty()) return; // 사전순으로 처음 찾은 해답이면 바로 종료
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    nn = n; mm = m; xx = x; yy = y; rr = r; cc = c; kk = k;

    backtracking(x, y, "");
    if(answer.empty()) return "impossible";
    return answer;
}
