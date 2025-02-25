// 11505 구간 곱 구하기 (https://www.acmicpc.net/problem/11505)
#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

static vector<long> tree;

void setTree(int i);
void changeVal(int i, long val);
long getMul(int s, int e);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int length = N;
    int treeHeight = 0;

    while (length != 0) {
        length /= 2;
        treeHeight++;
    }

    int treeSize = pow(2, treeHeight + 1);
    int leftStartIndex = treeSize / 2 - 1;

    tree.resize(treeSize + 1);
    fill(tree.begin(), tree.end(), 1);

    for (int i = leftStartIndex + 1; i <= leftStartIndex + N; i++) {
        cin >> tree[i];
    }


    setTree(treeSize - 1);

    for (int i = 0; i < M + K; i++) {
        long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {  // 값 교체
            changeVal(leftStartIndex + b, c);
        }
        else { // 구간 곱 출력
            cout << getMul(leftStartIndex + b, leftStartIndex + c) << "\n";
        }

    }
}

void changeVal(int i, long val) {
    tree[i] = val;
    i /= 2;
    while (i >= 1) {
        tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
        i /= 2;
    }
}


long getMul(int s, int e) {
    long partMul = 1;
    while (s <= e) {
        if (s % 2 == 1) {
            partMul = (partMul * tree[s]) % MOD;
            s++;
        }
        if (e % 2 == 0) {
            partMul = (partMul * tree[e]) % MOD;
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return partMul;
}


void setTree(int i) {
    while (i != 1) {
        tree[i / 2] = tree[i/2] * tree[i] % MOD;
        i--;
    }
}