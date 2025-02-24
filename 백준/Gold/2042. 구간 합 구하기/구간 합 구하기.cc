// 2042 구간 합 구하기 (https://www.acmicpc.net/problem/2042)
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;

void changeNode(int index, long val);
void setTree(int i);
long getSum(int s, int e);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    
    int treeHeight = 0;
    int index = N;
    
    while(index != 0){
        index /= 2;
        treeHeight++;
    }
    
    int treeSize = pow(2, treeHeight + 1);
    
    tree.resize(treeSize+1);
    
    int leftStartIndex = treeSize / 2;
    
    
    for(int i=leftStartIndex;i<leftStartIndex+N;i++){
        cin >> tree[i];
    }

    setTree(treeSize-1); // 트리의 구간 합 초기화

    for(int i=0;i<M+K;i++){
        long a, s, e;
        cin >> a >> s >> e;
        
        if(a==1) { // 값 교체
            changeNode(leftStartIndex+s-1, e);

        } else { // 구간 합 출력
            s += leftStartIndex-1;
            e += leftStartIndex-1;
            cout << getSum(s, e) << "\n";
        }
    }
}

long getSum(int s, int e) {
    long partSum = 0;
    while(s<=e){
        if(s % 2 == 1) {
            partSum += tree[s];
            s++;
        }
        if(e % 2 == 0) {
            partSum += tree[e];
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return partSum;
}

void setTree(int i){
    while(i != 1){
        tree[i/2] += tree[i];
        i--;
    }
}

void changeNode(int index, long val){
    long diff = val - tree[index];
    
    while(index) {
        tree[index] += diff;
        index /= 2;
    }
}