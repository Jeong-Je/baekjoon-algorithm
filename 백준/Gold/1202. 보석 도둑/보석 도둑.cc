#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewel(N); // {무게, 가격}
    vector<int> bag(K);

    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewel[i] = {m, v};
    }

    for (int i = 0; i < K; i++) {
        cin >> bag[i];
    }

    // 정렬: 보석 무게 오름차순, 가방 용량 오름차순
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    long long ans = 0;
    int idx = 0;

    for (int i = 0; i < K; i++) {
        // 현재 가방에 담을 수 있는 모든 보석 pq에 넣기
        while (idx < N && jewel[idx].first <= bag[i]) {
            pq.push(jewel[idx].second); // 가격 기준 max-heap
            idx++;
        }

        // 가장 비싼 보석 하나만 담기
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}
