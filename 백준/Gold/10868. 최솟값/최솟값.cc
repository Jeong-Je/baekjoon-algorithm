// 최솟값 10868 (https://www.acmicpc.net/problem/10868)
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

static vector<long> tree;

void setTree(int i);
long getMin(int s, int e);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    
    cin >> N >> M;
    
    int length = N;
    int treeHeight = 0;
    
    while(length != 0) {
        length /= 2;
        treeHeight++;
    }
    
    int treeSize = pow(2, treeHeight+1);
    int leftStartIndex = treeSize /2 - 1;
    
    tree.resize(treeSize+1);
    fill(tree.begin(), tree.end(), LONG_MAX);
    
    for(int i=leftStartIndex+1;i<=leftStartIndex+N;i++){
        cin >> tree[i];
    }
    
    setTree(treeSize-1);
    
    
    for(int i=0;i<M;i++){
        int s, e;
        cin >> s >> e;
        cout << getMin(leftStartIndex + s, leftStartIndex + e) << "\n";
    }
}

long getMin(int s, int e) {
    long answer = LONG_MAX;
    while(s<=e) {
        if(s % 2 == 1) {
            answer = answer > tree[s] ? tree[s] : answer;
            s++;
        }
        if(e % 2 == 0) {
            answer = answer > tree[e] ? tree[e] : answer;
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return answer;
}

void setTree(int i) {
    while(i != 1) {
        if(tree[i/2] > tree[i]) {
            tree[i/2] = tree[i];
        }
        i--;
    }
}
