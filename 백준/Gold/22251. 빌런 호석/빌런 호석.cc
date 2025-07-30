#include <iostream>
#include <string>

using namespace std;

int N,K,P,X, ans = 0;
int num[10][9] = {
    {1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int getDiff(int x, int y);
int getDiffOne(int a,int b);

int main() {
    cin >> N >> K >> P >> X;
    
    for(int i=1;i<=N;i++) {
        if(i == X) continue;
        if(getDiff(i, X) <= P) ans++;
    }
    
    
    cout << ans;
}


int getDiff(int x, int y) {
    int ret = 0;
    for(int i =0;i<K;i++){
        ret += getDiffOne(x % 10, y % 10);
        x /= 10;
        y /= 10;
    }
    return ret;
}

int getDiffOne(int a,int b) {
    int cnt = 0;
    for(int i=0;i<7;i++){
        if(num[a][i] != num[b][i]) cnt ++;
    }
    return cnt;
}